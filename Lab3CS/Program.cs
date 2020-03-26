using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab3CS
{
    class Program
    {

        static void Main(string[] args)
        {
            int size = Convert.ToInt32(Console.ReadLine());
            int[,] arr = new int[size, size+1];

            for (int i = 0; i < size; i++)
                for (int j = 0; j < size+1; j++)
                    arr[i, j] = Convert.ToInt32(Console.ReadLine());

            ArrayTwo b = new ArrayTwo(size, size+1, arr);
            b.GetArray();
            Console.WriteLine(b[0]);
            Console.WriteLine(b.Sum()); 
        }
    }

    public class ArrayTwo
    {
        private int n, m;
        private int[,] arr;
        public ArrayTwo(int n, int m, int[,] arr)
        {
            this.arr = arr;
            this.n = n;
            this.m = m;
        }

        public void GetArray()
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < m; j++)
                    Console.Write(arr[i, j] + " ");
                Console.WriteLine();
            }
        }

        public int Sum()

        {   int s = 0;
            for (int i = 0; i < n; i++)
            {
                
                for (int j = 0; j < m; j++)
                    s += arr[i, j];
            }
            return s;
        }

        public double this[int index]
        {
            get
            {
                double s = 0;
                for (int j = 0; j < m; j++)
                   s += arr[index, j]*arr[index, j];
                return Math.Sqrt(s/m);
            }
        }
    }
}

