package com.gowengamedev.insectoiddefense;

import android.app.Activity;
import android.opengl.GLSurfaceView.Renderer;
import android.os.SystemClock;
import android.util.Log;
import android.widget.Toast;

import com.gowengamedev.insectoiddefense.platform.PlatformAssetUtils;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

public final class GameRenderer implements Renderer
{
    // Definitions from src/core/game/ResourceConstants.h
    private static final short MUSIC_STOP = 1;
    private static final short MUSIC_PLAY_MAP_SPACE = 2;
    private static final short SOUND_ELECTRIC_BOLT = 1;
    private static final short SOUND_MISSILE_LAUNCH = 2;
    private static final short SOUND_PLASMA_BANG = 3;
    private static final short SOUND_FIRE_BOLT = 4;
    private static final short SOUND_EXPLOSION = 5;
    private static final short SOUND_LAZER_BEAM = 6;
    private static final short SOUND_ACID_DROP = 7;
    private static final short SOUND_TOWER_UPGRADED = 8;
    private static final short SOUND_DRAG_TOWER = 9;
    private static final short SOUND_ICE_BLAST = 10;
    private static final short SOUND_TOXIC_CLOUD = 11;
    private static final short SOUND_CREEP_DEATH = 12;
    private static final short SOUND_GOAL_HIT = 13;
    private static final short SOUND_PLACE_TOWER = 14;
    private static final short SOUND_BEGIN_WAVE = 15;
    private static final short SOUND_SELL_TOWER = 16;

    // Definitions from src/core/game/ScreenState.h
    private static final short SCREEN_STATE_NORMAL = 0;
    private static final short SCREEN_STATE_WAVE_COMPLETED = 1;
    private static final short SCREEN_STATE_GAME_OVER = 2;
    private static final short SCREEN_STATE_EXIT = 3;

    // Definitions from src/core/game/DifficultyLevel.h
    private static final short DIFFICULTY_LEVEL_EASY = 0;
    private static final short DIFFICULTY_LEVEL_NORMAL = 1;
    private static final short DIFFICULTY_LEVEL_HARD = 2;

    // #frames involved in average calc (suggested values 5-100)
    private static final float movAveragePeriod = 40;

    // adjusting ratio (suggested values 0.01-0.5)
    private static final float smoothFactor = 0.1f;

    static
    {
        System.loadLibrary("game");
    }

    private final Activity activity;
    private final int deviceScreenWidth;
    private final int deviceScreenHeight;
    private final Audio audio;

    private Music bgm;
    private Sound acidDropSound;
    private Sound beginWaveSound;
    private Sound creepDeathSound;
    private Sound dragTowerSound;
    private Sound electricBoltSound;
    private Sound explosionSound;
    private Sound fireBoltSound;
    private Sound goalHitSound;
    private Sound iceBlastSound;
    private Sound lazerBeamSound;
    private Sound missileLaunchSound;
    private Sound placeTowerSound;
    private Sound plasmaBangSound;
    private Sound sellTowerSound;
    private Sound towerUpgradedSound;
    private Sound toxicCloudSound;

    private float smoothedDeltaRealTime_ms = 17.5f;
    private float movAverageDeltaTime_ms = smoothedDeltaRealTime_ms;
    private long lastRealTimeMeasurement_ms;
    private boolean isInitialized;
    private boolean _isMinimumWaveRequirementMet;

    public GameRenderer(Activity activity, int deviceScreenWidth, int deviceScreenHeight, int levelIndex, int difficulty)
    {
        this.activity = activity;
        this.deviceScreenWidth = deviceScreenWidth;
        this.deviceScreenHeight = deviceScreenHeight;
        this.audio = new Audio(activity.getAssets());

        this.beginWaveSound = audio.newSound("begin_wave.ogg");
        this.dragTowerSound = audio.newSound("drag_tower.ogg");
        this.placeTowerSound = audio.newSound("place_tower.ogg");
        this.sellTowerSound = audio.newSound("sell_tower.ogg");
        this.towerUpgradedSound = audio.newSound("tower_upgraded.ogg");
        this.creepDeathSound = audio.newSound("creep_death.ogg");
        this.lazerBeamSound = audio.newSound("lazer_beam.ogg");
        this.missileLaunchSound = audio.newSound("missile_launch.ogg");
        this.explosionSound = audio.newSound("explosion.ogg");
        this.iceBlastSound = audio.newSound("ice_blast.ogg");
        this.electricBoltSound = audio.newSound("electric_bolt.ogg");
        this.plasmaBangSound = audio.newSound("plasma_bang.ogg");
        this.fireBoltSound = audio.newSound("fire_bolt.ogg");
        this.acidDropSound = audio.newSound("acid_drop.ogg");
        this.toxicCloudSound = audio.newSound("toxic_cloud.ogg");
        this.goalHitSound = audio.newSound("goal_hit.ogg");

        this.isInitialized = false;
        this._isMinimumWaveRequirementMet = SaveData.getHighWaveForDifficultyLevelAndLevelIndex(difficulty, levelIndex) >= LevelWaveRequirementMapper.getWaveRequirementForLevelIndex(levelIndex);

        init(levelIndex, difficulty);
    }

    @Override
    public void onSurfaceCreated(GL10 gl, EGLConfig config)
    {
        Log.d("GameRenderer", "GL Surface created!");

        if (!isInitialized)
        {
            PlatformAssetUtils.init_asset_manager(activity.getAssets());
            isInitialized = true;
        }

        on_surface_created(deviceScreenWidth, deviceScreenHeight);
    }

    @Override
    public void onSurfaceChanged(GL10 gl, int width, int height)
    {
        Log.d("GameRenderer", "GL Surface changed!");

        on_surface_changed(width, height, width, height);
        on_resume();
    }

    @Override
    public void onDrawFrame(GL10 gl)
    {
        int gameState = get_state();
        switch (gameState)
        {
            case SCREEN_STATE_WAVE_COMPLETED:
                onWaveCompleted();
                clear_state();
            case SCREEN_STATE_NORMAL:
                update(smoothedDeltaRealTime_ms / 1000);
                break;
            case SCREEN_STATE_GAME_OVER:
                saveScore();
                clear_state();
                break;
            case SCREEN_STATE_EXIT:
                activity.finish();
                break;
            default:
                break;
        }

        render();
        handleSound();
        handleMusic();

        // Moving average calc
        long currTimePick_ms = SystemClock.uptimeMillis();
        float realTimeElapsed_ms;
        if (lastRealTimeMeasurement_ms > 0)
        {
            realTimeElapsed_ms = (currTimePick_ms - lastRealTimeMeasurement_ms);
        }
        else
        {
            realTimeElapsed_ms = smoothedDeltaRealTime_ms; // just the first
            // time
        }

        movAverageDeltaTime_ms = (realTimeElapsed_ms + movAverageDeltaTime_ms * (movAveragePeriod - 1)) / movAveragePeriod;

        // Calc a better aproximation for smooth stepTime
        smoothedDeltaRealTime_ms = smoothedDeltaRealTime_ms + (movAverageDeltaTime_ms - smoothedDeltaRealTime_ms) * smoothFactor;

        lastRealTimeMeasurement_ms = currTimePick_ms;
    }

    public void onResume()
    {
        on_resume();
    }

    public void onPause()
    {
        if (bgm != null)
        {
            bgm.stop();
        }

        on_pause();

        saveScore();
    }

    public void handleTouchDown(float rawX, float rawY)
    {
        on_touch_down(rawX, rawY);
    }

    public void handleTouchDragged(float rawX, float rawY)
    {
        on_touch_dragged(rawX, rawY);
    }

    public void handleTouchUp(float rawX, float rawY)
    {
        on_touch_up(rawX, rawY);
    }

    public boolean handleOnBackPressed()
    {
        return handle_on_back_pressed();
    }

    private void handleSound()
    {
        short soundId;
        while ((soundId = get_current_sound_id()) > 0)
        {
            switch (soundId)
            {
                case SOUND_ACID_DROP:
                    this.acidDropSound.play(1);
                    break;
                case SOUND_BEGIN_WAVE:
                    this.beginWaveSound.play(1);
                    break;
                case SOUND_CREEP_DEATH:
                    this.creepDeathSound.play(1);
                    break;
                case SOUND_DRAG_TOWER:
                    this.dragTowerSound.play(1);
                    break;
                case SOUND_ELECTRIC_BOLT:
                    this.electricBoltSound.play(1);
                    break;
                case SOUND_EXPLOSION:
                    this.explosionSound.play(1);
                    break;
                case SOUND_FIRE_BOLT:
                    this.fireBoltSound.play(1);
                    break;
                case SOUND_GOAL_HIT:
                    this.goalHitSound.play(1);
                    break;
                case SOUND_ICE_BLAST:
                    this.iceBlastSound.play(1);
                    break;
                case SOUND_LAZER_BEAM:
                    this.lazerBeamSound.play(1);
                    break;
                case SOUND_MISSILE_LAUNCH:
                    this.missileLaunchSound.play(1);
                    break;
                case SOUND_PLACE_TOWER:
                    this.placeTowerSound.play(1);
                    break;
                case SOUND_PLASMA_BANG:
                    this.plasmaBangSound.play(1);
                    break;
                case SOUND_SELL_TOWER:
                    this.sellTowerSound.play(1);
                    break;
                case SOUND_TOWER_UPGRADED:
                    this.towerUpgradedSound.play(1);
                    break;
                case SOUND_TOXIC_CLOUD:
                    this.toxicCloudSound.play(1);
                    break;
                default:
                    continue;
            }
        }
    }

    private void handleMusic()
    {
        short musicId = get_current_music_id();
        switch (musicId)
        {
            case MUSIC_STOP:
                if (bgm != null)
                {
                    bgm.stop();
                }
                break;
            case MUSIC_PLAY_MAP_SPACE:
                loadAndPlayMusic("bgm.ogg");
                break;
            default:
                break;
        }
    }

    private void onWaveCompleted()
    {
        int wave = get_wave();
        int levelIndex = get_level_index();

        if (!_isMinimumWaveRequirementMet && wave >= LevelWaveRequirementMapper.getWaveRequirementForLevelIndex(levelIndex))
        {
            _isMinimumWaveRequirementMet = true;

            int levelUnlockedMessageStringId = LevelWaveRequirementMapper.getLevelUnlockedAchievementToastStringResourceForLevelIndex(levelIndex);
            final String levelUnlockedMessage = activity.getString(levelUnlockedMessageStringId);

            activity.runOnUiThread(new Runnable()
            {
                public void run()
                {
                    Toast.makeText(activity, levelUnlockedMessage, Toast.LENGTH_SHORT).show();
                }
            });
        }
    }

    private void saveScore()
    {
        int score = get_score();
        int wave = get_wave();
        int difficulty = get_difficulty();
        int levelIndex = get_level_index();

        SaveData.saveHighScoreForLevel(score, wave, levelIndex, difficulty);
    }

    private void loadAndPlayMusic(String fileName)
    {
        if (bgm != null && bgm.isPlaying())
        {
            bgm.dispose();
            bgm = null;
        }

        bgm = audio.newMusic(fileName);
        bgm.setLooping(true);
        bgm.play();
    }

    private static native void init(int levelIndex, int difficulty);

    private static native void on_surface_created(int pixelWidth, int pixelHeight);

    private static native void on_surface_changed(int pixelWidth, int pixelHeight, int dpWidth, int dpHeight);

    private static native void on_resume();

    private static native void on_pause();

    private static native void update(float deltaTime);

    private static native void render();

    private static native void on_touch_down(float normalized_x, float normalized_y);

    private static native void on_touch_dragged(float normalized_x, float normalized_y);

    private static native void on_touch_up(float normalized_x, float normalized_y);

    private static native short get_current_music_id();

    private static native short get_current_sound_id();

    private static native int get_state();

    private static native void clear_state();

    private static native int get_level_index();

    private static native int get_difficulty();

    private static native int get_wave();

    private static native int get_score();

    private static native boolean is_at_max_health();

    private static native boolean handle_on_back_pressed();
}