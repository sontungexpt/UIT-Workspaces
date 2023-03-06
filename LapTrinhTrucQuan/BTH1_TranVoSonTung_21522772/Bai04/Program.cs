namespace Bai04
{


    public static class DateTime
    {
        public static int Day { get; set; }
        public static int Month { get; set; }
        public static int Year { get; set; }

        static DateTime()
        {
            Day = 1;
            Month = 1;
            Year = 2000;
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

        public static void Init()
        {
            Console.WriteLine("Enter day:");
            Day = ReadInteger();
            Console.WriteLine("Enter month:");
            Month = ReadInteger();
            Console.WriteLine("Enter year:");
            Year = ReadInteger();
        }

        public static void InitMonthYear()
        {
            Console.WriteLine("Enter month:");
            Month = ReadInteger();
            Console.WriteLine("Enter year:");
            Year = ReadInteger();
        }

        public static bool IsLeapYear()
        {
            if (Year % 400 == 0)
                return true;
            else if (Year % 4 == 0 && Year % 100 != 0)
                return true;
            return false;
        }

        public static bool IsYearValid()
        {
            if (Year > 0)
                return true;
            return false;
        }

        public static bool IsMonthValid()
        {
            if (Month > 0 && Month < 13)
                return true;
            return false;
        }

        public static int DayInMonth()
        {
            if (IsYearValid() && IsMonthValid())
            {
                int[] dayInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
                if (IsLeapYear())
                    dayInMonth[1] = 29;
                return dayInMonth[Month - 1];
            }
            return 0;
        }
    }

    class Bai04
    {
        static void Main(string[] args)
        {

            DateTime.InitMonthYear();
            Console.WriteLine(DateTime.DayInMonth() == 0 ?
                "Cannot find day in month because month or year is invalid" :
                DateTime.DayInMonth().ToString());
            Console.ReadKey();
        }
    }
}
