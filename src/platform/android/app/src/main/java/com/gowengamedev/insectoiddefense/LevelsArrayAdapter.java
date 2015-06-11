package com.gowengamedev.insectoiddefense;

import android.content.Context;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ArrayAdapter;
import android.widget.TextView;

import com.gowengamedev.insectoiddefense.R;

public final class LevelsArrayAdapter extends ArrayAdapter<String>
{
    private final int difficultyLevel;
    private final Context context;

    public LevelsArrayAdapter(int difficultyLevel, Context context, int resource, int textViewResourceId, String[] objects)
    {
        super(context, resource, textViewResourceId, objects);

        this.difficultyLevel = difficultyLevel;
        this.context = context;
    }

    @Override
    public View getView(int position, View convertView, ViewGroup parent)
    {
        View view = super.getView(position, convertView, parent);

        ViewUtils.setAstrolytTypeFaceForViewGroup((ViewGroup) view);
        TextView statsTextView = (TextView) view.findViewById(R.id.level_stats_textview);

        setTextForPosition(statsTextView, position);

        return view;
    }

    private void setTextForPosition(TextView textView, int position)
    {
        if (position == 0 || SaveData.getHighWaveForDifficultyLevelAndLevelIndex(difficultyLevel, (position - 1)) >= LevelWaveRequirementMapper.getWaveRequirementForLevelIndex((position - 1)))
        {
            int highScore = SaveData.getHighScoreForDifficultyLevelAndLevelIndex(difficultyLevel, position);
            int wave = SaveData.getHighWaveForDifficultyLevelAndLevelIndex(difficultyLevel, position);
            String statsText = String.format(context.getString(R.string.highscore_wave_format), String.valueOf(highScore), String.valueOf(wave));

            textView.setText(statsText);
        }
        else
        {
            setLevelLockedText(textView);
        }
    }

    private void setLevelLockedText(TextView textView)
    {
        ViewUtils.setTextWithIcon(context, textView, context.getString(R.string.level_locked));
    }
}