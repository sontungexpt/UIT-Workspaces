using System;

namespace Bai01
{
    class Bai01
    {
        static void Main(string[] args)
        {
            int row;
            int column;
            int[,] intergerMatrix;
            int rowRemove;
            ReadRandomMatrix(out intergerMatrix, out row, out column);

            PrintMatrix(intergerMatrix);

            Console.WriteLine("Max value in matrix is: " + FindMaxValue(intergerMatrix));

            Console.WriteLine("Min value in matrix is: " + FindMinValue(intergerMatrix));

            Console.WriteLine("The row with sum of elements is max is: " + FindRowWithMaxSum(intergerMatrix));

            Console.WriteLine("The sum of not prime number in matrix is: " + SumOfNotPrimeNumber(intergerMatrix));

            RemoveRow(ref intergerMatrix, out rowRemove);

            Console.WriteLine("The matrix after remove row " + rowRemove);

            PrintMatrix(intergerMatrix);

            Console.WriteLine("The matrix after remove column which has max value");

            RemoveCol(ref intergerMatrix, ColIndexOfMaxValue(intergerMatrix));

            PrintMatrix(intergerMatrix);

            Console.ReadKey();
        }

        static void ReadRandomMatrix(out int[,] matrix, out int row, out int col)
        {
            Console.WriteLine("Enter the row of integer matrix");
            row = ReadInteger();
            Console.WriteLine("Enter the column of integer matrix");
            col = ReadInteger();
            matrix = new int[row, col];
            Random random = new Random();
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                    matrix[i, j] = random.Next(0, 100);
            }
        }


        static void PrintMatrix(int[,] matrix)
        {
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            Console.WriteLine("The matrix is: ");
            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                    Console.Write(matrix[i, j] + "\t");
                Console.WriteLine();
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
        //Find max value in matrix
        static int FindMaxValue(int[,] matrix)
        {
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            int max = matrix[0, 0];

            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                {
                    if (matrix[i, j] > max)
                    {
                        max = matrix[i, j];
                    }
                }
            }
            return max;
        }

        //Find min value in matrix
        static int FindMinValue(int[,] matrix)
        {
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            int min = matrix[0, 0];
            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                {
                    if (matrix[i, j] < min)
                    {
                        min = matrix[i, j];
                    }
                }
            }
            return min;
        }

        //Find index of max value in matrix
        static int ColIndexOfMaxValue(int[,] matrix)
        {
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            int max = matrix[0, 0];
            int colIndex = 0;
            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                {
                    if (matrix[i, j] > max)
                    {
                        max = matrix[i, j];
                        colIndex = j;
                    }
                }
            }
            return colIndex;
        }

        //Find the row with the max sum of elements
        static int FindRowWithMaxSum(int[,] matrix)
        {
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            int max = 0;
            int index = 0;
            for (int i = 0; i < rowLength; i++)
            {
                int sum = 0;
                for (int j = 0; j < colLength; j++)
                {
                    sum += matrix[i, j];
                }
                if (sum > max)
                {
                    max = sum;
                    index = i;
                }
            }
            return index;
        }

        //calcultae sum of not prime number in matrix
        static int SumOfNotPrimeNumber(int[,] matrix)
        {
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            int sum = 0;
            for (int i = 0; i < rowLength; i++)
            {
                for (int j = 0; j < colLength; j++)
                {
                    if (!IsPrimeNumber(matrix[i, j]))
                    {
                        sum += matrix[i, j];
                    }
                }
            }
            return sum;
        }

        //remove row in matrix
        static void RemoveRow(ref int[,] matrix, out int row)
        {
            Console.WriteLine("Enter the row you want to remove");
            row = ReadInteger();
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            int[,] newMatrix = new int[rowLength - 1, colLength];
            int newRowIndex = 0;

            for (int i = 0; i < rowLength; i++)
            {
                if (i != row)
                {
                    for (int j = 0; j < colLength; j++)
                    {
                        newMatrix[newRowIndex, j] = matrix[i, j];
                    }
                    newRowIndex++;
                }
            }
            matrix = newMatrix;
        }

        //remove col in matrix
        static void RemoveCol(ref int[,] matrix, int col)
        {
            int rowLength = matrix.GetLength(0);
            int colLength = matrix.GetLength(1);
            int[,] newMatrix = new int[rowLength, colLength - 1];
            int newColIndex = 0;

            for (int i = 0; i < colLength; i++)
            {
                if (i != col)
                {
                    for (int j = 0; j < rowLength; j++)
                    {
                        newMatrix[j, newColIndex] = matrix[j, i];
                    }
                    newColIndex++;
                }
            }
            matrix = newMatrix;
        }
    }
}
