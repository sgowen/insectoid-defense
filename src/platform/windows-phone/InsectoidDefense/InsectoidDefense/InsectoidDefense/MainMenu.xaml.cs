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
using System.IO;
using System.IO.IsolatedStorage;
using System.Windows.Resources;
using System.Windows.Media.Animation;
using OpenXLive;
using OpenXLive.Silverlight;
using OpenXLive.Features;
using System.Diagnostics;

namespace InsectoidDefense
{
    public partial class MainMenu : PhoneApplicationPage
    {
        public MainMenu()
        {
            InitializeComponent();
            SignInBox.DataContext = "Sign in to have your name appear on the leaderboards and earn achievements!";
        }

        protected override void OnNavigatedTo(System.Windows.Navigation.NavigationEventArgs e)
        {
            base.OnNavigatedTo(e);

            if (XLiveGameManager.CurrentSession != null && XLiveGameManager.CurrentSession.IsValid && XLiveGameManager.CurrentSession.CurrentPlayer != null && !XLiveGameManager.CurrentSession.CurrentPlayer.IsAnonymous)
            {
                MyPlayer player = XLiveGameManager.CurrentSession.CurrentPlayer;
                string playerName = player.Title;
                SignInBox.Text = "Hello " + playerName + ", now you can earn achievements and share your high scores with the world!";
                SignInBox.InvalidateArrange();
            }
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Uri("/LevelSelect.xaml", UriKind.Relative));
        }

        private void Button_Click(object sender, RoutedEventArgs e)
        {
            browser.Visibility = Visibility.Visible;
            browser.Navigate(new Uri("https://s3.amazonaws.com/insectoiddefense/insectoid-defense-how-to-play/index.html", UriKind.Absolute));
        }

        protected override void OnBackKeyPress(System.ComponentModel.CancelEventArgs e)
        {
            base.OnBackKeyPress(e);

            if (browser.Visibility == Visibility.Visible)
            {
                browser.Visibility = Visibility.Collapsed;
                e.Cancel = true;
            }
        }

        private void Button_Click_2(object sender, RoutedEventArgs e)
        {
            if (XLiveGameManager.CurrentSession != null && XLiveGameManager.CurrentSession.IsValid)
            {
                OpenXLive.Silverlight.XLiveUIManager.ShowLeaderboard();
            }
        }

        private void Button_Click_3(object sender, RoutedEventArgs e)
        {
            MarketplaceReviewTask task = new MarketplaceReviewTask();
            task.Show();
        }

        private void Button_Click_4(object sender, RoutedEventArgs e)
        {
            OpenXLive.Silverlight.XLiveUIManager.ShowLogon();
        }

        private void AchieveButton_Click(object sender, RoutedEventArgs e)
        {
            if (XLiveGameManager.CurrentSession != null && XLiveGameManager.CurrentSession.IsValid)
            {
                OpenXLive.Silverlight.XLiveUIManager.ShowAchievement();
            }
        }
    }
}