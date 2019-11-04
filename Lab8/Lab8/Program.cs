using System;
using System.Diagnostics;

namespace Lab8
{
    class Program
    {
        static void Main(string[] args)
        {
            string minifiedList = " ";
            string list = Lab8.PrettifyList(minifiedList);
            Debug.Assert(null == list);

            minifiedList = "";
            list = Lab8.PrettifyList(minifiedList);
            Debug.Assert(null == list);

            minifiedList = "             ";
            list = Lab8.PrettifyList(minifiedList);
            Debug.Assert(null == list);

            minifiedList = null;
            list = Lab8.PrettifyList(minifiedList);
            Debug.Assert(null == list);

        }
    }
}