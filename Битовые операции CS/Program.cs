using System;

namespace Битовые_операции_CS
{
    class Program
    {
        static void Increment(ref int x)
        {
            int i;
            for (i = 1; (x & i) != 0; i <<= 1)
            {
                x &= ~i;
            }
            x |= i;
        }
        static bool Equality(int x, int y)
        {
            if ((x ^ y) == 0)
                return true;
            else
                return false;
        }
        static void Main(string[] args)
        {
            int a, b, c;

            Console.WriteLine("Enter numbers for checking on equality:");
            a = Convert.ToInt32(Console.ReadLine());
            b = Convert.ToInt32(Console.ReadLine());

            if (Equality(a, b) == true)
                Console.WriteLine($"{a} equal to {b}");
            else
                Console.WriteLine($"{a} not equal to {b}");

            Console.WriteLine("\nEnter the number for incrementing:");
            c = Convert.ToInt32(Console.ReadLine());
            Increment(ref c);

            Console.WriteLine("The incremented number: ");
            Console.WriteLine(c);
        }
    }
}
