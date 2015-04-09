using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Net;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Navigation;
using System.Windows.Media.Imaging;
using Microsoft.Phone.Controls;
using Microsoft.Phone.Shell;
using Microsoft.Phone.Tasks;
using System.Xml.Linq;
using System.Diagnostics;

namespace InsectoidDefense
{
    public partial class LevelSelect : PhoneApplicationPage
    {
        private static String[] nameArray = new String[10];

        public ObservableCollection<Data> myText = new ObservableCollection<Data>();

        private BitmapImage ship = new BitmapImage(new Uri("/Assets/ship_default.png", UriKind.Relative));
        private Data[] dataArray = new Data[10];

        private int selectedLevelIndex;
        private int selectedDifficulty = 1;

        public int getLevel()
        {
            return selectedLevelIndex;
        }

        static LevelSelect()
        {
            nameArray[0] = "Invasion!";
            nameArray[1] = "Freeze or Burn";
            nameArray[2] = "Hull Damage";
            nameArray[3] = "Clear a Path";
            nameArray[4] = "Hangar Breach";
            nameArray[5] = "Divided";
            nameArray[6] = "Blitzkrieg";
            nameArray[7] = "Full-Scale War";
            nameArray[8] = "Sabotage";
            nameArray[9] = "Finale";
        }

        public LevelSelect()
        {
            InitializeComponent();

            FillDataArray();
            PopulateList();

            EasyButton.Checked += new RoutedEventHandler(EasyButton_Checked);
            NormalButton.Checked += new RoutedEventHandler(NormalButton_Checked);
            HardButton.Checked += new RoutedEventHandler(HardButton_Checked);

            mediaElement1.MediaEnded += new RoutedEventHandler(mediaElement1_MediaEnded);
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            PopulateList();
        }

        private void mediaElement1_MediaEnded(object sender, RoutedEventArgs e)
        {
            mediaElement1.Position = TimeSpan.Zero;
            mediaElement1.Play();
        }

        private void EasyButton_Checked(object sender, RoutedEventArgs e)
        {
            if (EasyButton.IsChecked == true)
            {
                EasyButton.Background.Opacity = 255;
                selectedDifficulty = 0;
                PopulateList();
            }
            else
            {
                EasyButton.Background.Opacity = 0;
            }
        }

        private void NormalButton_Checked(object sender, RoutedEventArgs e)
        {
            if (NormalButton.IsChecked == true)
            {
                NormalButton.Background.Opacity = 255;
                selectedDifficulty = 1;
                PopulateList();
            }
            else
            {
                NormalButton.Background.Opacity = 0;
            }
        }

        private void HardButton_Checked(object sender, RoutedEventArgs e)
        {
            if (HardButton.IsChecked == true)
            {
                HardButton.Background.Opacity = 255;
                selectedDifficulty = 2;
                PopulateList();
            }
            else
            {
                HardButton.Background.Opacity = 0;
            }
        }

        private void StartButton_Click(object sender, RoutedEventArgs e)
        {
            SaveData.setTutorialViewedForLevel(5);
            SaveData.setTutorialViewedForLevel(7);
            SaveData.setTutorialViewedForLevel(8);
            SaveData.setTutorialViewedForLevel(9);

            NavigationService.Navigate(new Uri("/GamePage.xaml?levelIndex=" + selectedLevelIndex + "&difficulty=" + selectedDifficulty, UriKind.Relative));
        }

        private void MainBox_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            selectedLevelIndex = MainBox.SelectedIndex;

            if (selectedLevelIndex >= 0 && selectedLevelIndex <= 9)
            {
                ship.UriSource = new Uri("/Assets/ship_level_" + (selectedLevelIndex + 1) + ".png", UriKind.Relative);
                bool isLocked = dataArray[selectedLevelIndex].Locked == "Y";

                description.DataContext = new LevelDescription(selectedLevelIndex, isLocked);
                StartButton.Visibility = isLocked ? Visibility.Collapsed : Visibility.Visible;
            }
            else
            {
                ship.UriSource = new Uri("/Assets/ship_default.png", UriKind.Relative);
                description.DataContext = new LevelDescription(selectedLevelIndex, false);
                StartButton.Visibility = Visibility.Collapsed;
            }

            ShipImage.Source = ship;

            InvalidateArrange();
        }

        private void PopulateList()
        {
            MainBox.SelectedIndex = -1;

            myText.Clear();

            for (int i = 0; i < 10; i++)
            {
                dataArray[i].Locked = i > 0 && SaveData.getHighWaveForDifficultyLevelAndLevelIndex(selectedDifficulty, i - 1) < LevelWaveRequirementMapper.getWaveRequirementForLevelIndex(i - 1) ? "Y" : "N";
                dataArray[i].HighScore = SaveData.getHighScoreForDifficultyLevelAndLevelIndex(selectedDifficulty, i);
                dataArray[i].HighWave = SaveData.getHighWaveForDifficultyLevelAndLevelIndex(selectedDifficulty, i);
                myText.Add(dataArray[i]);
            }

            MainBox.ItemsSource = myText;
        }

        private void FillDataArray()
        {
            for (int i = 0; i < 10; i++)
            {
                dataArray[i] = new Data()
                {
                    Name = nameArray[i],
                    Locked = i > 0 && SaveData.getHighWaveForDifficultyLevelAndLevelIndex(selectedDifficulty, i - 1) < LevelWaveRequirementMapper.getWaveRequirementForLevelIndex(i - 1) ? "Y" : "N",
                    HighScore = SaveData.getHighScoreForDifficultyLevelAndLevelIndex(selectedDifficulty, i),
                    HighWave = SaveData.getHighWaveForDifficultyLevelAndLevelIndex(selectedDifficulty, i),
                    UnlockMessage = LevelWaveRequirementMapper.getLockedDescriptionStringResourceForLevelIndex(i)
                };
            }
        }
    }
}