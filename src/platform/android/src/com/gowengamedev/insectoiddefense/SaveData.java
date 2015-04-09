package com.gowengamedev.insectoiddefense;

import static com.gowengamedev.insectoiddefense.DifficultyLevel.DIFFICULTY_LEVEL_EASY;
import static com.gowengamedev.insectoiddefense.DifficultyLevel.DIFFICULTY_LEVEL_HARD;
import static com.gowengamedev.insectoiddefense.DifficultyLevel.DIFFICULTY_LEVEL_NORMAL;

public final class SaveData
{
    private static final String[] HIGH_SCORES_EASY;
    private static final String[] HIGH_SCORES_NORMAL;
    private static final String[] HIGH_SCORES_HARD;

    private static final String[] HIGH_WAVES_EASY;
    private static final String[] HIGH_WAVES_NORMAL;
    private static final String[] HIGH_WAVES_HARD;

    private static final String[] LEVEL_REQUIRES_TUTORIAL;

    static
    {
        HIGH_SCORES_EASY = new String[10];

        HIGH_SCORES_EASY[0] = "high_score_level_one_easy";
        HIGH_SCORES_EASY[1] = "high_score_level_two_easy";
        HIGH_SCORES_EASY[2] = "high_score_level_three_easy";
        HIGH_SCORES_EASY[3] = "high_score_level_four_easy";
        HIGH_SCORES_EASY[4] = "high_score_level_five_easy";
        HIGH_SCORES_EASY[5] = "high_score_level_six_easy";
        HIGH_SCORES_EASY[6] = "high_score_level_seven_easy";
        HIGH_SCORES_EASY[7] = "high_score_level_eight_easy";
        HIGH_SCORES_EASY[8] = "high_score_level_nine_easy";
        HIGH_SCORES_EASY[9] = "high_score_level_ten_easy";

        HIGH_SCORES_NORMAL = new String[10];

        HIGH_SCORES_NORMAL[0] = "high_score_level_one_normal";
        HIGH_SCORES_NORMAL[1] = "high_score_level_two_normal";
        HIGH_SCORES_NORMAL[2] = "high_score_level_three_normal";
        HIGH_SCORES_NORMAL[3] = "high_score_level_four_normal";
        HIGH_SCORES_NORMAL[4] = "high_score_level_five_normal";
        HIGH_SCORES_NORMAL[5] = "high_score_level_six_normal";
        HIGH_SCORES_NORMAL[6] = "high_score_level_seven_normal";
        HIGH_SCORES_NORMAL[7] = "high_score_level_eight_normal";
        HIGH_SCORES_NORMAL[8] = "high_score_level_nine_normal";
        HIGH_SCORES_NORMAL[9] = "high_score_level_ten_normal";

        HIGH_SCORES_HARD = new String[10];

        HIGH_SCORES_HARD[0] = "high_score_level_one_hard";
        HIGH_SCORES_HARD[1] = "high_score_level_two_hard";
        HIGH_SCORES_HARD[2] = "high_score_level_three_hard";
        HIGH_SCORES_HARD[3] = "high_score_level_four_hard";
        HIGH_SCORES_HARD[4] = "high_score_level_five_hard";
        HIGH_SCORES_HARD[5] = "high_score_level_six_hard";
        HIGH_SCORES_HARD[6] = "high_score_level_seven_hard";
        HIGH_SCORES_HARD[7] = "high_score_level_eight_hard";
        HIGH_SCORES_HARD[8] = "high_score_level_nine_hard";
        HIGH_SCORES_HARD[9] = "high_score_level_ten_hard";

        HIGH_WAVES_EASY = new String[10];

        HIGH_WAVES_EASY[0] = "high_wave_level_one_easy";
        HIGH_WAVES_EASY[1] = "high_wave_level_two_easy";
        HIGH_WAVES_EASY[2] = "high_wave_level_three_easy";
        HIGH_WAVES_EASY[3] = "high_wave_level_four_easy";
        HIGH_WAVES_EASY[4] = "high_wave_level_five_easy";
        HIGH_WAVES_EASY[5] = "high_wave_level_six_easy";
        HIGH_WAVES_EASY[6] = "high_wave_level_seven_easy";
        HIGH_WAVES_EASY[7] = "high_wave_level_eight_easy";
        HIGH_WAVES_EASY[8] = "high_wave_level_nine_easy";
        HIGH_WAVES_EASY[9] = "high_wave_level_ten_easy";

        HIGH_WAVES_NORMAL = new String[10];

        HIGH_WAVES_NORMAL[0] = "high_wave_level_one_normal";
        HIGH_WAVES_NORMAL[1] = "high_wave_level_two_normal";
        HIGH_WAVES_NORMAL[2] = "high_wave_level_three_normal";
        HIGH_WAVES_NORMAL[3] = "high_wave_level_four_normal";
        HIGH_WAVES_NORMAL[4] = "high_wave_level_five_normal";
        HIGH_WAVES_NORMAL[5] = "high_wave_level_six_normal";
        HIGH_WAVES_NORMAL[6] = "high_wave_level_seven_normal";
        HIGH_WAVES_NORMAL[7] = "high_wave_level_eight_normal";
        HIGH_WAVES_NORMAL[8] = "high_wave_level_nine_normal";
        HIGH_WAVES_NORMAL[9] = "high_wave_level_ten_normal";

        HIGH_WAVES_HARD = new String[10];

        HIGH_WAVES_HARD[0] = "high_wave_level_one_hard";
        HIGH_WAVES_HARD[1] = "high_wave_level_two_hard";
        HIGH_WAVES_HARD[2] = "high_wave_level_three_hard";
        HIGH_WAVES_HARD[3] = "high_wave_level_four_hard";
        HIGH_WAVES_HARD[4] = "high_wave_level_five_hard";
        HIGH_WAVES_HARD[5] = "high_wave_level_six_hard";
        HIGH_WAVES_HARD[6] = "high_wave_level_seven_hard";
        HIGH_WAVES_HARD[7] = "high_wave_level_eight_hard";
        HIGH_WAVES_HARD[8] = "high_wave_level_nine_hard";
        HIGH_WAVES_HARD[9] = "high_wave_level_ten_hard";

        LEVEL_REQUIRES_TUTORIAL = new String[10];

        LEVEL_REQUIRES_TUTORIAL[0] = "level_one_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[1] = "level_two_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[2] = "level_three_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[3] = "level_four_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[4] = "level_five_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[5] = "level_six_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[6] = "level_seven_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[7] = "level_eight_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[8] = "level_nine_requires_tutorial";
        LEVEL_REQUIRES_TUTORIAL[9] = "level_ten_requires_tutorial";
    }

    public static boolean doesLevelRequireTutorial(int levelIndex)
    {
        return AppPrefs.getInstance().getBoolean(LEVEL_REQUIRES_TUTORIAL[levelIndex], true);
    }

    public static void setTutorialViewedForLevel(int levelIndex)
    {
        AppPrefs.getInstance().set(LEVEL_REQUIRES_TUTORIAL[levelIndex], false);
    }

    public static int getHighScoreForDifficultyLevelAndLevelIndex(int dl, int levelIndex)
    {
        return AppPrefs.getInstance().getInt(getHighScoresKeysForDifficultyLevel(dl)[levelIndex], 0);
    }

    public static int getHighWaveForDifficultyLevelAndLevelIndex(int dl, int levelIndex)
    {
        return AppPrefs.getInstance().getInt(getHighWavesKeysForDifficultyLevel(dl)[levelIndex], 0);
    }

    public static void saveHighScoreForLevel(int highscore, int wave, int levelIndex, int difficulty)
    {
        int highestScore = getHighScoreForDifficultyLevelAndLevelIndex(difficulty, levelIndex);

        if (highscore > highestScore)
        {
            AppPrefs.getInstance().set(getHighScoresKeysForDifficultyLevel(difficulty)[levelIndex], highscore);
        }

        int highestWave = getHighWaveForDifficultyLevelAndLevelIndex(difficulty, levelIndex);

        if (wave > highestWave)
        {
            AppPrefs.getInstance().set(getHighWavesKeysForDifficultyLevel(difficulty)[levelIndex], wave);
        }
    }

    private static String[] getHighScoresKeysForDifficultyLevel(int difficultyLevel)
    {
        switch (difficultyLevel)
        {
            case DIFFICULTY_LEVEL_EASY:
                return HIGH_SCORES_EASY;
            case DIFFICULTY_LEVEL_NORMAL:
                return HIGH_SCORES_NORMAL;
            case DIFFICULTY_LEVEL_HARD:
                return HIGH_SCORES_HARD;
            default:
                return null;
        }
    }

    private static String[] getHighWavesKeysForDifficultyLevel(int difficultyLevel)
    {
        switch (difficultyLevel)
        {
            case DIFFICULTY_LEVEL_EASY:
                return HIGH_WAVES_EASY;
            case DIFFICULTY_LEVEL_NORMAL:
                return HIGH_WAVES_NORMAL;
            case DIFFICULTY_LEVEL_HARD:
                return HIGH_WAVES_HARD;
            default:
                return null;
        }
    }
}