using System;
using System.Collections.Generic;
using System.Text;

namespace Dota2Helper.Abilities
{
    public abstract class Ability
    {
        public abstract int[] GetManacost();
        public abstract int[] GetCoolDown();

        public string Name { get; protected set; }
        public bool Active { get; protected set; }
        public string Description { get; protected set; }
        public bool SameManaCost { get; protected set; }
        public bool SameCoolDown { get; protected set; }
        
    }
}
