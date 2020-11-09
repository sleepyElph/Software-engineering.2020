using Dota2Helper.Heroes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Dota2Helper
{
    class Controller
    {
        private List<Hero> Heroes = new List<Hero>();
        public Controller()
        {
            List<HeroTable> heroes;
            using (DotaBaseContext context = new DotaBaseContext())
            {
                heroes = context.HeroTable.ToList();
                foreach(HeroTable h in heroes)
                {
                    if (h.Range)
                    {
                        RangeHero range = new RangeHero(h);
                        Heroes.Add(range);
                    }
                    else
                    {
                        MeleeHero melee = new MeleeHero(h);
                        Heroes.Add(melee);
                    }
                }
            }
        }
        
        public Hero GetHero(string HeroName)
        {
            return Heroes.First(x => x.Name == HeroName);
        }

        public List<string> GetAllHeroName()
        {
            List<string> names = new List<string>();
            foreach(Hero h in Heroes)
            {
                names.Add(h.Name);
            }
            return names;
        }

        public bool DamageCompare(Hero hero1, Hero hero2)
        {
            return hero1.Damage > hero2.Damage;
        }

        public bool ArmorCompare(Hero hero1, Hero hero2)
        {
            return hero1.Armor > hero2.Armor;
        }

        public bool SpeedCompare(Hero hero1, Hero hero2)
        {
            return hero1.Speed > hero2.Speed;
        }

        public bool AttackSpeedCompare(Hero hero1, Hero hero2)
        {
            return hero1.AttackSpeed > hero2.AttackSpeed;
        }

        public bool AnimationAttackCompare(MeleeHero hero1, MeleeHero hero2)
        {
            return hero1.AttackAnimationSpeed < hero2.AttackAnimationSpeed;
        }

        public bool AttackRangeCompare(RangeHero hero1, RangeHero hero2)
        {
            return hero1.AttackRange > hero2.AttackRange;
        }

        public bool ProjectileSpeedCompare(RangeHero hero1, RangeHero hero2)
        {
            return hero1.ProjectileSpeed > hero2.ProjectileSpeed;
        }
    }
}