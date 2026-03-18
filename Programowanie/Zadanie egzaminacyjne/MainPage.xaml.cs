

namespace Zadanie_egzaminacyjne
{
    
    public partial class MainPage : ContentPage
    {

        public string Name { get;  set;}
        public string Surname { get; set;}
        public string Position { get; set; }
        public string AmountOfCharacters { get; set; }
        public bool Letters { get; set; }
        public bool Numbers { get; set; }
        public bool SpecialChars { get; set; }
        int[] order = { 1, 2, 3, 4 };
        int categoryIndex = 0;

        private string password;
        public MainPage()
        {
            InitializeComponent();
        }

        private void Confirm(object sender, EventArgs e)
        {
             DisplayAlert("Tytuł", $"Dane pracownika: {Name}, {Surname}, {Position}, hasło: {password}", "OK");
        }

        private void GeneratePasswod(object sender, EventArgs e)
        {
            Random rnd = new Random();
            if (Numbers)
                password += (char)('0' + rnd.Next(0, 10)); ;
            if(Letters)
                password += (char)('A' + rnd.Next(0, 26));
            if(SpecialChars)
            {
                char[] znakiSpecjalne = { '!', '"', '#', '$', '%', '&', '\'', '(', ')', '*', '+' };
                password += znakiSpecjalne[rnd.Next(0, znakiSpecjalne.Length)];
            }

            int amountOfCharacters2 = int.Parse(AmountOfCharacters);
            int total = password.Length;
            for (int i = 0; i < amountOfCharacters2 - total; i++)
            {
                password += (char)('a' + rnd.Next(0, 26));
            }

            DisplayAlert("", $"{password}", "OK");
        }

    }
}
