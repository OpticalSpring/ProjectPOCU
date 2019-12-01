using System;
using System.Collections.Generic;
using System.Text;
using System.IO;


namespace Lab11
{
    public static class Encoder
    {
        public static bool TryEncode(Stream input, Stream output)
        {
            if(input.Length == 0 || input == null)
            {
                return false;
            }
            string str = "";
            for (int i = 0; i < input.Length; i++)
            {
                str += input.ReadByte();
               if(str[i] == ' ')
                {
                    
                    str = str.Substring(0,str.Length - 1);
                    str += '0';
                }
            }
            str += "00";
            Console.WriteLine(str);
            string rStr = "";
            string b = ""+str[0] + str[1];
            int count = 0;
            int charValue = int.Parse(b);
            for (int i = 0; i < str.Length-1; i+=2)
            {
                string a = "" + str[i] + str[i + 1];
                if(charValue != int.Parse(a))
                {
                    rStr += Convert.ToString(count, 16).PadLeft(2, '0') + " " + Convert.ToString(charValue,16).PadLeft(2,'0') + " ";
                    count = 1;
                    charValue = int.Parse(a);
                    Console.WriteLine(a);
                }
                else
                {
                    count++;
                }

            }
            Console.WriteLine(rStr);
            return true;
        }

        public static bool TryDecode(Stream input, Stream output)
        {
            return false;
        }
    }
}
