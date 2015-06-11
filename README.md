Insectoid Defense
===========

<img src="http://gowengamedev.com/wp-content/uploads/2014/12/google_play_feature_graphic.png" />

A Sci-Fi Tower Defense game for Android, iOS, and Windows Phone 8.

This project serves as an excellent template for those wanting to develop cross-platform games for mobile without relying on cross-platform frameworks. It uses precompiler directives to intuitively switch between OpenGL ES and Direct3D rendering. Roughly 90% of the game is written in C++. The other 10% of the game is a reusable wrapper layer written in Java for Android, Objective-C for iOS, and C# for Windows Phone 8.

<img src="http://gowengamedev.com/github/insectoid_defense_showcase.png" />

## Graphics

Thanks goes to <a href="http://www.hirefreelanceartist.com/free-tower-defense-graphics.html" target="_blank">Silviu Ploisteanu</a> for a majority of the graphics used in this game!

## Setup Instructions for Android/iOS

1. Download version **1.6.8** of the libpng library from http://sourceforge.net/projects/libpng/files/libpng16/older-releases/1.6.8/
2. Extract the contents of lpng168.zip into the 3rdparty/libpng directory.
3. Move scripts/pnglibconf.h.prebuilt into the root directory and rename it to pnglibconf.h
4. Replace lines 123-127 of pngpriv.h with **#define PNG_ARM_NEON_OPT 0**

## Setup Instructions for Android

1. Download the Android NDK from https://developer.android.com/ndk/downloads/index.html if you do not already have it
2. Open app/src/main/jni/Android.mk and edit the first line (starting with NDKROOT :=) to point to your Android NDK installation root directory
3. Open in Android Studio (src/platform/android)
4. Open the local.properties file and add the following: ndk.dir=<path to ndk, same as in Android.mk>
5. Run it!

## Setup Instructions for Windows Phone 8

Assuming you already have the Windows Phone 8 sdk installed, just open the project in Visual Studio and run it!