using System;
using System.Diagnostics;

namespace Lab2
{
    class Program
    {
        static void Main(string[] args)
        {
            int num1 = 4;
            int num2 = 5;
            int num3 = 2;
            int num4 = 6;

            int sum = Lab2.GetSum(num1, num2, num3, num4);

            Console.WriteLine(sum);
            Debug.Assert(sum == 17);

            double average = Lab2.GetAverage(num1, num2, num3, num4);

            Console.WriteLine(average);
            Debug.Assert(average == 4.25);

            int product = Lab2.Multiply(num1, num2);

            Console.WriteLine(product);
            Debug.Assert(product == 20);

            int difference = Lab2.Subtract(num1, num2);

            Console.WriteLine(difference);
            Debug.Assert(difference == -1);

            string s1 = "First string";
            string s2 = " Second string";
            string combinedString = Lab2.CombineStrings(s1, s2);

            Console.WriteLine(combinedString);
            Debug.Assert(combinedString == "First string Second string");
        }
    }
}