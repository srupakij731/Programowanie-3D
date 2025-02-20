using static System.Math;
StreamReader streamReader = new StreamReader("skrot_przyklad.txt");
string num;
List<string> numbers = new List<string>();
while ((num = streamReader.ReadLine()) != null)
{
    numbers.Add(num);
}
streamReader.Close();


//3.2
int total = 0;
int max = 0;

foreach (string number in numbers)
{

    if (GetOddShortcut(number) == 0)
    {
        total++;
        if (int.Parse(number) > max)
            max = int.Parse(number);
    }
}
Console.WriteLine(total);
Console.WriteLine(max);

//3.3
StreamReader streamReader2 = new StreamReader("skrot2_przyklad.txt");
string num2;
List<string> numbers2 = new List<string>();
while ((num2 = streamReader2.ReadLine()) != null)
{
    numbers2.Add(num2);
}
streamReader2.Close();



foreach (string number in numbers2)
{
    if(GetNWW(int.Parse(number), GetOddShortcut(number)) == 7)
    {
        Console.WriteLine(number);
    }
}

//
int GetOddShortcut(string number)
{
    int oddShortcut = 0;
    int numberInt = int.Parse(number);
    int validLetters = 0;

    while(numberInt > 0)
    {
        int n = numberInt % 10;
        numberInt /= 10;

        if (n % 2 == 1)
        {
            oddShortcut += n * (int)Math.Pow(10, validLetters);
            validLetters++;
        }
    }

    return oddShortcut;
}

int GetNWW(int number1, int number2)
{
    int rest;

    while (number1 % number2 != 0)
    {
        rest = number1 % number2;
        number1 = number2;
        number2 = rest;
    }
    return number2;
}