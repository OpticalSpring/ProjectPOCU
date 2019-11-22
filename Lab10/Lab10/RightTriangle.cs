using System;
using System.Collections.Generic;
using System.Text;

namespace Lab10
{
    class RightTriangle
    {
        public uint Width;
        public uint Height;

        public RightTriangle(uint width, uint height)
        {
            Width = width;
            Height = height;
        }

        public double GetPerimeter()
        {
            double returnValue = Width + Height + Math.Sqrt(Width * Width + Height * Height);
            returnValue = Math.Round(returnValue * 10000) / 10000;
            return returnValue;
        }

        public double GetArea()
        {
            double returnValue = Width * Height * 0.5f;
            returnValue = Math.Round(returnValue * 10000) / 10000;
            return returnValue;
        }
    }
}
