internal class Program
{
    private static void Main(string[] args)
    {
        int amountOfDices = GetAmountOfDices();

        while (true)
        {
            int[] dices = new int[7];
            dices = ThrowDices(dices, amountOfDices);
            for (int i =0;i < 7;i++)
                Console.WriteLine($"kostka {i + 1}: {dices[i]}");

            Console.WriteLine(CalculateScore(dices));

            Console.WriteLine("Grać dalej t/n");
            string c = Console.ReadLine();
            if (c == "t")
                continue;
            else if (c == "n")
                break;
        }
    }

    public static int GetAmountOfDices()
    {
        int amountOfDices;
        do
        {
            Console.WriteLine("Podaj ilość kości");
            amountOfDices = int.Parse(Console.ReadLine());
        }
        while (amountOfDices < 3 || amountOfDices > 10);
            return amountOfDices;

    }

    public static int CalculateScore(int[] dices)
    {
        int score = 0;
        for(int i = 1; i <=6; i++)
        {
            if (dices[i] > 1)
                score += i * dices[i];
        }
        return score;
    }

    public static int[] ThrowDices(int[] dicesTrown, int amountOfDices)
    {
        for (int i = 0; i < amountOfDices; i++)
        {
            Random r = new Random();
            int thrownNumber = r.Next(1, 7);
            dicesTrown[thrownNumber]++;
        }
        return dicesTrown;
    }
}
