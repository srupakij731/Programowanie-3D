using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace _2024_06
{
    public partial class MainPage : ContentPage, INotifyPropertyChanged
    {
        const int AmountOfDices = 5;
        Random random = new Random();

        public ObservableCollection<string> DiceImages { get; set; } = new ObservableCollection<string>();

        private int score;
        public int Score
        {
            get => score;
            set
            {
                if (score != value)
                {
                    score = value;
                    OnPropertyChanged();
                }
            }
        }

        public MainPage()
        {
            InitializeComponent();
            for (int i = 0; i < AmountOfDices; i++)
                DiceImages.Add("question.jpg");

            BindingContext = this;
        }

        private void Roll(object sender, EventArgs e)
        {
            Score = 0;
            for (int i = 0; i < AmountOfDices; i++)
            {
                int roll = random.Next(1, 7);
                DiceImages[i] = $"k{roll}.jpg";
                Score += roll;
            }
        }

        private void Reset(object sender, EventArgs e)
        {
            Score = 0;
            for (int i = 0; i < AmountOfDices; i++)
                DiceImages[i] = "question.jpg"; 
        }
    }
}
