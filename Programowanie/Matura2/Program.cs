StreamReader streamReader = new StreamReader("przyklad.txt");
string num;
streamReader.ReadLine();
List<string> numbers = new List<string>();
while ((num = streamReader.ReadLine()) != null)
{
    numbers.Add(num);
}
streamReader.Close();

foreach (string number in numbers)
{

    string n = new string(number.Reverse().ToArray());
    if (int.Parse(n) % 17 == 0)
    {
        //Console.WriteLine(n);
    }
}

//4.2
int highest = 0;

foreach (string number in numbers)
{
    int n = Math.Abs((int.Parse(number)));

    string sNumberReverse = new string(number.Reverse().ToArray());
    int numberReverse = Math.Abs(int.Parse(sNumberReverse));

    if (highest < n - numberReverse)
    {
        highest = n;
    }
}
Console.WriteLine(highest);

//4.3   