internal class Program
{
    private static void Main(string[] args)
    {
        int amountOfDices = GetAmountOfDices();
        bool play = true;
        Random r = new Random();

        while (true)
        {
            int[] dicesTrown = new int[7];

            for (int i = 0; i < amountOfDices; i++)
            {
                int thrownNumber = r.Next(1, 7);
                dicesTrown[thrownNumber]++;
                Console.WriteLine($"kostka {i+1}: {thrownNumber}");
            }
            Console.WriteLine(CalculateScore(dicesTrown));
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
        Console.WriteLine("Podaj ilość kości");
        int.TryParse(Console.ReadLine(), out int amountOfDices);
        if (amountOfDices < 3 || amountOfDices > 10)
            return amountOfDices;
        else
            return amountOfDices;//XD
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
}
