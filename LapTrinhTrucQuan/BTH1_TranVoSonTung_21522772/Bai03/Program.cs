namespace Bai03
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

        public static bool IsDayValid()
        {
            int[] dayInMonth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
            if (IsLeapYear())
                dayInMonth[1] = 29;
            if (!IsMonthValid())
                throw new Exception("Canot check day because month is invalid");
            if (Day > 0 && Day < dayInMonth[Month - 1])
                return true;
            return false;
        }

        public static void CheckValid()
        {
            try
            {
                if (!IsYearValid())
                    Console.WriteLine("Year is invalid");
                if (!IsMonthValid())
                    Console.WriteLine("Month is invalid");
                if (!IsDayValid())
                    throw new Exception("Day is invalid");
                Console.WriteLine("Date is valid");
            }
            catch (Exception exception)
            {
                Console.WriteLine(exception.Message);
            }
        }
    }

    class Bai03
    {
        static void Main(string[] args)
        {

            DateTime.Init();
            DateTime.CheckValid();
            Console.ReadKey();
        }
    }
}
