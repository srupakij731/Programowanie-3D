using Microsoft.Maui.Controls;
using Microsoft.Maui.Graphics;
using System.Collections.Generic;

namespace Tpdp
{
    public partial class MainPage : ContentPage
    {
        public MainPage()
        {
            InitializeComponent();
            List<Task> tasks = new List<Task>
            {
                new Task("Zostac Sigmą", true),
                new Task("Być Sigmą", false),
                new Task("umrzeć bedąc Sigmą", true)
            };
            TasksCollectionView.ItemsSource = tasks;
        }
    }
    public class Task
    {
        public string Title { get; set; }
        public Color IsCompleted { get; set; }

        public Task(string title, bool isCompleted)
        {
            Title = title;
            IsCompleted = isCompleted ? Color.FromArgb("#008000") : Color.FromArgb("#ce0010");
        }
    }
}
