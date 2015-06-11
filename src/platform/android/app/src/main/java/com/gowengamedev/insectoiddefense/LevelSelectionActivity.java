package com.gowengamedev.insectoiddefense;

import android.app.Activity;
import android.content.Intent;
import android.graphics.Color;
import android.os.Bundle;
import android.support.v4.app.FragmentActivity;
import android.support.v4.app.FragmentStatePagerAdapter;
import android.support.v4.view.ViewPager;
import android.support.v4.view.ViewPager.OnPageChangeListener;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;
import android.widget.AdapterView;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.Button;
import android.widget.TextView;

import com.gowengamedev.insectoiddefense.R;

public final class LevelSelectionActivity extends FragmentActivity
{
    public static void startActivity(Activity activity)
    {
        Intent i = new Intent(activity, LevelSelectionActivity.class);
        activity.startActivity(i);
    }

    private Music backgroundMusic;
    private int[] shipLevelDrawableResources;
    private int levelIndex;
    private OnItemClickListener levelOnItemClickListener;
    private LevelsListFragment currentLevelsListFragment;

    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        getWindow().clearFlags(WindowManager.LayoutParams.FLAG_FORCE_NOT_FULLSCREEN);

        setContentView(R.layout.activity_level_selection);

        this.shipLevelDrawableResources = new int[11];
        this.shipLevelDrawableResources[0] = R.drawable.ship_level_1;
        this.shipLevelDrawableResources[1] = R.drawable.ship_level_2;
        this.shipLevelDrawableResources[2] = R.drawable.ship_level_3;
        this.shipLevelDrawableResources[3] = R.drawable.ship_level_4;
        this.shipLevelDrawableResources[4] = R.drawable.ship_level_5;
        this.shipLevelDrawableResources[5] = R.drawable.ship_level_6;
        this.shipLevelDrawableResources[6] = R.drawable.ship_level_7;
        this.shipLevelDrawableResources[7] = R.drawable.ship_level_8;
        this.shipLevelDrawableResources[8] = R.drawable.ship_level_9;
        this.shipLevelDrawableResources[9] = R.drawable.ship_level_10;
        this.shipLevelDrawableResources[10] = R.drawable.ship_default;

        levelOnItemClickListener = new LevelOnItemClickListener();
        findViewPager().setAdapter(new MyFragmentStatePagerAdapter(getSupportFragmentManager()));
        findViewPager().setOnPageChangeListener(new MyOnPageChangeListener());
        findViewPager().setCurrentItem(1);

        ViewUtils.setAstrolytTypeFaceForViewGroup((ViewGroup) findViewById(R.id.level_selection_container));

        Audio audio = new Audio(getAssets());
        this.backgroundMusic = audio.newMusic("level_selection_bgm.ogg");
        this.backgroundMusic.setLooping(true);
        this.backgroundMusic.setVolume(1.0f);
    }

    @Override
    protected void onResume()
    {
        super.onResume();
        backgroundMusic.play();

        if (currentLevelsListFragment != null)
        {
            currentLevelsListFragment.refresh();
        }
    }

    @Override
    protected void onPause()
    {
        if (isFinishing())
        {
            backgroundMusic.dispose();
            backgroundMusic = null;
        }
        else
        {
            backgroundMusic.pause();
        }

        super.onPause();
    }

    public void startOnClick(View view)
    {
        GameActivity.startActivity(this, levelIndex, findViewPager().getCurrentItem());
    }

    private void clickLevelAtPosition(int position)
    {
        if (position == 0 || SaveData.getHighWaveForDifficultyLevelAndLevelIndex(findViewPager().getCurrentItem(), (position - 1)) >= LevelWaveRequirementMapper.getWaveRequirementForLevelIndex((position - 1)))
        {
            findLevelDescriptionTextView().setText(getResources().getStringArray(R.array.level_descriptions)[position]);
            findStartButton().setVisibility(View.VISIBLE);
        }
        else
        {
            findLevelDescriptionTextView().setText(LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(position));
            findStartButton().setVisibility(View.INVISIBLE);
        }
    }

    private void pageChanged()
    {
        findLevelDescriptionTextView().setVisibility(View.INVISIBLE);
        findStartButton().setVisibility(View.INVISIBLE);
        findShipImageView().setImageResource(shipLevelDrawableResources[10]);
    }

    private TextView findLevelDescriptionTextView()
    {
        return (TextView) findViewById(R.id.level_description_textview);
    }

    private Button findStartButton()
    {
        return (Button) findViewById(R.id.level_selection_start_button);
    }

    private ViewPager findViewPager()
    {
        return (ViewPager) findViewById(R.id.level_selection_view_pager);
    }

    private AspectRatioImageView findShipImageView()
    {
        return (AspectRatioImageView) findViewById(R.id.shipview);
    }

    private final class MyFragmentStatePagerAdapter extends FragmentStatePagerAdapter
    {
        public MyFragmentStatePagerAdapter(android.support.v4.app.FragmentManager fm)
        {
            super(fm);
        }

        @Override
        public android.support.v4.app.Fragment getItem(int position)
        {
            currentLevelsListFragment = LevelsListFragment.createInstance(position, levelOnItemClickListener);
            return currentLevelsListFragment;
        }

        @Override
        public String getPageTitle(int position)
        {
            switch (position)
            {
                case 0:
                    return getString(R.string.easy_radio_button);
                case 1:
                    return getString(R.string.normal_radio_button);
                case 2:
                    return getString(R.string.hard_radio_button);
                default:
                    throw new IllegalArgumentException("Position Number # " + position + " is not valid!");
            }
        }

        @Override
        public int getCount()
        {
            return 3;
        }
    }

    private final class LevelOnItemClickListener implements OnItemClickListener
    {
        @Override
        public void onItemClick(AdapterView<?> parent, View view, int position, long id)
        {
            levelIndex = position;

            ViewUtils.resetListViewSelection(parent);

            TextView nameTextView = (TextView) view.findViewById(R.id.level_name_textview);
            nameTextView.setTextColor(Color.GREEN);
            TextView statsTextView = (TextView) view.findViewById(R.id.level_stats_textview);
            statsTextView.setTextColor(Color.GREEN);

            findShipImageView().setImageResource(shipLevelDrawableResources[position]);
            findLevelDescriptionTextView().setVisibility(View.VISIBLE);

            clickLevelAtPosition(position);
        }
    }

    private final class MyOnPageChangeListener implements OnPageChangeListener
    {
        @Override
        public void onPageScrollStateChanged(int arg0)
        {
            // Not Needed
        }

        @Override
        public void onPageScrolled(int arg0, float arg1, int arg2)
        {
            // Not Needed
        }

        @Override
        public void onPageSelected(int arg0)
        {
            pageChanged();
        }
    }
}