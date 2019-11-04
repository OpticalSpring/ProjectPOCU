namespace Lab8
{
    public static class Lab8
    {
        public static string PrettifyList(string s)
        {
            for (int i = 0; i < 1; i++)
            {
                if(s[i] == 0 || s[i] == 32 || s[i] == 0x9 || s[i] == 0xa || s[i] == 0xb || s[i] == 0xc || s[i] == 0xd || s[i] == 0x20)
                {
                    return null;
                }
            }
            int n1Count = 1;
            int n2Count = 96;
            string rString = "1) ";
            for (int i = 0; i < s.Length; i++)
            {
                if (s[i] == '|')
                {
                    n1Count++;
                    n2Count = 96;
                    rString += "\r\n";
                    rString += n1Count;
                    rString += ") ";
                }
                else if (s[i] == '_')
                {
                    n2Count++;
                    rString += "\r\n    ";
                    rString += (char)n2Count;
                    rString += ") ";
                }
                else if (s[i] == '/')
                {
                    rString += "\r\n        ";
                    rString += "- ";
                }
                else
                {
                    rString += s[i];
                }
            }
            rString += "\r\n";
            return rString;
        }
    }
}