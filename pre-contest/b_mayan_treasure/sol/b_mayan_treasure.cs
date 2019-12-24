namespace CodingBattle
{
    using System;
    using System.Linq;

    public class Program
    {
        static public void Main(string[] args)
        {
            string line1 = Console.ReadLine(); // Unused
            string line2 = Console.ReadLine();

            int[] numbers = line2.Split(" ").Select(i => int.Parse(i)).OrderBy(i => i).ToArray();

            int min = -1;
            int a = 0, b = 0, c = 0;

            for (int i = 0; i < numbers.Length - 2; i++)
            {
                if (i == 0 || min > numbers[i + 2] - numbers[i])
                {
                    min = numbers[i + 2] - numbers[i];
                    a = numbers[i];
                    b = numbers[i + 1];
                    c = numbers[i + 2];
                }
            }

            Console.WriteLine(a + " " + b + " " + c);
        }
    }
}
