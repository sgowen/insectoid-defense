using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;

namespace InsectoidDefense
{
    public class ListBoxSelector : TemplateSelector
    {
        public DataTemplate Unlocked { get; set; }
        public DataTemplate Locked { get; set; }

        public override DataTemplate SelectTemplate(object item, DependencyObject container)
        {
            Data lvlItem = item as Data;
            if (lvlItem != null)
            {
                if (lvlItem.Locked == "N")
                {
                    return Unlocked;
                }
                else if (lvlItem.Locked == "Y")
                {
                    return Locked;
                }
            }

            throw new NotImplementedException();
        }
    }
}