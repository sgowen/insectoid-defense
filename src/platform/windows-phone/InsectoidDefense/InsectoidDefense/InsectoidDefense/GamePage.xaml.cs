using System;
using System.Collections.Generic;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using Microsoft.Phone.Tasks;
using System.Diagnostics;
using System.IO.IsolatedStorage;
using InsectoidDefenseComp;
using Coding4Fun.Toolkit.Controls;
using System.Windows.Media.Imaging;

namespace InsectoidDefense
{
    public partial class GamePage : PhoneApplicationPage
    {
        private Direct3DInterop m_d3dInterop = new Direct3DInterop();
        private object m_d3dContentProvider;
        private int levelIndex = 0;
        private int difficulty = 1;

        public GamePage()
        {
            InitializeComponent();
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            string str_levelIndex;
            if (NavigationContext.QueryString.TryGetValue("levelIndex", out str_levelIndex))
            {
                Console.WriteLine("str_levelIndex = " + str_levelIndex);
                levelIndex = Convert.ToInt32(str_levelIndex);
            }

            string str_difficulty;
            if (NavigationContext.QueryString.TryGetValue("difficulty", out str_difficulty))
            {
                Console.WriteLine("str_difficulty = " + str_difficulty);
                difficulty = Convert.ToInt32(str_difficulty);
            }
        }

        protected override void OnNavigatedFrom(NavigationEventArgs e)
        {
            base.OnNavigatedFrom(e);

            saveHighScore();
        }

        protected override void OnBackKeyPress(System.ComponentModel.CancelEventArgs e)
        {
            base.OnBackKeyPress(e);

            if (m_d3dInterop.onBackPressed())
            {
                e.Cancel = true;
            }
        }

        private void DrawingSurface_Loaded(object sender, RoutedEventArgs e)
        {
            // Set window bounds in dips
            m_d3dInterop.WindowBounds = new Windows.Foundation.Size((float)DrawingSurface.ActualWidth, (float)DrawingSurface.ActualHeight);

            // Set native resolution in pixels
            m_d3dInterop.NativeResolution = new Windows.Foundation.Size((float)Math.Floor(DrawingSurface.ActualWidth * Application.Current.Host.Content.ScaleFactor / 100.0f + 0.5f), (float)Math.Floor(DrawingSurface.ActualHeight * Application.Current.Host.Content.ScaleFactor / 100.0f + 0.5f));

            // Set render resolution to the full native resolution
            m_d3dInterop.RenderResolution = m_d3dInterop.NativeResolution;

            if (m_d3dContentProvider == null)
            {
                m_d3dContentProvider = m_d3dInterop.CreateContentProvider(levelIndex, difficulty, SaveData.getHighWaveForDifficultyLevelAndLevelIndex(difficulty, levelIndex) >= LevelWaveRequirementMapper.getWaveRequirementForLevelIndex(levelIndex));
            }

            // Hook-up native component to DrawingSurface
            DrawingSurface.SetContentProvider(m_d3dContentProvider);
            DrawingSurface.SetManipulationHandler(m_d3dInterop);

            m_d3dInterop.setWinRtCallback(new WinRtCallback(ProcessCallback));
        }

        private void ProcessCallback(String command, String param)
        {
            if (command.Equals("EXIT"))
            {
                Deployment.Current.Dispatcher.BeginInvoke(() =>
                {
                    NavigationService.GoBack();
                });
            }
            else if (command.Equals("DISPLAY_TOAST"))
            {
                Deployment.Current.Dispatcher.BeginInvoke(() =>
                {
                    ToastPrompt toast = new ToastPrompt();
                    toast.FontSize = 30;
                    toast.Title = param;
                    toast.TextOrientation = System.Windows.Controls.Orientation.Horizontal;

                    toast.Show();
                });
            }
            else if (command.Equals("GAME_OVER"))
            {
                saveHighScore();
            }
        }

        private void saveHighScore()
        {
            int highScore = m_d3dInterop.getScore();
            int highWave = m_d3dInterop.getWave();

            SaveData.saveHighScoreForLevel(highScore, highWave, difficulty, levelIndex);
        }
    }
}