using System.Reflection.Metadata.Ecma335;

Console.WriteLine("aaaa");
string stringi = "E-Mail";
Console.WriteLine("tekst" + stringi);
Console.WriteLine("tekst {0}", stringi);
Console.WriteLine($"tekst {stringi}");

Console.WriteLine("km\\h");
Console.WriteLine(@"km\h");

int number = -69;
Console.WriteLine(number);
void function(int x)
{
    x += 1;
}
function(number);
Console.WriteLine(number);
