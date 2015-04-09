package com.gowengamedev.insectoiddefense;

import android.annotation.SuppressLint;
import android.content.Context;
import android.os.Build;
import android.os.Build.VERSION;
import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.view.animation.AlphaAnimation;
import android.widget.AdapterView.OnItemClickListener;
import android.widget.ListView;

import com.gowengamedev.insectoiddefense.R;

public final class LevelsListFragment extends Fragment
{
    public static LevelsListFragment createInstance(int difficultyLevel, OnItemClickListener onItemClickListener)
    {
        LevelsListFragment fragment = new LevelsListFragment();
        Bundle args = new Bundle();
        args.putSerializable(LevelsListFragment.ARG_DIFFICULTY_LEVEL, difficultyLevel);
        fragment.setArguments(args);

        levelOnItemClickListener = onItemClickListener;

        return fragment;
    }

    private static final String ARG_DIFFICULTY_LEVEL = "arg_difficulty_level";
    private static OnItemClickListener levelOnItemClickListener;

    private ListView listView;

    @SuppressLint("NewApi")
    @Override
    public View onCreateView(LayoutInflater inflater, ViewGroup container, Bundle savedInstanceState)
    {
        listView = (ListView) inflater.inflate(R.layout.listview_level_selection, container, false);

        if (VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB)
        {
            listView.setAlpha(0.60f);
        }
        else
        {
            AlphaAnimation aa = new AlphaAnimation(1, 0.60f);
            aa.setDuration(1);
            aa.setFillAfter(true);
            listView.startAnimation(aa);
        }

        listView.setAdapter(getLevelsArrayAdapter(getArguments().getInt(ARG_DIFFICULTY_LEVEL), listView.getContext()));
        listView.setOnItemClickListener(levelOnItemClickListener);

        return listView;
    }

    @Override
    public void setUserVisibleHint(boolean isVisibleToUser)
    {
        super.setUserVisibleHint(isVisibleToUser);

        if (listView != null)
        {
            ViewUtils.resetListViewSelection(listView);
        }
    }

    public void refresh()
    {
        listView.invalidateViews();
    }

    private LevelsArrayAdapter getLevelsArrayAdapter(int dl, Context context)
    {
        return new LevelsArrayAdapter(dl, context, R.layout.listview_item_level, R.id.level_name_textview, getResources().getStringArray(R.array.level_names));
    }
}