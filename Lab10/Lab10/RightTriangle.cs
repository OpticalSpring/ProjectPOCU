using System;
using System.Collections.Generic;
using System.Text;

namespace Lab10
{
    class RightTriangle
    {
        public uint Width { get; private set; }
        public uint Height { get; private set; }

        public RightTriangle(uint width, uint height)
        {
            Width = width;
            Height = height;
        }

        public double GetPerimeter()
        {
            double returnValue = Width + Height + Math.Sqrt(Width * Width + Height * Height);
            returnValue = Math.Round(returnValue * 1000) / 1000;
            Console.WriteLine(returnValue);
            return returnValue;
        }

        public double GetArea()
        {
            double returnValue = Width * Height * 0.5f;
            returnValue = Math.Round(returnValue * 1000) / 1000;
            Console.WriteLine(returnValue);
            return returnValue;
        }
    }
}
