namespace InsectoidDefense
{
    public class LevelWaveRequirementMapper
    {
        public static int getWaveRequirementForLevelIndex(int levelIndex)
        {
            switch (levelIndex)
            {
                case 0:
                    return 20;
                case 1:
                    return 30;
                case 2:
                    return 30;
                case 3:
                    return 30;
                case 4:
                    return 20;
                case 5:
                    return 30;
                case 6:
                    return 20;
                case 7:
                    return 50;
                case 8:
                    return 40;
                case 9:
                default:
                    return 60;
            }
        }

        public static string getLockedDescriptionStringResourceForLevelIndex(int levelIndex)
        {
            switch (levelIndex)
            {
                case 0:
                    return "We should never see this message.";
                case 1:
                    return "Reach wave 20 or higher in Invasion! to unlock!";
                case 2:
                    return "Reach wave 30 or higher in Freeze or Burn to unlock!";
                case 3:
                    return "Reach wave 30 or higher in Hull Damage to unlock!";
                case 4:
                    return "Reach wave 30 or higher in Clear a Path to unlock!";
                case 5:
                    return "Reach wave 20 or higher in Hangar Breach to unlock!";
                case 6:
                    return "Reach wave 30 or higher in Divided to unlock!";
                case 7:
                    return "Reach wave 20 or higher in Blitzkrieg to unlock!";
                case 8:
                    return "Reach wave 50 or higher in Full-scale War to unlock!";
                case 9:
                default:
                    return "Reach wave 40 or higher in Sabotoge to unlock!";
            }
        }
    }
}