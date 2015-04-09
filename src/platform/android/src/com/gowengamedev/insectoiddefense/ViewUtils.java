package com.gowengamedev.insectoiddefense;

import android.annotation.SuppressLint;
import android.app.Activity;
import android.content.Context;
import android.graphics.Color;
import android.graphics.Point;
import android.graphics.Typeface;
import android.os.Build;
import android.os.Build.VERSION;
import android.text.Html;
import android.text.SpannableStringBuilder;
import android.text.Spanned;
import android.text.style.ImageSpan;
import android.view.Display;
import android.view.View;
import android.view.ViewGroup;
import android.view.inputmethod.InputMethodManager;
import android.widget.AdapterView;
import android.widget.Button;
import android.widget.TextView;

import com.gowengamedev.insectoiddefense.R;

public final class ViewUtils
{
    private static Typeface astrolytTypeface;

    public static void hideKeyboardForView(View view)
    {
        Context context = view.getContext();
        InputMethodManager inputMethodManager = (InputMethodManager) context.getSystemService(Context.INPUT_METHOD_SERVICE);
        inputMethodManager.hideSoftInputFromWindow(view.getWindowToken(), InputMethodManager.HIDE_NOT_ALWAYS);
    }

    @SuppressLint("NewApi")
    @SuppressWarnings("deprecation")
    public static Point getScreenSize(Activity activity)
    {
        Display display = activity.getWindowManager().getDefaultDisplay();
        Point size = new Point();

        if (VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB_MR2)
        {
            display.getSize(size);
        }
        else
        {
            size.x = display.getWidth();
            size.y = display.getHeight();
        }

        return size;
    }

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

    public static String getTrimmedString(TextView tv)
    {
        return tv.getText().toString().trim();
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