using System;
using System.Collections.Generic;

namespace Dota2Helper
{
    public partial class AbilityTable
    {
        public AbilityTable()
        {
            HeroTableFirstSpellNavigation = new HashSet<HeroTable>();
            HeroTableSecondSpellNavigation = new HashSet<HeroTable>();
            HeroTableThirdSpellNavigation = new HashSet<HeroTable>();
            HeroTableUltimateNavigation = new HashSet<HeroTable>();
        }

        public string Name { get; set; }
        public bool Active { get; set; }
        public bool Ultimate { get; set; }
        public int? Cd1 { get; set; }
        public int? Cd2 { get; set; }
        public int? Cd3 { get; set; }
        public int? Cd4 { get; set; }
        public int? ManaCost1 { get; set; }
        public int? ManaCost2 { get; set; }
        public int? ManaCost3 { get; set; }
        public int? ManaCost4 { get; set; }
        public string Description { get; set; }

        public virtual ICollection<HeroTable> HeroTableFirstSpellNavigation { get; set; }
        public virtual ICollection<HeroTable> HeroTableSecondSpellNavigation { get; set; }
        public virtual ICollection<HeroTable> HeroTableThirdSpellNavigation { get; set; }
        public virtual ICollection<HeroTable> HeroTableUltimateNavigation { get; set; }
    }
}
