using System;

namespace Bai05
{
    class Bai05
    {
        static void Main(string[] args)
        {
            int day;
            int month;
            int year;
            ReadDateTime(out day, out month, out year);
            try
            {
                DateTime datetime = new DateTime(day, month, year);
                Console.WriteLine(datetime.DayOfWeek.ToString());
            }
            catch (Exception e)
            {
                Console.WriteLine("Year, month, or day is invalid");
            }

        }
        private static int ReadInteger()
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

        public static void ReadDateTime(out int day, out int month, out int year)
        {
            Console.WriteLine("Enter day:");
            day = ReadInteger();
            Console.WriteLine("Enter month:");
            month = ReadInteger();
            Console.WriteLine("Enter year:");
            year = ReadInteger();
        }
    }
}
