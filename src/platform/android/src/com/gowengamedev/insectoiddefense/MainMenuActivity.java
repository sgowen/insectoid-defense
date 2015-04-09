package com.gowengamedev.insectoiddefense;

import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;

import com.gowengamedev.insectoiddefense.R;

public final class MainMenuActivity extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

        Logger.initializeLoggingLevel("DEBUG");

        AppPrefs.setInstance(this);

        requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN, WindowManager.LayoutParams.FLAG_FULLSCREEN);
        getWindow().clearFlags(WindowManager.LayoutParams.FLAG_FORCE_NOT_FULLSCREEN);

        setContentView(R.layout.activity_main_menu);

        ViewUtils.setAstrolytTypeFaceForViewGroup((ViewGroup) findViewById(R.id.main_menu_container));
    }

    public void clickPlay(View view)
    {
        LevelSelectionActivity.startActivity(this);
    }

    public void clickHowToPlay(View view)
    {
        startActivity(new Intent(android.content.Intent.ACTION_VIEW, Uri.parse("https://s3.amazonaws.com/insectoiddefense/insectoid-defense-how-to-play/index.html")));
    }
}