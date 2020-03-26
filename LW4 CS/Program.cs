using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LW4_CS
{
    class MyClass
    {
        private char[] str;

        public MyClass()
        {

        }
        public MyClass(char[] str)
        {
            this.str = str;
        }

        public MyClass(MyClass other)
        {
            this.str = other.str;
        }

        public char[] getLine()
        {
            return str;
        }

        public int getLength()
        {
            return str.Length;
        }

        public int getSize(MyClass obj, char symbol)
        {
            int Size=obj.str.Length;
            for (int i = 0; i < obj.str.Length; i++)
                if (obj.str[i] == symbol)
                    Size = obj.str.Length - 1;
            return Size;
        }
        public static MyClass operator-(MyClass obj, char symbol)
        {
            MyClass a = new MyClass();
            int size = obj.getSize(obj, symbol);
            char[] tmp = new char[size];
            int k = 0;
            for (int i = 0; i < obj.str.Length; i++)
            {
                if (obj.str[i] != symbol)
                    tmp[i-k] = obj.str[i];
                else
                    k++;
            }
            a.str = tmp;
            return a;
        }

        public static MyClass operator+(MyClass obj1, MyClass obj2)
        {
            MyClass c = new MyClass();
            string txt1 = new string(obj1.str);
            string txt2 = new string(obj2.str);
            string result = Convert.ToString(Convert.ToInt32(txt1) + Convert.ToInt32(txt2));
            char[] arr;
            arr = result.ToCharArray();
            c.str = arr;
            return c;
        }
    }


    class Program
    {
        static void Main(string[] args)
        {
            string str1 = Console.ReadLine();
            string str2 = Console.ReadLine();
            char[] arr1;
            char[] arr2;
            arr1 = str1.ToCharArray();
            arr2 = str2.ToCharArray();

            MyClass a = new MyClass(arr1);
            MyClass b = new MyClass(arr2);
            MyClass c = new MyClass(a+b);

            Console.WriteLine(a.getLine());
            Console.WriteLine(a.getLength());
            a = a - '5';
            Console.WriteLine(a.getLine());
            Console.WriteLine(c.getLine());
        }
    }
}
