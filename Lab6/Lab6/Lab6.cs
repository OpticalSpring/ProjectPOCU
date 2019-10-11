using System;
using System.Diagnostics;

namespace Lab6
{
    public static class Lab6
    {
        public static int[,] Rotate90Degrees(int[,] data)
        {
            int[,] rData = new int[data.GetLength(1), data.GetLength(0)];
            for (int i = 0; i < data.GetLength(1); i++)
            {
                for (int j = 0; j < data.GetLength(0); j++)
                {
                    rData[i, j] = data[data.GetLength(0) - j - 1, i];
                }
            }
            return rData;
        }

        public static void TransformArray(int[,] data, EMode mode)
        {
            int[,] rData = new int[data.GetLength(0), data.GetLength(1)];
            for (int i = 0; i < data.GetLength(0); i++)
            {
                for (int j = 0; j < data.GetLength(1); j++)
                {
                    switch (mode)
                    {
                        case EMode.HorizontalMirror:
                            rData[i, j] = data[i, data.GetLength(1) - 1 - j];
                            break;
                        case EMode.VerticalMirror:
                            rData[i, j] = data[data.GetLength(0) - 1 - i, j];
                            break;
                        case EMode.DiagonalShift:
                            if (i == 0 && j == 0)
                            {
                                rData[i, j] = data[data.GetLength(0) - 1, data.GetLength(1) - 1];
                            }
                            else if (i == 0)
                            {
                                rData[i, j] = data[data.GetLength(0) - 1, j - 1];
                            }
                            else if (j == 0)
                            {
                                rData[i, j] = data[i - 1, data.GetLength(1) - 1];
                            }
                            else
                            {
                                rData[i, j] = data[i - 1, j - 1];
                            }
                            break;
                    }
                }
            }
            for (int i = 0; i < data.GetLength(0); i++)
            {
                for (int j = 0; j < data.GetLength(1); j++)
                {
                    data[i, j] = rData[i, j];
                }
            }
        }
    }

}
