using System;
using System.Collections.Generic;
using System.Text;

namespace Lab10
{
    class Circle
    {
        public uint Radius { get; private set; }
        public uint Diameter { get; private set; }

        public Circle(uint radius)
        {
            Radius = radius;
            Diameter = radius * 2;
        }

        public double GetCircumference()
        {
            double returnValue = Diameter * Math.PI;
            returnValue = Math.Round(returnValue * 1000) / 1000;
            Console.WriteLine(returnValue);
            return returnValue;
        }

        public double GetArea()
        {
            double returnValue = Radius * Radius * Math.PI;
            returnValue = Math.Round(returnValue * 1000) / 1000;
            Console.WriteLine(returnValue);
            return returnValue;
        }
    }
}
