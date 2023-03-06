using System.Text;

namespace Bai01
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.OutputEncoding = Encoding.UTF8;
            Console.InputEncoding = Encoding.UTF8;
            PrintCalendar();
        }

        static DateTime ReadMonthYear()
        {
            int month;
            int year;
            Console.Write("Enter month: ");
            month = int.Parse(Console.ReadLine());
            Console.Write("Enter year: ");
            year = int.Parse(Console.ReadLine());
            return new DateTime(year, month, 1);
        }
        static void PrintCalendar()
        {
            DateTime date = ReadMonthYear();
            int dayInMonth = DateTime.DaysInMonth(date.Year, date.Month);
            
            //print the calendar
            Console.WriteLine("Sun\tMon\tTue\tWed\tThu\tFri\tSat");
            Console.WriteLine();
            int fistDayIndex = (int)date.DayOfWeek;
            int day = 1;
            while(day <= dayInMonth)
            {
                if (fistDayIndex > 0)
                {
                    Console.Write("\t");
                    fistDayIndex--;
                }
                else
                {
                    Console.Write($"{day++}\t");
                    if ((int)date.DayOfWeek == 6)
                        Console.WriteLine();
                    date = date.AddDays(1);
                }
            }
        }
    }
}






