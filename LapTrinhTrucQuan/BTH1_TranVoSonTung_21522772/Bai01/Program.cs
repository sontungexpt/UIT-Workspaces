using System;

namespace Bai01
{
    class Bai01
    {
        static void Main(string[] args)
        {
            int amount;
            int[] integers;

            ReadRandomArray(out integers, out amount);

            PrintArray(integers);

            Console.WriteLine("The sum of the odd member in array is: " + GetSumOdd(integers));

            Console.WriteLine("The count of the prime member in array is: " + CountPrimeNumber(integers));

            Console.WriteLine("The index of the min square member in array is: " + FindMinSquareNumber(integers));

            Console.ReadKey();
        }

        static void ReadRandomArray(out int[] array, out int amount)
        {
            Console.WriteLine("Enter the numbers of integer array");
            amount = ReadInteger();
            array = new int[amount];
            Random random = new Random();
            int arrayLength = array.Length;
            for (int i = 0; i < arrayLength; i++)
            {
                array[i] = random.Next(0, 100);
            }
        }

        static void ReadArray(out int[] array, out int amount)
        {
            Console.WriteLine("Enter the numbers of integer array");
            amount = ReadInteger();
            array = new int[amount];
            int arrayLength = array.Length;
            for (int i = 0; i < arrayLength; i++)
            {
                Console.WriteLine($"Enter the array [{i}]");
                array[i] = ReadInteger();
            }
        }

        static void PrintArray(int[] array)
        {
            int arrayLength = array.Length;
            Console.WriteLine("The array is: ");
            for (int i = 0; i < arrayLength; i++)
            {
                Console.WriteLine($"Array[{i}]: {array[i]}");
            }
        }

        static int ReadInteger()
        {
            int result = 0;
            bool success;
            Console.Write(@"Enter the interger: ");
            do
            {
                try
                {
                    success = true;
                    result = int.Parse(Console.ReadLine());
                }
                catch (Exception exception)
                {
                    success = false;
                    Console.WriteLine(exception.Message);
                    Console.Write(@"Please enter the integer again: ");
                }
            } while (!success);
            return result;
        }

        static int GetSumOdd(int[] integers)
        {
            int sum = 0;
            foreach (int integer in integers)
            {
                if (integer % 2 != 0)
                    sum += integer;
            }
            return sum;

        }

        static bool IsPrimeNumber(int integer)
        {
            if (integer <= 1)
                return false;
            else
            {
                for (int i = 2; i <= integer / 2; i++)
                {
                    if (integer % i == 0)
                        return false;
                }
                return true;
            }
        }

        static int CountPrimeNumber(int[] integers)
        {
            int count = 0;
            foreach (int integer in integers)
            {
                if (IsPrimeNumber(integer))
                    count++;
            }
            return count;
        }

        static bool IsSquareNumber(int integer)
        {
            for (int i = 1; i * i <= integer; i++)
            {
                if (i * i == integer)
                    return true;
            }
            return false;
        }

        static int? FindMinSquareNumber(int[] integers)
        {
            int min = int.MaxValue;
            int index = 0;
            int length = integers.Length;
            for (int i = 0; i < length; i++)
            {
                if (IsSquareNumber(integers[i]) && integers[i] < min)
                {
                    min = integers[i];
                    index = i;
                }
            }
            if (min != int.MaxValue)
                return index; // return index of min square number
            return -1; // not found
        }
    }
}
