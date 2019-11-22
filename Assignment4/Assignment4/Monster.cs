using System;
using System.Collections.Generic;
using System.Text;

namespace Assignment4
{
    public class Monster
    {
        public string Name { get; private set; }
        public EElementType ElementType { get; private set; }
        public int Health { get; private set; }
        public int AttackStat { get; private set; }
        public int DefenseStat { get; private set; }

        public Monster(string name, EElementType elementType, int health, int attack, int defense)
        {
            Name = name;
            ElementType = elementType;
            Health = health;
            AttackStat = attack;
            DefenseStat = defense;
        }

        public void TakeDamage(int amount)
        {
            if (Health - amount < 0)
            {
                Health = 0;
            }
            else
            {
                Health -= amount;
            }
        }

        public void Attack(Monster otherMonster)
        {
            double damagePoint = AttackStat - otherMonster.DefenseStat;
            switch (ElementType)
            {
                case EElementType.Fire:
                    if(otherMonster.ElementType == EElementType.Wind)
                    {
                        damagePoint *= 1.5;
                    }
                    else if(otherMonster.ElementType == EElementType.Water || otherMonster.ElementType == EElementType.Earth)
                    {
                        damagePoint *= 0.5;
                    }
                    break;
                case EElementType.Water:
                    if (otherMonster.ElementType == EElementType.Fire)
                    {
                        damagePoint *= 1.5;
                    }
                    else if (otherMonster.ElementType == EElementType.Wind)
                    {
                        damagePoint *= 0.5;
                    }
                    break;
                case EElementType.Earth:
                    if (otherMonster.ElementType == EElementType.Fire)
                    {
                        damagePoint *= 1.5;
                    }
                    else if (otherMonster.ElementType == EElementType.Wind)
                    {
                        damagePoint *= 0.5;
                    }
                    break;
                case EElementType.Wind:
                    if (otherMonster.ElementType == EElementType.Water || otherMonster.ElementType == EElementType.Earth)
                    {
                        damagePoint *= 1.5;
                    }
                    else if (otherMonster.ElementType == EElementType.Fire)
                    {
                        damagePoint *= 0.5;
                    }
                    break;
            }
            if(damagePoint < 1)
            {
                damagePoint = 1;
            }
            otherMonster.TakeDamage((int)damagePoint);
        }
    }
}
