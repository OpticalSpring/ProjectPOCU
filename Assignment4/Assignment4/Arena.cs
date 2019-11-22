
using System;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Assignment4
{
    public class Arena
    {
        public uint Capacity { get; private set; }
        public string ArenaName { get; private set; }
        public uint Turns { get; private set; }
        public uint MonsterCount { get; private set; }

        private int mobCount;

        public Monster[] monster;
        public Arena(string arenaName, uint capacity)
        {
            ArenaName = arenaName;
            Capacity = capacity;
            monster = new Monster[Capacity];
            Turns = 0;
            MonsterCount = 0;
        }

        public void LoadMonsters(string filePath)
        {
            string[] lines = File.ReadAllLines(filePath);

            string[] str = { "", "", "", "", "" };
            int num = 0;
            mobCount = lines.Length;
            for (int j = 0; j < mobCount; j++)
            {
                num = 0;
                for (int i = 0; i < 5; i++)
                {
                    str[i] = "";
                }
                for (int i = 0; i < lines[j].Length; i++)
                {
                    if (lines[j][i] == ',')
                    {
                        num++;
                    }
                    else
                    {
                        str[num] += lines[j][i];
                    }
                }


                EElementType type = EElementType.Water;
                if (str[1] == "Earth")
                {
                    type = EElementType.Earth;
                }
                else if (str[1] == "Wind")
                {
                    type = EElementType.Wind;
                }
                else if (str[1] == "Fire")
                {
                    type = EElementType.Fire;
                }
                else if (str[1] == "Water")
                {
                    type = EElementType.Water;
                }
                monster[j] = new Monster(str[0], type, int.Parse(str[2]), int.Parse(str[3]), int.Parse(str[4]));
                MonsterCount++;
                Console.WriteLine("---설명---");
                Console.WriteLine("이름: {0}", monster[j].Name);
                Console.WriteLine("속성: {0}", monster[j].ElementType);
                Console.WriteLine("체력: {0}", monster[j].Health);
                Console.WriteLine("공격력: {0}", monster[j].AttackStat);
                Console.WriteLine("방어력: {0}", monster[j].DefenseStat);
            }
        }

        public void GoToNextTurn()
        {
            MonsterCount = 0;
            for (int i = 0; i < mobCount; i++)
            {
                if (monster[i].Health > 0)
                {
                    int j = 0;
                    MonsterCount++;
                    if(MonsterCount == 1)
                    {
                        break;
                    }
                    while (true)
                    {
                        j++;
                        if (i + j >= mobCount)
                        {
                            if (monster[i + j - mobCount].Health > 0)
                            {
                                monster[i].Attack(monster[i + j - mobCount]);
                                Console.WriteLine("------");
                                Console.WriteLine("이름: {0}", monster[i].Name);
                                Console.WriteLine("체력: {0}", monster[i].Health);
                                break;
                            }
                        }
                        else
                        {
                            if (monster[i + j].Health > 0)
                            {
                                monster[i].Attack(monster[i + j]);
                                Console.WriteLine("------");
                                Console.WriteLine("이름: {0}", monster[i].Name);
                                Console.WriteLine("체력: {0}", monster[i].Health);
                                break;
                            }
                        }
                    }
                }
            }
            Turns++;
        }

        public Monster GetHealthiest()
        {
            if(MonsterCount == 0)
            {
                return null;
            }
            int max = 0;
            int num = 0;
            for (int i = 0; i < mobCount; i++)
            {
                if (monster[i].Health > max)
                {
                    max = monster[i].Health;
                    num = i;
                }
            }
            Console.WriteLine(monster[num].Name);
            return monster[num];
        }
    }
}
