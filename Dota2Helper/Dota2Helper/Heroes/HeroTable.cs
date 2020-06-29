using System;
using System.Collections.Generic;

namespace Dota2Helper
{
    public partial class HeroTable
    {
        public string Name { get; set; }
        public int Hp { get; set; }
        public int Mana { get; set; }
        public float IncHp { get; set; }
        public float IncMana { get; set; }
        public int MainAttribute { get; set; }
        public int Strength { get; set; }
        public int Agility { get; set; }
        public int Intelligence { get; set; }
        public float IncStrength { get; set; }
        public float IncAgility { get; set; }
        public float IncIntelligence { get; set; }
        public int Damage { get; set; }
        public int Armor { get; set; }
        public int AttackSpeed { get; set; }
        public int Speed { get; set; }
        public bool Range { get; set; }
        public int? AttackRange { get; set; }
        public int? ProjectileSpeed { get; set; }
        public float? AttackAnimationSpeed { get; set; }
        public string FirstSpell { get; set; }
        public string SecondSpell { get; set; }
        public string ThirdSpell { get; set; }
        public string Ultimate { get; set; }
        public string TalentR1 { get; set; }
        public string TalentR2 { get; set; }
        public string TalentR3 { get; set; }
        public string TalentR4 { get; set; }
        public string TalentL1 { get; set; }
        public string TalentL2 { get; set; }
        public string TalentL3 { get; set; }
        public string TalentL4 { get; set; }
        public string Description { get; set; }

        public virtual AbilityTable FirstSpellNavigation { get; set; }
        public virtual AbilityTable SecondSpellNavigation { get; set; }
        public virtual AbilityTable ThirdSpellNavigation { get; set; }
        public virtual AbilityTable UltimateNavigation { get; set; }
    }
}
