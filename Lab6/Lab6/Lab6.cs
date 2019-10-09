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
                    rData[i, j] = data[data.GetLength(0)-j-1, i];
                }
            }
            return rData;
        }

        public static void TransformArray(int[] data)
        {

        }
    }
    
}
