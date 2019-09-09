using System;
using System.Collections.Generic;
using System.Text;

namespace Lab2
{
    public static class Lab2
    {
        public static int GetSum(int num1, int num2, int num3, int num4)
        {
            int sum;
            sum = num1 + num2 + num3 + num4;
            return sum;
        }

        public static double GetAverage(int num1, int num2, int num3, int num4)
        {
            int sum = GetSum(num1, num2, num3, num4);
            return sum / 4;
        }

        public static int Multiply(int num1, int num2)
        {
            int product = num1 * num2;
            return product;
        }

        public static int Subtract(int num1, int num2)
        {
            return num1 - num2;
        }

        public static int CombineStrings(string s1, string s2)
        {
            string result = s1 + s2;
            return result;
        }
    }
}