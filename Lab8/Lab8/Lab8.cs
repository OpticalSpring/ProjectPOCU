namespace Lab8
{
    public static class Lab8
    {
        public static string PrettifyList(string s)
        {
            if (s == null)
            {
                return null;
            }
            else if (s.Length == 0)
            {
                return null;
            }
            else if (s[0] == 0 || s[0] == 32 || s[0] == 0x9 || s[0] == 0xa || s[0] == 0xb || s[0] == 0xc || s[0] == 0xd || s[0] == 0x20)
            {
                return null;
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
                else if (s[i] == '/' && n2Count > 96)
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