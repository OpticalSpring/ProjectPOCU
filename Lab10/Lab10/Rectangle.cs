using System;
using System.Collections.Generic;
using System.Text;

namespace Lab10
{
    class Rectangle
    {
        public uint Width;
        public uint Height;

        public Rectangle(uint width, uint height)
        {
            Width = width;
            Height = height;
        }

        public double GetPerimeter()
        {
            double returnValue = Width * 2 + Height * 2;
            returnValue = Math.Round(returnValue * 10000) / 10000;
            return returnValue;
        }

        public double GetArea()
        {
            double returnValue = Width * Height;
            returnValue = Math.Round(returnValue * 10000) / 10000;
            return returnValue;
        }
    }
}
