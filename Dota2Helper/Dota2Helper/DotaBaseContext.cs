using System;
using Microsoft.EntityFrameworkCore.Metadata;
using Microsoft.EntityFrameworkCore;

namespace Dota2Helper
{
    public partial class DotaBaseContext : DbContext
    {
        public virtual DbSet<AbilityTable> AbilityTable { get; set; }
        public virtual DbSet<HeroTable> HeroTable { get; set; }

        public DotaBaseContext()
        {
        }

        public DotaBaseContext(DbContextOptions<DotaBaseContext> options)
            : base(options)
        {
        }        

        protected override void OnConfiguring(DbContextOptionsBuilder optionsBuilder)
        {
            if (!optionsBuilder.IsConfigured)
            {
                optionsBuilder.UseSqlServer("Server=DESKTOP-NBICKMA;Database=DotaBase;Trusted_Connection=True;");
            }
        }

        protected override void OnModelCreating(ModelBuilder modelBuilder)
        {
            modelBuilder.Entity<AbilityTable>(entity =>
            {
                entity.HasKey(e => e.Name)
                    .HasName("PK_Ability");

                entity.Property(e => e.Name).HasMaxLength(20);

                entity.Property(e => e.Cd1).HasColumnName("CD1");

                entity.Property(e => e.Cd2).HasColumnName("CD2");

                entity.Property(e => e.Cd3).HasColumnName("CD3");

                entity.Property(e => e.Cd4).HasColumnName("CD4");
            });

            modelBuilder.Entity<HeroTable>(entity =>
            {
                entity.HasKey(e => e.Name)
                    .HasName("PK_Hero");

                entity.Property(e => e.Name).HasMaxLength(20);

                entity.Property(e => e.Description).IsRequired();

                entity.Property(e => e.FirstSpell)
                    .IsRequired()
                    .HasMaxLength(20);

                entity.Property(e => e.Hp).HasColumnName("HP");

                entity.Property(e => e.IncHp).HasColumnName("IncHP");

                entity.Property(e => e.SecondSpell)
                    .IsRequired()
                    .HasMaxLength(20);

                entity.Property(e => e.TalentL1)
                    .IsRequired()
                    .HasMaxLength(50);

                entity.Property(e => e.TalentL2)
                    .IsRequired()
                    .HasMaxLength(50);

                entity.Property(e => e.TalentL3)
                    .IsRequired()
                    .HasMaxLength(50);

                entity.Property(e => e.TalentL4)
                    .IsRequired()
                    .HasMaxLength(50);

                entity.Property(e => e.TalentR1)
                    .IsRequired()
                    .HasMaxLength(50);

                entity.Property(e => e.TalentR2)
                    .IsRequired()
                    .HasMaxLength(50);

                entity.Property(e => e.TalentR3)
                    .IsRequired()
                    .HasMaxLength(50);

                entity.Property(e => e.TalentR4)
                    .IsRequired()
                    .HasMaxLength(50);

                entity.Property(e => e.ThirdSpell)
                    .IsRequired()
                    .HasMaxLength(20);

                entity.Property(e => e.Ultimate)
                    .IsRequired()
                    .HasMaxLength(20);

                entity.HasOne(d => d.FirstSpellNavigation)
                    .WithMany(p => p.HeroTableFirstSpellNavigation)
                    .HasForeignKey(d => d.FirstSpell)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_Hero_Ability");

                entity.HasOne(d => d.SecondSpellNavigation)
                    .WithMany(p => p.HeroTableSecondSpellNavigation)
                    .HasForeignKey(d => d.SecondSpell)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_Hero_Ability1");

                entity.HasOne(d => d.ThirdSpellNavigation)
                    .WithMany(p => p.HeroTableThirdSpellNavigation)
                    .HasForeignKey(d => d.ThirdSpell)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_Hero_Ability2");

                entity.HasOne(d => d.UltimateNavigation)
                    .WithMany(p => p.HeroTableUltimateNavigation)
                    .HasForeignKey(d => d.Ultimate)
                    .OnDelete(DeleteBehavior.ClientSetNull)
                    .HasConstraintName("FK_Hero_Ability3");
            });

            OnModelCreatingPartial(modelBuilder);
        }

        partial void OnModelCreatingPartial(ModelBuilder modelBuilder);
    }
}
