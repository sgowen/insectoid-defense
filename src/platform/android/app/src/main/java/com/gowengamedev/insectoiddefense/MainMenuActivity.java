package com.gowengamedev.insectoiddefense;

import android.app.Activity;
import android.os.Bundle;
import android.view.View;
import android.view.ViewGroup;
import android.view.Window;
import android.view.WindowManager;

public final class MainMenuActivity extends Activity
{
    @Override
    public void onCreate(Bundle savedInstanceState)
    {
        super.onCreate(savedInstanceState);

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
}