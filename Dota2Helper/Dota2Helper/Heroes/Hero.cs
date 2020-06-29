using Dota2Helper.Abilities;
using System;
using System.Collections.Generic;
using System.Numerics;
using System.Text;

namespace Dota2Helper.Heroes
{
    public abstract class Hero
    {
        public DefaultSpell FirstSpell { get; protected set; }
        public DefaultSpell SecondSpell { get; protected set; }
        public DefaultSpell ThirdSpell { get; protected set; }
        public Ultimate Ultimate { get; protected set; }
        public Dictionary<string, string> Talents = new Dictionary<string, string>();
        public string Name { get; protected set; }
        public int Hp { get; protected set; }
        public int Mana { get; protected set; }
        public float IncHp { get; protected set; }
        public float IncMana { get; protected set; }
        public int MainAttribute { get; protected set; }
        public int Strength { get; protected set; }
        public int Agility { get; protected set; }
        public int Intelligence { get; protected set; }
        public float IncStrength { get; protected set; }
        public float IncAgility { get; protected set; }
        public float IncIntelligence { get; protected set; }
        public int Damage { get; protected set; }
        public int Armor { get; protected set; }
        public int AttackSpeed { get; protected set; }
        public int Speed { get; protected set; }        
        public string Description { get; protected set; }
    }
}
