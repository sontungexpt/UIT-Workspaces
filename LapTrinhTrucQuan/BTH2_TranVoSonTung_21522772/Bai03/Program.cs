namespace Bai03
{
    class Program
    {
        class Offset
        {
            public int X { get; set; }

            public int Y { get; set; }

            public Offset()
            {
                X = 0;
                Y = 0;
            }

            public Offset(int x, int y)
            {
                X = x;
                Y = y;
            }

            public void Show()
            {
                Console.WriteLine($"X = {X}, Y = {Y}");
            }
        }


        static void Main(string[] args)
        {
            //a) Nhập / xuất ma trận hai chiều các số nguyên
            int rowLength;
            int colLength;
            int[,] matrix = ReadMatrix(out rowLength, out colLength);
            int valueFound;
            PrintMatrix(matrix);

            //b.Tìm kiếm một phần tử trong ma trận
            Offset? offsetFound = IndexOf(matrix, out valueFound);

            if (offsetFound != null)
            {
                Console.Write($"Value {valueFound} found at offset ");
                offsetFound.Show();
            }
            else
            {
                Console.WriteLine("Value not found");
            }
            //c. Xuất các phần tử là số nguyên tố
            PrintPrimeNumber(matrix);
            //d. Cho biết dòng nào có nhiều số nguyên tố nhất
            Console.WriteLine("\nThe row has the most prime number is: " + RowHasMostPrimeNumber(matrix));
            Console.WriteLine("Press any key to exit");
        }

        static int[,] ReadMatrix(out int rowLength, out int colLength)
        {
            Console.Write("Input your row length: ");
            rowLength = int.Parse(Console.ReadLine());
            Console.Write("Input your column length: ");
            colLength = int.Parse(Console.ReadLine());
            int[,] matrix = new int[rowLength, colLength];
            for (int rowIndex = 0; rowIndex < rowLength; rowIndex++)
            {
                for (int colIndex = 0; colIndex < colLength; colIndex++)
                {
                    Console.Write($"matrix[{rowIndex},{colIndex}] = ");
                    matrix[rowIndex, colIndex] = int.Parse(Console.ReadLine());
                }
            }
            return matrix;
        }

        static void PrintMatrix(int[,] matrix)
        {
            for (int rowIndex = 0; rowIndex < matrix.GetLength(0); rowIndex++)
            {
                for (int colIndex = 0; colIndex < matrix.GetLength(1); colIndex++)
                {
                    Console.Write($"{matrix[rowIndex, colIndex]} ");
                }
                Console.WriteLine();
            }
        }

        static Offset? IndexOf(int[,] matrix, out int value)
        {
            Console.Write("Enter your value you want to find in matrix: ");
            value = int.Parse(Console.ReadLine());
            for (int rowIndex = 0; rowIndex < matrix.GetLength(0); rowIndex++)
            {
                for (int colIndex = 0; colIndex < matrix.GetLength(1); colIndex++)
                {
                    if (matrix[rowIndex, colIndex] == value)
                    {
                        return new Offset(rowIndex, colIndex);
                    }
                }
            }
            return null;
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

        //print the prime number in matrix
        static void PrintPrimeNumber(int[,] matrix)
        {
            Console.Write("The prime number in matrix is: ");
            for (int rowIndex = 0; rowIndex < matrix.GetLength(0); rowIndex++)
            {
                for (int colIndex = 0; colIndex < matrix.GetLength(1); colIndex++)
                {
                    if (IsPrimeNumber(matrix[rowIndex, colIndex]))
                    {
                        Console.Write($"{matrix[rowIndex, colIndex]} ");
                    }
                }
            }
        }

        static int CountPrimeNumberRow(int[,] matrix, int row)
        {
            int count = 0;
            for (int i = 0; i < matrix.GetLength(1); i++)
            {
                if (IsPrimeNumber(matrix[row, i]))
                {
                    count++;
                }
            }
            return count;
        }

        static int RowHasMostPrimeNumber(int[,] matrix)
        {
            int max = CountPrimeNumberRow(matrix, 0);
            int maxRow = 0;
            for (int i = 1; i < matrix.GetLength(0); i++)
            {
                int count = CountPrimeNumberRow(matrix, i);
                if (count > max)
                {
                    max = count;
                    maxRow = i;
                }
            }
            return maxRow;
        }
    }

}

