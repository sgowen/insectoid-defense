
package com.gowengamedev.insectoiddefense;

import android.annotation.SuppressLint;

import java.util.HashMap;
import java.util.Map;

@SuppressLint("UseSparseArrays")
public final class LevelWaveRequirementMapper
{
    private static final Map<Integer, Integer> levelWaveRequirementMap;
    private static final Map<Integer, Integer> levelLockedDescriptionStringResourceMap;
    private static final Map<Integer, Integer> levelUnlockedAchievementTextMap;

    static
    {
        levelWaveRequirementMap = new HashMap<>();
        levelWaveRequirementMap.put(0, 20);
        levelWaveRequirementMap.put(1, 30);
        levelWaveRequirementMap.put(2, 30);
        levelWaveRequirementMap.put(3, 30);
        levelWaveRequirementMap.put(4, 20);
        levelWaveRequirementMap.put(5, 30);
        levelWaveRequirementMap.put(6, 20);
        levelWaveRequirementMap.put(7, 50);
        levelWaveRequirementMap.put(8, 40);
        levelWaveRequirementMap.put(9, 60);

        levelLockedDescriptionStringResourceMap = new HashMap<>();
        levelLockedDescriptionStringResourceMap.put(1, R.string.level_2_locked);
        levelLockedDescriptionStringResourceMap.put(2, R.string.level_3_locked);
        levelLockedDescriptionStringResourceMap.put(3, R.string.level_4_locked);
        levelLockedDescriptionStringResourceMap.put(4, R.string.level_5_locked);
        levelLockedDescriptionStringResourceMap.put(5, R.string.level_6_locked);
        levelLockedDescriptionStringResourceMap.put(6, R.string.level_7_locked);
        levelLockedDescriptionStringResourceMap.put(7, R.string.level_8_locked);
        levelLockedDescriptionStringResourceMap.put(8, R.string.level_9_locked);
        levelLockedDescriptionStringResourceMap.put(9, R.string.level_10_locked);

        levelUnlockedAchievementTextMap = new HashMap<>();
        levelUnlockedAchievementTextMap.put(0, R.string.level_2_unlocked);
        levelUnlockedAchievementTextMap.put(1, R.string.level_3_unlocked);
        levelUnlockedAchievementTextMap.put(2, R.string.level_4_unlocked);
        levelUnlockedAchievementTextMap.put(3, R.string.level_5_unlocked);
        levelUnlockedAchievementTextMap.put(4, R.string.level_6_unlocked);
        levelUnlockedAchievementTextMap.put(5, R.string.level_7_unlocked);
        levelUnlockedAchievementTextMap.put(6, R.string.level_8_unlocked);
        levelUnlockedAchievementTextMap.put(7, R.string.level_9_unlocked);
        levelUnlockedAchievementTextMap.put(8, R.string.level_10_unlocked);
        levelUnlockedAchievementTextMap.put(9, R.string.game_cleared);
    }

    public static int getWaveRequirementForLevelIndex(Integer levelIndex)
    {
        return levelWaveRequirementMap.get(levelIndex);
    }

    public static int getLockedDescriptionStringResourceForLevelIndex(Integer levelIndex)
    {
        return levelLockedDescriptionStringResourceMap.get(levelIndex);
    }

    public static int getLevelUnlockedAchievementToastStringResourceForLevelIndex(Integer levelIndex)
    {
        return levelUnlockedAchievementTextMap.get(levelIndex);
    }
}