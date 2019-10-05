using System;
using System.Collections.Generic;
using System.Text;

namespace Assignment2
{
    class Canvas
    {
        public enum EShape
        {
            Rectangle,
            IsoscelesRightTriangle,
            IsoscelesTriangle,
            Circle
        }


        public static char[,] Draw(uint width, uint height, EShape shape)
        {
            uint widthAll = width + 4;
            uint heightAll = height + 4;
            uint wV = 0;
            char[,] shapeValue = new char[heightAll, widthAll];
            if (width == 0 || height == 0)
            {
                return new char[0, 0];
            }
            for (uint i = 0; i < heightAll; i++)
            {
                for (uint j = 0; j < widthAll; j++)
                {
                    shapeValue[i, j] = ' ';
                }
            }
            switch (shape)
            {
                case EShape.Rectangle:
                    for (uint i = 0; i < heightAll; i++)
                    {
                        for (uint j = 0; j < widthAll; j++)
                        {
                            if (i == 0 || i == heightAll - 1)
                            {
                                shapeValue[i, j] = '-';
                            }
                            else if (j == 0 || j == widthAll - 1)
                            {
                                shapeValue[i, j] = '|';
                            }

                            if (i > 1 && i < heightAll - 2 && j > 1 && j < widthAll - 2)
                            {
                                shapeValue[i, j] = '*';
                            }
                        }
                    }
                    break;
                case EShape.IsoscelesRightTriangle:
                    if (width != height)
                    {
                        return new char[0, 0];
                    }
                    for (int i = 0; i < heightAll; i++)
                    {

                        for (uint j = 0; j < widthAll; j++)
                        {
                            if (i == 0 || i == heightAll - 1)
                            {
                                shapeValue[i, j] = '-';
                            }
                            else if (j == 0 || j == widthAll - 1)
                            {
                                shapeValue[i, j] = '|';
                            }


                        }
                        for (uint j = 0; j < wV + 1; j++)
                        {
                            if (i > 1 && i < heightAll - 2 && j > 1 && j < widthAll - 2)
                            {
                                shapeValue[i, j] = '*';
                            }
                        }
                        wV++;

                    }
                    break;
                case EShape.IsoscelesTriangle:
                    if (width != height * 2 - 1)
                    {
                        return new char[0, 0];
                    }

                    
                    for (uint i = 0; i < heightAll; i++)
                    {

                        for (uint j = 0; j < widthAll; j++)
                        {
                            if (i == 0 || i == heightAll - 1)
                            {
                                shapeValue[i, j] = '-';
                            }
                            else if (j == 0 || j == widthAll - 1)
                            {
                                shapeValue[i, j] = '|';
                            }


                        }
                        if (i > 1 && i < heightAll - 2)
                        {
                            for (uint j = widthAll / 2 - wV; j < widthAll / 2 + wV + 1; j++)
                            {
                                shapeValue[i, j] = '*';
                            }
                            wV++;
                        }
                    }
                    break;
                case EShape.Circle:
                    if (width % 2 == 0)
                    {
                        return new char[0, 0];
                    }
                    if (width != height)
                    {
                        return new char[0, 0];
                    }
                    for (uint i = 0; i < heightAll; i++)
                    {

                        for (uint j = 0; j < widthAll; j++)
                        {
                            if (i == 0 || i == heightAll - 1)
                            {
                                shapeValue[i, j] = '-';
                            }
                            else if (j == 0 || j == widthAll - 1)
                            {
                                shapeValue[i, j] = '|';
                            }

                            int xLen = (int)Math.Abs(widthAll / 2 - i);
                            int yLen = (int)Math.Abs(heightAll / 2 - j);
                            if (xLen * xLen + yLen * yLen <= (width / 2) * (width / 2))
                            {
                                shapeValue[i, j] = '*';
                            }
                        }
                    }
                    break;
            }




            return shapeValue;
        }

        internal static bool IsShape(char[,] canvas, EShape shape)
        {
            char[,] newCanvas = Draw((uint)canvas.GetLength(1) - 4, (uint)canvas.GetLength(0) - 4, shape);
            if (newCanvas.GetLength(0) == 0)
            {
                return false;
            }
            int count = 0;
            for (int i = 0; i < canvas.GetLength(0); i++)
            {
                for (int j = 0; j < canvas.GetLength(1); j++)
                {
                    if (canvas[i, j] != newCanvas[i, j])
                    {
                        count++;
                    }
                }
            }
            Console.WriteLine("{0}, {1}, count : {2}, shape : {3}", (uint)canvas.GetLength(0), (uint)canvas.GetLength(1), count, shape);
            if (count > 0)
            {
                return false;
            }
            else
            {
                return true;
            }
        }
    }
}
