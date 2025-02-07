StreamReader sr = new StreamReader("przyklad.txt");
string num;
sr.ReadLine();
List<string> numbers = new List<string>();
while ((num = sr.ReadLine()) != null)
{
    numbers.Add(num);
}
sr.Close();

//4.1

//int counter4_1 = numbers.Where(s => s[0] == s[s.Length-1]).Count();
//string firstNumber4_1 = numbers.First(s => s[0] == s[s.Length - 1]);

//Console.WriteLine($"{counter4_1} {firstNumber4_1}");

//4.2
int MaxPrimeNumbers = 0;
for (int i = 0; i < numbers.Count; i++)
{
    List<int> PrimeNumbers = new List<int>();

    int numb = int.Parse(numbers[0]);
    for (int j = 2; j <= numb; j++)
    {
        if (j == int.Parse(numbers[i]))
        {
            break;
        }
        while (numb % j == 0)
        {
            PrimeNumbers.Add(j);
            numb /= j;
        }
    }
    if(PrimeNumbers.Count > MaxPrimeNumbers)
    {
        MaxPrimeNumbers = PrimeNumbers.Count;
    }
}
Console.WriteLine(MaxPrimeNumbers);