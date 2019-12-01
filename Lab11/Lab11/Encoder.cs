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
            if (input.Length == 0 || input == null)
            {
                return false;
            }
            char[] charArray = new char[input.Length + 1];
            for (int i = 0; i < input.Length; i++)
            {
                charArray[i] = (char)input.ReadByte();
            }
            charArray[input.Length] = ' ';
            Console.WriteLine(charArray);

            string rStr = "";
            int count = 0;
            char lastChar = charArray[1];
            for (int i = 0; i < charArray.Length; i++)
            {
                if (charArray[i] != lastChar)
                {
                    
                    rStr += count + "/"+ lastChar + ".";
                    lastChar = charArray[i];
                    count = 1;
                }
                else
                {
                    if (count >= 255)
                    {
                        rStr += count + "/" + lastChar + ".";
                        lastChar = charArray[i];
                        count = 1;
                    }
                    else
                    {
                        count++;
                    }
                }
            }
            Console.WriteLine(rStr);
            string nav = "";
            for (int i = 0; i < rStr.Length; i++)
            {
                if (rStr[i] == '/')
                {
                    
                    for (int j = 0; j < nav.Length; j++)
                    {
                        char a = (char)nav[j];
                        int b = 0;
                        switch (a)
                        {
                            case '0':
                                b = 0;
                                break;
                            case '1':
                                b = 1;
                                break;
                            case '2':
                                b = 2;
                                break;
                            case '3':
                                b = 3;
                                break;
                            case '4':
                                b = 4;
                                break;
                            case '5':
                                b = 5;
                                break;
                            case '6':
                                b = 6;
                                break;
                            case '7':
                                b = 7;
                                break;
                            case '8':
                                b = 8;
                                break;
                            case '9':
                                b = 9;
                                break;
                            case 'A':
                                b = 10;
                                break;
                            case 'B':
                                b = 11;
                                break;
                            case 'C':
                                b = 12;
                                break;
                            case 'D':
                                b = 13;
                                break;
                            case 'E':
                                b = 14;
                                break;
                            case 'F':
                                b = 15;
                                break;
                        }
                        output.WriteByte((byte)b);
                    }
                    nav = "";
                }
                else if (rStr[i] == '.')
                {
                    for (int j = 0; j < nav.Length; j++)
                    {
                        output.WriteByte((byte)nav[j]);
                    }
                    nav = "";
                }
                else
                {

                    nav += rStr[i];
                }
            }
            input.Position = 0;
            output.Position = 0;

            return true;
        }

        public static bool TryDecode(Stream input, Stream output)
        {
            if (input.Length == 0 || input == null)
            {
                return false;
            }
            string str = "";
            for (int i = 0; i < input.Length; i++)
            {
                str += input.ReadByte() + "/";
            }
            //Console.WriteLine(str);
            string rStr = "";
            string nav = "";
            int count = 0;
            int a = 0;

            for (int i = 0; i < str.Length; i++)
            {
                if (str[i] == '/')
                {
                    a++;
                    if (a % 2 == 1)
                    {
                        count = int.Parse(nav);
                        nav = "";
                    }
                    else
                    {
                        for (int j = 0; j < count; j++)
                        {
                            rStr += (char)int.Parse(nav);
                        }
                        nav = "";
                    }

                }
                else
                {
                    nav += str[i];
                }
            }
            //Console.WriteLine(rStr);

            for (int i = 0; i < rStr.Length; i++)
            {
                output.WriteByte((byte)rStr[i]);
            }
            input.Position = 0;
            output.Position = 0;
            return true;
        }
    }
}
