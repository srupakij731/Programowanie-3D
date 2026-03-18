using ClassLibrary;
using ClassLibrary.Models;
namespace quiz
{
    public partial class MainPage : ContentPage
    {
        int current = 1;
        int correntAnswers = 0;
        public MainPage()
        {
            InitializeComponent();
        }

        private void OnNextQuestionClicked(object? sender, EventArgs e)
        {
            current++;
            QuizService q = new QuizService();
            AnswerBtn.IsEnabled = true;
            QuestionIdLabel.Text = "Pytanie: " + (current-1);
            Question question = q.GetQuestion(current);
            if (question == null)
            {
                QuestionLabel.Text = "Koniec quizu!";
                MainLayout.Children.Clear();
                return;
            }

            QuestionLabel.Text = question.Text;

            List<Answer> answers = q.GetAnswers(question.Id);

            MainLayout.Children.Clear();

            var radioGroup = new VerticalStackLayout { Spacing = 5 };

            foreach (var answer in answers)
            {
                var radio = new RadioButton
                {
                    Content = answer.Text,
                    Value = answer  
                };

                radio.CheckedChanged += (s, args) =>
                {
                    if (args.Value)
                        Console.WriteLine($"Wybrano odpowiedź: {answer.Text}");
                };

                radioGroup.Children.Add(radio);
            }

            MainLayout.Children.Add(radioGroup);
        }

        private void OnAnswerSend(object? sender, EventArgs e)
        {
            AnswerBtn.IsEnabled = false;
            var radioGroup = MainLayout.Children
                                .OfType<VerticalStackLayout>()
                                .FirstOrDefault();

            if (radioGroup == null)
                return;

            var selectedRadio = radioGroup.Children
                                .OfType<RadioButton>()
                                .FirstOrDefault(r => r.IsChecked);

            if (selectedRadio != null)
            {
                Answer selectedAnswer = (Answer)selectedRadio.Value;

                if (selectedAnswer.IsCorrect)
                {
                    correntAnswers++;
                }
            }
            MainLayout.Children.Clear();

            CorrentAnswers.Text = "Aktualna ilość poprawnych odpowiedzi: " + correntAnswers;
        }
    }
}
