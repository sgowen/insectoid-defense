using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace InsectoidDefense
{
    public class LevelText
    {
        public LevelText(string levelName, int highScore, int highWave)
        {
            LevelName = levelName;
            HighScore = highScore;
            HighWave = highWave;
        }

        public string LevelName { get; set; }
        public bool IsLocked { get; set; }
        public int HighScore { get; set; }
        public int HighWave { get; set; }
        public string ScoreWave
        {
            get
            {
                return string.Format("Highscore: {0}, Wave: {1}", this.HighScore.ToString(), this.HighWave.ToString());
            }
            set
            {

            }
        }
        public override string ToString()
        {
            return this.LevelName;
        }
    }
}