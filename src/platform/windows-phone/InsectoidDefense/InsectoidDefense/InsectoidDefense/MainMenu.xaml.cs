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
using System.Diagnostics;

namespace InsectoidDefense
{
    public partial class MainMenu : PhoneApplicationPage
    {
        public MainMenu()
        {
            InitializeComponent();
        }

        private void Button_Click_1(object sender, RoutedEventArgs e)
        {
            NavigationService.Navigate(new Uri("/LevelSelect.xaml", UriKind.Relative));
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
    }
}