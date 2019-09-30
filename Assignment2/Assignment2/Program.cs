using System;
using System.Diagnostics;
using static Assignment2.Canvas;

namespace Assignment2
{
    class Program
    {
        static void Main(string[] args)
        {
            char[,] canvas = Canvas.Draw(10, 8, EShape.Rectangle);
            printCanvas(canvas);

            canvas = Canvas.Draw(10, 10, EShape.IsoscelesRightTriangle);
            printCanvas(canvas);

            canvas = Canvas.Draw(9, 5, EShape.IsoscelesTriangle);
            printCanvas(canvas);

            canvas = Canvas.Draw(21, 21, EShape.Circle);
            printCanvas(canvas);

        }
        private static void printCanvas(char[,] canvas)
        {
            for (int i = 0; i < canvas.GetLength(0); i++)
            {
                for (int j = 0; j < canvas.GetLength(1); j++)
                {
                    Console.Write(canvas[i, j]);
                }

                Console.WriteLine();
            }
        }
    }
}