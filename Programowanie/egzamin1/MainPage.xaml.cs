namespace egzamin1
{
    public partial class MainPage : ContentPage
    {
        int count = 0;

        public MainPage()
        {
            InitializeComponent();
        }

        private void Button_Clicked(object sender, EventArgs e)
        {
            if (!email.Text.Contains("@"))
            {
                result.Text = "Zły e-mail";
                return;
            }
            if (password1.Text != password2.Text)
            {
                result.Text = "Hasła się nie zgadzają";
                return;
            }

            result.Text = "Witaj " + email.Text;
        }
    }
}
