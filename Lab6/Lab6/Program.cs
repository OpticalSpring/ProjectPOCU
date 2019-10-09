using System;
using System.Diagnostics;

namespace Lab6
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] data = getTestArray();
            printArray(data);
            int[,] rotated = Lab6.Rotate90Degrees(data);
            printArray(rotated);

            Debug.Assert(isArrayEqual(new int[,]
            {
                { 41, 31, 21, 11, 1 },
                { 42, 32, 22, 12, 2 },
                { 43, 33, 23, 13, 3 },
                { 44, 34, 24, 14, 4 },
                { 45, 35, 25, 15, 5 },
                { 46, 36, 26, 16, 6 }
            }, rotated));

            
        }

        private static bool isArrayEqual(int[,] expected, int[,] actual)
        {
            if (expected.GetLength(0) != actual.GetLength(0)
                || expected.GetLength(1) != actual.GetLength(1))
            {
                return false;
            }

            int row = expected.GetLength(0);
            int column = expected.GetLength(1);

            for (int i = 0; i < row; i++)
            {
                for (int j = 0; j < column; j++)
                {
                    if (expected[i, j] != actual[i, j])
                    {
                        return false;
                    }
                }
            }

            return true;
        }

        private static int[,] getTestArray()
        {
            return new int[5, 6]
            {
                { 1, 2, 3, 4, 5, 6 },
                { 11, 12, 13, 14, 15, 16 },
                { 21, 22, 23, 24, 25, 26 },
                { 31, 32, 33, 34, 35, 36 },
                { 41, 42, 43, 44, 45, 46 }
            };
        }

        private static void printArray(int[,] data)
        {
            Console.WriteLine("---------------------------------");

            for (int i = 0; i < data.GetLength(0); i++)
            {
                for (int j = 0; j < data.GetLength(1); j++)
                {
                    Console.Write("{0, -4} ", data[i, j]);
                }

                Console.WriteLine();
            }

            Console.WriteLine("---------------------------------");
        }
    }
}