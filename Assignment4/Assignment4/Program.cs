using System.Diagnostics;

namespace Assignment4
{
    class Program
    {
        static void Main(string[] args)
        {
            Monster monster1 = new Monster("Slime", EElementType.Fire, 120, 7, 2);

            Debug.Assert(monster1.Name == "Slime");
            Debug.Assert(monster1.ElementType == EElementType.Fire);
            Debug.Assert(monster1.Health == 120);
            Debug.Assert(monster1.AttackStat == 7);
            Debug.Assert(monster1.DefenseStat == 2);

            monster1.TakeDamage(20);
            Debug.Assert(monster1.Health == 100);
            monster1.TakeDamage(110);
            Debug.Assert(monster1.Health == 0);

            monster1 = new Monster("Slime", EElementType.Fire, 100, 7, 2);
            Monster monster2 = new Monster("Goblin", EElementType.Earth, 70, 4, 3);

            monster1.Attack(monster2);
            Debug.Assert(monster2.Health == 68);

            monster2.Attack(monster1);
            Debug.Assert(monster1.Health == 97);

            Monster monster3 = new Monster("Ghost", EElementType.Water, 20, 1, 1);
            monster3.Attack(monster1);

            Debug.Assert(monster1.Health == 96);

            Arena arena = new Arena("Scorching Rocks", 8);

            Debug.Assert(arena.ArenaName == "Scorching Rocks");
            Debug.Assert(arena.Capacity == 8);
            Debug.Assert(arena.Turns == 0);
            Debug.Assert(arena.MonsterCount == 0);

            arena.LoadMonsters("monsters.txt");

            Debug.Assert(arena.MonsterCount == 6);
            Debug.Assert(arena.GetHealthiest().Name == "MyMonster5");

            arena.GoToNextTurn();
            arena.GoToNextTurn();
            arena.GoToNextTurn();
            arena.GoToNextTurn();

            Debug.Assert(arena.GetHealthiest().Name == "MyMonster1");
        }
    }
}