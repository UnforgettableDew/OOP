using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LW5._2
{
    class Program
    {
        abstract class Figure
        {
            public abstract double getSquare();
            public abstract double getLength();
        }

        class Circle : Figure
        {
            private double radius;

            public Circle(float radius)
            {
                this.radius = radius;
            }

            public override double getLength()
            {
                return 2 * Math.PI * radius;
            }

            public override double getSquare()
            {
                return Math.PI * Math.Sqrt(radius);
            }

            class Ellipse : Figure
            {
                private double a, b;

                public Ellipse(double a, double b)
                {
                    this.a = a;
                    this.b = b;
                }

                public override double getLength()
                {
                    return Math.PI * (a + b);
                }

                public override double getSquare()
                {
                    return Math.PI * a * b;
                }
            }
            static void Main(string[] args)
            {
                Ellipse a = new Ellipse(4, 5);
                Circle b = new Circle(5);

                Console.WriteLine(a.getLength());
                Console.WriteLine(a.getSquare());

                Console.WriteLine(b.getLength());
                Console.WriteLine(b.getSquare());
            }
        }
    }
}
