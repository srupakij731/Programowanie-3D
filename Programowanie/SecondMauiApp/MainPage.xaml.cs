using System;
using Microsoft.Maui.Controls;

namespace SecondMauiApp;

public partial class MainPage : ContentPage
{
    public MainPage()
    {
        InitializeComponent();
    }

    private void Button_Clicked(object sender, EventArgs e)
    {
        bool isValid1 = double.TryParse(number1.Text, out double num1);
        bool isValid2 = double.TryParse(number2.Text, out double num2);

        if (isValid1 && isValid2)
        {
            double suma = num1 + num2;
            result.Text = $"Wynik: {suma}";
        }
        else
        {
            result.Text = "Błąd: Wprowadź poprawne liczby!";
        }
    }
}
