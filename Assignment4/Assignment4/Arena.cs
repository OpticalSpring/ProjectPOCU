
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

        public int MobCount;

        public Monster[] Mob;
        public Arena(string arenaName, uint capacity)
        {
            ArenaName = arenaName;
            Capacity = capacity;
            Mob = new Monster[Capacity];
            Turns = 0;
            MonsterCount = 0;
        }

        public void LoadMonsters(string filePath)
        {
            if (!File.Exists(filePath))
            {
                return;
            }
            string[] lines = File.ReadAllLines(filePath);

            string[] str = { "", "", "", "", "" };
            int num = 0;
            if (lines.Length > Capacity)
            {
                MobCount = (int)Capacity;
            }
            else
            {
                MobCount = lines.Length;
            }
            for (int j = 0; j < MobCount; j++)
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
                Mob[j] = new Monster(str[0], type, int.Parse(str[2]), int.Parse(str[3]), int.Parse(str[4]));
                MonsterCount++;
            }
        }

        public void GoToNextTurn()
        {
            if (MonsterCount == 0)
            {
                return;
            }
            if (MonsterCount == 1)
            {
                return;
            }
            for (int i = 0; i < MobCount; i++)
            {
                if (Mob[i].Health > 0)
                {
                    int j = 0;
                    while (true)
                    {
                        j++;
                        if (i + j >= MobCount)
                        {
                            if (Mob[i + j - MobCount].Health > 0)
                            {
                                Mob[i].Attack(Mob[i + j - MobCount]);
                                if (Mob[i + j - MobCount].Health <= 0)
                                {
                                    MonsterCount--;
                                }
                                break;
                            }
                        }
                        else
                        {
                            if (Mob[i + j].Health > 0)
                            {
                                Mob[i].Attack(Mob[i + j]);
                                if (Mob[i + j].Health <= 0)
                                {
                                    MonsterCount--;
                                }
                                break;
                            }
                        }
                    }
                }
            }
            Turns++;
            Console.WriteLine("{0} ------------", Turns);
            for (int i = 0; i < MobCount; i++)
            {
                Console.WriteLine("{0} : {1}", Mob[i].Name, Mob[i].Health);
            }
        }

        public Monster GetHealthiest()
        {

            if (MonsterCount == 0)
            {
                return null;
            }
            int max = 0;
            int num = 0;
            for (int i = 0; i < MobCount; i++)
            {
                if (Mob[i].Health > max)
                {
                    max = Mob[i].Health;
                    num = i;
                }
            }
            return Mob[num];
        }
    }
}
