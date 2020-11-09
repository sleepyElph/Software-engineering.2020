using Dota2Helper.Abilities;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Dota2Helper.Heroes
{
    public class MeleeHero : Hero
    {
        public float AttackAnimationSpeed { get; private set; }

        public MeleeHero(HeroTable hero)
        {
            Talents.Add("L1", hero.TalentL1);
            Talents.Add("L2", hero.TalentL2);
            Talents.Add("L3", hero.TalentL3);
            Talents.Add("L4", hero.TalentL4);
            Talents.Add("R1", hero.TalentR1);
            Talents.Add("R2", hero.TalentR2);
            Talents.Add("R3", hero.TalentR3);
            Talents.Add("R4", hero.TalentR4);
            Name = hero.Name;
            Hp = hero.Hp;
            Mana = hero.Mana;
            IncHp = hero.IncHp;
            IncMana = hero.IncMana;
            MainAttribute = hero.MainAttribute;
            Strength = hero.Strength;
            Agility = hero.Agility;
            Intelligence = hero.Intelligence;
            IncStrength = hero.IncStrength;
            IncAgility = hero.IncAgility;
            IncIntelligence = hero.IncIntelligence;
            Damage = hero.Damage;
            Armor = hero.Armor;
            AttackSpeed = hero.AttackSpeed;
            Speed = hero.Speed;
            Description = hero.Description;
            AttackAnimationSpeed = (float)hero.AttackAnimationSpeed;

            using (DotaBaseContext context = new DotaBaseContext())
            {
                List<AbilityTable> abilities = context.AbilityTable.ToList();
                DefaultSpell First = new DefaultSpell(abilities.First(x => x.Name == hero.FirstSpell));
                FirstSpell = First;

                DefaultSpell Second = new DefaultSpell(abilities.First(x => x.Name == hero.SecondSpell));
                SecondSpell = Second;

                DefaultSpell Third = new DefaultSpell(abilities.First(x => x.Name == hero.ThirdSpell));
                ThirdSpell = Third;

                Ultimate Ulti = new Ultimate(abilities.First(x => x.Name == hero.Ultimate));
                Ultimate = Ulti;
            }
        }          
    }
}
