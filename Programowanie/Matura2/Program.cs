StreamReader streamReader = new StreamReader("przyklad.txt");
string num;
List<string> numbers = new List<string>();
while ((num = streamReader.ReadLine()) != null)
{
    numbers.Add(num);
}
streamReader.Close();

Console.WriteLine("4.1");
foreach (string number in numbers)
{

    string n = reverse(number);
    if (int.Parse(n) % 17 == 0)
    {
        Console.WriteLine(n);
    }
}

Console.WriteLine("\n4.2");
string highest = "0";

foreach (string number in numbers)
{
    int n = Math.Abs((int.Parse(number)));

    string sNumberReverse = reverse(number);
    int numberReverse = Math.Abs(int.Parse(sNumberReverse));

    if (int.Parse(highest) < (n - numberReverse))
    {
        highest = number;
    }
}
Console.WriteLine(highest);
Console.WriteLine(Math.Abs(int.Parse(highest) - int.Parse(reverse(highest))));

Console.WriteLine("\n4.3");
foreach(string number in numbers)
{
    if(isPrimaryNumber(number) && isPrimaryNumber(reverse(number)))
        Console.WriteLine(number);

}

Console.WriteLine("\n4.4");
int twoNumbers = 0;
int threeNumbers = 0;
var numbersGrouped = numbers.GroupBy(n => n);

foreach(var group in numbersGrouped)
{
    if(group.Count() == 2)
        twoNumbers++;
    if(group.Count() == 3)
        threeNumbers++;
}
Console.WriteLine(numbersGrouped.Count());
Console.WriteLine(twoNumbers);
Console.WriteLine(threeNumbers);


string reverse(string number)
{
    string n ="";
    for(int i = number.Length-1; i >= 0; i--)
    {
        n += number[i];
    }
    return n;
}

bool isPrimaryNumber(string number)
{
    int n = int.Parse(number);
    for(int i = 2; i < n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}