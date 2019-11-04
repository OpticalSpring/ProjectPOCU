using System;
using System.Diagnostics;

namespace Lab8
{
    class Program
    {
        static void Main(string[] args)
        {
            string minifiedList = "Apple|Orange|Banana";
            string prettifiedList = @"1) Apple
2) Orange
3) Banana
";
            string list = Lab8.PrettifyList(minifiedList);
            Console.WriteLine(list);
            Debug.Assert(prettifiedList == list);

            Console.WriteLine("---------------------------------");

            minifiedList = "Apple_Fuji_Gala|Orange|Banana_Baby_Cavendish";
            prettifiedList = @"1) Apple
    a) Fuji
    b) Gala
2) Orange
3) Banana
    a) Baby
    b) Cavendish
";

            list = Lab8.PrettifyList(minifiedList);
            Console.WriteLine(list);
            Debug.Assert(prettifiedList == list);

            Console.WriteLine("---------------------------------");

            minifiedList = "Week 1_Course Explanation/it's fun/it's awesome_Hello World_Types of Programming Languages|Week 2_Console output_Variables_Primitive Types|Week 3_Casting_Operator_String_Console input";
            prettifiedList = @"1) Week 1
    a) Course Explanation
        - it's fun
        - it's awesome
    b) Hello World
    c) Types of Programming Languages
2) Week 2
    a) Console output
    b) Variables
    c) Primitive Types
3) Week 3
    a) Casting
    b) Operator
    c) String
    d) Console input
";

            list = Lab8.PrettifyList(minifiedList);
            Console.WriteLine(list);
            Debug.Assert(prettifiedList == list);

        }
    }
}