using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InsectoidDefense
{
    public class LevelDescription
    {
        public LevelDescription(int levelIndex, bool isLocked)
        {
            LevelIndex = levelIndex;
            IsLocked = isLocked;
        }



        public string Description { get; set; }
        public int LevelIndex { get; set; }
        public bool IsLocked { get; set; }

        public override string ToString()
        {
#if FREE_VERSION
            if(LevelIndex >= 4)
            {
                Description = "Please purchase the full version to experience all the levels!";
                return Description;
            }
#endif
                switch (LevelIndex)
                {
                    case 0:
                        Description = "Insectoids have ambushed our star cruiser on our way back to Earth! Most of our weapon systems have already been knocked offline or destroyed entirely. The entire ship is infested, including the civilian quarters. Drive them out!";
                        break;
                    case 1:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(1) : "The Insectoids are nearly out of the civilian quarters, but now we must face their fire armada. They have trapped our best scientists. Fortunately, we have repaired our Freeze Tower, which can force enemies to move slower. Also, it appears that Red Insectoids in particular are very weak to the effects of this tower. Rescue the scientists!";
                        break;
                    case 2:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(2) : "There is a new type of green Insectoid eating away at our ship's hull. They repair damage from attacks rather quickly. Fortunately, we were able to bring our missiles back online. We can use them to obliterate the enemy! Be careful though, because missiles are ineffective against Red Insectoids and are unable to target the Blue Insectoids.";
                        break;
                    case 3:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(3) : "We are unable to transport our civilians off the ship until we establish a safe path for them to the hangar. The scientists we rescued have developed a new Fire tower that can prevent the Green Insectoid from regenerating. Also, any Blue Insectoids caught on fire can be targetted by missiles! Clear a path to the hangar!";
                        break;
                    case 4:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(4) : "We have been cut off from our own hangar, crippling our attack. If we do not reclaim the hangar soon, we will lose our momentum in this fight. The scientists have developed a new Green Tower harnessed from a Green Insectoid we captured in our previous battle. However, we are uncertain of its abilities. In any case, clean out the hangar!";
                        break;
                    case 5:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(5) : "The hangar is ours, but it is in bad shape. The majority of our equipment has been seized and relocated to the bridge, where the Insectoids are regrouping to isolate us in the hangar. We are unable to get the hangar operational again until we reclaim our equipment!";
                        break;
                    case 6:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(6) : "A new yellow Insectoid has penetrated our industrial sector. Unfortunately for us, it appears to be twice as fast as the others. The Insectoids are going to destroy our supplies if we do not act quickly! Early analysis indicates that this Insectoid is resistant to electric attacks but is highly vulnerable to the Green Tower. Good luck!";
                        break;
                    case 7:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(7) : "Our hangar has been repaired, and the civilians have been sent down to our home planet. After retreating for several weeks, the enemy is approaching again. This appears to be their largest attack yet. We are in a much better position now than ever before to fight them, but prepare for the worst…";
                        break;
                    case 8:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(8) : "While we were distracted with the battle topside, the enemy has sabotoged our propulsion system. Unfortunately, we can only afford to send a small team for this, since we are mostly occupied by the larger battle, but we absolutely must regain control of those engines. Otherwise, we will fall out of orbit with our planet and lose our only chance to come home alive!";
                        break;
                    case 9:
                        Description = IsLocked ? LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(9) : "We have prevented additional damage to our engines, but we have slowed down enough for the entire Insectoid army to surround us. Our scientists have engineered a bomb that can destroy them all in one shot. All we need to do is fend them off while it is prepared for deployment and our engines are repaired. Pull this off, and we will be able to escape while the Insectoids are wiped out for good!";
                        break;
                    default:
                        Description = "";
                        break;
            }
            return Description;
        }
    }
}