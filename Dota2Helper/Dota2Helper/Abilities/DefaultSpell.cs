using System;
using System.Collections.Generic;
using System.Text;

namespace Dota2Helper.Abilities
{
    public class DefaultSpell : Ability
    {
        public override int[] GetManacost() {return ManaCost;}
        public override int[] GetCoolDown() {return CoolDown;}
        public DefaultSpell(AbilityTable ability)
        {
            Name = ability.Name;
            Active = ability.Active;
            Description = ability.Description;

            CoolDown[0] = (int)ability.Cd1;
            CoolDown[1] = (int)ability.Cd2;
            CoolDown[2] = (int)ability.Cd3;
            CoolDown[3] = (int)ability.Cd4;

            ManaCost[0] = (int)ability.ManaCost1;
            ManaCost[1] = (int)ability.ManaCost2;
            ManaCost[2] = (int)ability.ManaCost3;
            ManaCost[3] = (int)ability.ManaCost4;

            if ((int)ability.Cd1 == (int)ability.Cd2 && (int)ability.Cd2 == (int)ability.Cd3 && (int)ability.Cd3 == (int)ability.Cd4) SameCoolDown = true;
            if ((int)ability.ManaCost1 == (int)ability.ManaCost2 && (int)ability.ManaCost2 == (int)ability.ManaCost3 && (int)ability.ManaCost3 == (int)ability.ManaCost4) SameManaCost = true;
        }
        private int[] CoolDown = new int[4];
        private int[] ManaCost = new int[4];

        
    }
}
