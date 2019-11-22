using System;
using System.Collections.Generic;
using System.Text;

namespace Lab10
{
    class Rectangle
    {
        public uint Width { get; set; }
        public uint Height { get; set; }

        public Rectangle(uint width, uint height)
        {
            Width = width;
            Height = height;
        }

        public double GetPerimeter()
        {
            double returnValue = Width * 2 + Height * 2;
            returnValue = Math.Round(returnValue * 1000) / 1000;
            Console.WriteLine(returnValue);
            return returnValue;
        }

        public double GetArea()
        {
            double returnValue = Width * Height;
            returnValue = Math.Round(returnValue * 1000) / 1000;
            Console.WriteLine(returnValue);
            return returnValue;
        }
    }
}
