List<int> intsCollection = new List<int>();
intsCollection.Add(15);
intsCollection.Add(18);
intsCollection.Add(5);
intsCollection.Add(12);
intsCollection.Add(19);
intsCollection.Add(4);

Console.WriteLine(intsCollection[0]);
Console.WriteLine(intsCollection[1]);
intsCollection.RemoveAt(1);
Console.WriteLine(intsCollection[0]);
Console.WriteLine(intsCollection[1]);

Console.WriteLine("elementy w kolekcji");
for (int i = 0; i < intsCollection.Count; i++)
{
    Console.WriteLine(intsCollection[i]);
}

List<int> ints = new List<int>();
for (int i = 0; i < intsCollection.Count; i++)
{
    if (intsCollection[i] > 10)
    ints.Add(intsCollection[i]);
}

Console.WriteLine("elementy w kolekcji więkrze od 10");
for (int i = 0; i < ints.Count; i++)
{
    Console.WriteLine(ints[i]);
}
