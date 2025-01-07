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

int counter4_1 = numbers.Where(s => s[0] == s[s.Length-1]).Count();
string firstNumber4_1 = numbers.First(s => s[0] == s[s.Length - 1]);

Console.WriteLine($"{counter4_1} {firstNumber4_1}");
