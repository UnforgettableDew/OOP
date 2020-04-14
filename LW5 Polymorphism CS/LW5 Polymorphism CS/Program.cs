using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LW5_Polymorphism_CS
{
    class Line
    {
        protected char[] str;

        public Line(char[] str)
        {
            this.str = str;
        }

        public Line() {}
        public char[] getLine()
        {
            if (str != null)
                return str;
            else
            {
                string ex = "There is nothing to get\n";
                return ex.ToCharArray();
            }
        }

        public int getLength()
        {
            if (str != null)
                return str.Length;
            else
                return 0;
        }
    }

    class LettersLine:Line
    {
        private bool isNumber = false;

        public LettersLine(char[] str)
        {

            for (int i = 0; i < str.Length; i++)
                if (str[i] <= 97 || str[i] >= 122)
                {
                    isNumber = true;
                    break;
                }
            if (isNumber == true)
                Console.WriteLine("There are numbers in the line\n");
            else
                this.str = str;
        }

        public char[] sortLine()
        {
            if (isNumber == false)
            {
                for (int i = 0; i < str.Length - 1; i++)
                    for (int j = 0; j < str.Length - i - 1; j++)
                    {

                        if (str[j] > str[j + 1] && str[j] != ' ')
                        {
                            char tmp;
                            tmp = str[j];
                            str[j] = str[j + 1];
                            str[j + 1] = tmp;
                        }
                    }
                return str;
            }
            else
            {
                string ex = "Can't sort the line with number\n";
                return ex.ToCharArray();
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            string str = Console.ReadLine();
            char[] arr;
            arr = str.ToCharArray();

            LettersLine a = new LettersLine(arr);

            Console.WriteLine(a.getLine());
            Console.WriteLine(a.getLength());
            Console.WriteLine(a.sortLine());
        }
    }
}
