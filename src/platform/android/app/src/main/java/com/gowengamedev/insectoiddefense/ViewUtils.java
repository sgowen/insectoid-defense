package com.gowengamedev.insectoiddefense;

import android.content.Context;
import android.graphics.Color;
import android.graphics.Typeface;
import android.text.Html;
import android.text.SpannableStringBuilder;
import android.text.Spanned;
import android.text.style.ImageSpan;
import android.view.View;
import android.view.ViewGroup;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.TextView;

public final class ViewUtils
{
    private static Typeface astrolytTypeface;

    public static final void setAstrolytTypeFaceForViewGroup(ViewGroup vg)
    {
        for (int i = 0; i < vg.getChildCount(); i++)
        {
            if (vg.getChildAt(i) instanceof ViewGroup)
            {
                setAstrolytTypeFaceForViewGroup((ViewGroup) vg.getChildAt(i));
            }
            else if (vg.getChildAt(i) instanceof TextView)
            {
                ((TextView) vg.getChildAt(i)).setTypeface(getAstrolytTypeface(vg.getContext()));
            }
            else if (vg.getChildAt(i) instanceof Button)
            {
                ((Button) vg.getChildAt(i)).setTypeface(getAstrolytTypeface(vg.getContext()));
            }
        }
    }

    public static void setTextWithIcon(Context context, TextView textView, String text)
    {
        Spanned html = Html.fromHtml(text);
        SpannableStringBuilder builder = new SpannableStringBuilder(html);

        ImageSpan[] images = builder.getSpans(0, builder.length(), ImageSpan.class);
        if (images != null && images.length > 0)
        {
            ImageSpan imagePlaceholder = images[0];
            int start = builder.getSpanStart(imagePlaceholder);
            int end = builder.getSpanEnd(imagePlaceholder);
            int flags = builder.getSpanFlags(imagePlaceholder);

            ImageSpan imageSpan = new ImageSpan(context, R.drawable.lock_icon, ImageSpan.ALIGN_BASELINE);
            builder.setSpan(imageSpan, start, end, flags);
            builder.removeSpan(imagePlaceholder);
        }

        textView.setText(builder);
    }

    public static void resetListViewSelection(AdapterView<?> adapterView)
    {
        for (int i = 0; i < adapterView.getChildCount(); i++)
        {
            View listItem = adapterView.getChildAt(i);
            TextView nameTextView = (TextView) listItem.findViewById(R.id.level_name_textview);
            nameTextView.setTextColor(Color.BLACK);
            TextView statsTextView = (TextView) listItem.findViewById(R.id.level_stats_textview);
            statsTextView.setTextColor(Color.BLACK);
        }
    }

    private static Typeface getAstrolytTypeface(Context context)
    {
        if (astrolytTypeface == null)
        {
            astrolytTypeface = Typeface.createFromAsset(context.getAssets(), "astrolyt.ttf");
        }

        return astrolytTypeface;
    }

    private ViewUtils()
    {
        // Hide Constructor
    }
}