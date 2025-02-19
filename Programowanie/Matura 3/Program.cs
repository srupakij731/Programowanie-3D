using static System.Math;
StreamReader streamReader = new StreamReader("skrot_przyklad.txt");
string num;
streamReader.ReadLine();
List<string> numbers = new List<string>();
while ((num = streamReader.ReadLine()) != null)
{
    numbers.Add(num);
}
streamReader.Close();


//3.2
int total = 0;
int max = 0;
int ma2x = 0;

foreach (string number in numbers)
{
    bool isGood = true;
    int numberInt = int.Parse(number);
    for (int i = 1; i <= number.Length; i++)
    {
        int n = numberInt % (int)Pow(10, i);
        numberInt -= n;
        n = n / (int)Pow(10, i - 1);
        if(n == 1 || n==3 || n==5|| n== 7|| n==9)
        {
            isGood = false;
            break;
        }
    }
    if (isGood)
    {
        total++;
        if (int.Parse(number) > max)
            max = int.Parse(number);
    }
}
Console.WriteLine(total);
Console.WriteLine(max);