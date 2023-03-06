namespace Bai02
{
    class Bai02
    {
        static void Main(string[] args)
        {
            int n;
            Console.WriteLine("The sum of prime number less than n is: " + GetSumPrimeLessThanX(out n));
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

        static int GetSumPrimeLessThanX(out int x)
        {
            Console.WriteLine("Enter n: ");
            x = ReadInteger();
            int sum = 0;
            for (int i = 2; i < x; i++)
            {
                if (IsPrimeNumber(i) && i < x)
                    sum += i;
            }
            return sum;
        }
    }
}