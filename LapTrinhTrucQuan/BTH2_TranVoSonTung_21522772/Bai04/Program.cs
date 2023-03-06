using System;

namespace Bai04
{
    public class Fraction
    {
        int _numerator;
        int _denominator;

        public Fraction()
        {
            _numerator = 0;
            _denominator = 1;
        }

        public Fraction(int numerator, int denominator)
        {
            _numerator = numerator;
            _denominator = denominator;
        }

        public int Numerator
        {
            get
            {
                return _numerator;
            }

            set
            {
                _numerator = value;
            }
        }

        public int Denominator
        {
            get
            {
                return _denominator;
            }
            set
            {
                if (value == 0)
                    throw new DivideByZeroException("Denominator cannot be zero");
                _denominator = value;
            }
        }

        public static Fraction operator +(Fraction a) => a;
        public static Fraction operator -(Fraction a) => new(-a._numerator, a._denominator);

        public static Fraction operator +(Fraction a, Fraction b)
            => new (a._numerator * b._denominator + b._numerator * a._denominator, a._denominator * b._denominator);

        public static Fraction operator -(Fraction a, Fraction b)
            => a + (-b);

        public static Fraction operator *(Fraction a, Fraction b)
            => new (a._numerator * b._numerator, a._denominator * b._denominator);

        public static Fraction operator /(Fraction a, Fraction b)
        {
            if (b._numerator == 0)
            {
                throw new DivideByZeroException();
            }
            return new (a._numerator * b._denominator, a._denominator * b._numerator);
        }

        public static bool operator ==(Fraction a, Fraction b)
            => a._numerator * b._denominator == b._numerator * a._denominator;
        public static bool operator !=(Fraction a, Fraction b)
            => !(a == b);
        public static bool operator >(Fraction a, Fraction b)
            => a._numerator * b._denominator > b._numerator * a._denominator;
        public static bool operator <(Fraction a, Fraction b)
            => a._numerator * b._denominator < b._numerator * a._denominator;
        public static bool operator >=(Fraction a, Fraction b)
            => a._numerator * b._denominator >= b._numerator * a._denominator;
        public static bool operator <=(Fraction a, Fraction b)
            => a._numerator * b._denominator <= b._numerator * a._denominator;


        public override string ToString() => $"{_numerator} / {_denominator}";

        public override bool Equals(object obj)
        {
            if (obj == null)
                return false;
            if (obj is Fraction f)
            {
                return this == f;
            }
            return false;
        }
        
        

        public void Input()
        {
            Console.Write("Enter numerator: ");
            _numerator = int.Parse(Console.ReadLine());
            Console.Write("Enter denominator: ");
            _denominator = int.Parse(Console.ReadLine());
        }
        public void Output() => Console.WriteLine(this.ToString());

        public override int GetHashCode()
        {
            throw new NotImplementedException();
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            try
            {
                //Read two fractions
                Fraction a = new ();
                Fraction b = new ();
                Console.WriteLine("Enter fraction a: ");
                a.Input();
                Console.WriteLine("Enter fraction b: ");
                b.Input();

                //calculate sum, different, product, quotient
                Fraction sum = a + b;
                Fraction diff = a - b;
                Fraction product = a * b;
                Fraction quotient = a / b;
                //print result
                Console.WriteLine("Sum: " + sum);
                Console.WriteLine("Diff: " + diff);
                Console.WriteLine("Product: " + product);
                Console.WriteLine("Quotient: " + quotient);

                //input the list of fractions
                Fraction[] fractions = Input();
                Console.Write("The Max Fraction is: ");
                Console.WriteLine(Max(fractions));
                //sort the fractions
                Sort(fractions);
                Console.WriteLine("The sorted fractions are: ");
                Output(fractions);

            }
            catch (OutOfMemoryException e)
            {
                Console.WriteLine(e.Message);
            }
            catch (Exception e)
            {
                Console.WriteLine(e.Message);
            }
        }

        static Fraction[] Input()
        {
            Console.Write("Enter number of fractions: ");
            int n = int.Parse(Console.ReadLine());
            if (n < 0)
                throw new Exception("Number of fractions must be greater than 0");
            var fractions = new Fraction[n];
            if (fractions == null)
                throw new OutOfMemoryException("Cannot allocate memory");
            for (int i = 0; i < n; i++)
            {
                Console.WriteLine("Enter fraction " + i);
                fractions[i] = new Fraction();
                fractions[i].Input();
            }
            return fractions;

        }
        static void Output(Fraction[] fractions)
        {
            foreach (Fraction fraction in fractions)
            {
                fraction.Output();
            }
        }

        //find the max fraction in list
        static Fraction Max(Fraction[] fractions)
        {
            Fraction max = fractions[0];
            for (int i = 1; i < fractions.Length; i++)
            {
                if (fractions[i] > max)
                {
                    max = fractions[i];
                }
            }
            return max;
        }

        //sort the fraction list in ascending order
        static void Sort(Fraction[] fractions)
        {
            for (int i = 0; i < fractions.Length - 1; i++)
            {
                for (int j = i + 1; j < fractions.Length; j++)
                {
                    if (fractions[i] > fractions[j])
                    {
                        (fractions[j], fractions[i]) = (fractions[i], fractions[j]);
                    }
                }
            }
        }
    }
}