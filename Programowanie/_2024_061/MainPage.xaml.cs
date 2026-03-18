using System.Collections.ObjectModel;
using System.ComponentModel;
using System.Runtime.CompilerServices;

namespace _2024_061
{
    public partial class MainPage : ContentPage, INotifyPropertyChanged
    {
        const int AmountOfDices = 67;
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

        private int total;
        public int Total
        {
            get => total;
            set
            {
                if (total != value)
                {
                    total = value;
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
            var cubes = new ObservableCollection<int>();
            Dictionary<int, int> existing = new Dictionary<int, int>();

            for (int i = 0; i < AmountOfDices; i++)
            {
                int roll = random.Next(1, 7);
                DiceImages[i] = $"k{roll}.jpg";

                cubes.Add(roll);

                if (existing.ContainsKey(roll))
                    existing[roll]++;
                else
                    existing[roll] = 1;
            }

            foreach (var group in cubes.GroupBy(x => x))
            {
                if (group.Count() >= 2)
                {
                    Score += group.Key * group.Count();
                    
                }
            }
            Total += Score;
        }


        private void Reset(object sender, EventArgs e)
        {
            Score = 0;
            Total = 0;
            for (int i = 0; i < AmountOfDices; i++)
                DiceImages[i] = "question.jpg";
        }
    }
}
