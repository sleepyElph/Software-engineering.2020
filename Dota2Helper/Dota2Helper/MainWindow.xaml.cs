using Dota2Helper.Abilities;
using Dota2Helper.Heroes;
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Dota2Helper
{
    public partial class MainWindow : Window
    {
        private Hero SelectedHero;
        private Ability SelectedAbility;
        private Controller Controller = new Controller();

        public MainWindow()
        {
            InitializeComponent();
            HeroCombo.ItemsSource = Controller.GetAllHeroName();
            
            SelectedHero = Controller.GetHero("Axe");
            HeroCombo.Text = "Axe";
            UpdateHero();
        }

        private void UpdateHero()
        {
            if (SelectedHero is RangeHero)
            {
                AttackRange.Visibility = ProjectileSpeed1.Visibility =
                    ProjectileSpeed2.Visibility = ProjectileBlock.Visibility = Visibility.Visible;
                AttackTime.Visibility = Visibility.Hidden;
                TypeAttackBlock.Text = ((RangeHero)SelectedHero).AttackRange.ToString();
                ProjectileBlock.Text = ((RangeHero)SelectedHero).ProjectileSpeed.ToString();
            }
            else
            {
                AttackRange.Visibility = ProjectileSpeed1.Visibility =
                    ProjectileSpeed2.Visibility = ProjectileBlock.Visibility = Visibility.Hidden;
                AttackTime.Visibility = Visibility.Visible;
                TypeAttackBlock.Text = ((MeleeHero)SelectedHero).AttackAnimationSpeed.ToString();
            }
            SelectedAbility = SelectedHero.FirstSpell;
            UpdateMainAttribute();
            UpdateAttribute();
            UpdateTalents();
            UpdateImages();
            UpdateAbilities();
        }

        private void UpdateMainAttribute()
        {
            HeroName.Text = SelectedHero.Name.ToUpper();
            if (SelectedHero.MainAttribute == 1)
            {
                MainStrength.Visibility = Visibility.Visible;
                MainAgility.Visibility = Visibility.Hidden;
                MainIntelligence.Visibility = Visibility.Hidden;
            }
            if (SelectedHero.MainAttribute == 2)
            {
                MainStrength.Visibility = Visibility.Hidden;
                MainAgility.Visibility = Visibility.Visible;
                MainIntelligence.Visibility = Visibility.Hidden;
            }
            if (SelectedHero.MainAttribute == 3)
            {
                MainStrength.Visibility = Visibility.Hidden;
                MainAgility.Visibility = Visibility.Hidden;
                MainIntelligence.Visibility = Visibility.Visible;
            }
        }

        private void UpdateAttribute()
        {
            HeroDescription.Text = SelectedHero.Description;
            HPBlock.Text = SelectedHero.Hp.ToString();
            ManaBlock.Text = SelectedHero.Mana.ToString();
            IncHPBlock.Text = "+" + SelectedHero.IncHp.ToString();
            IncManaBlock.Text = "+" + SelectedHero.IncMana.ToString();
            StrengthBlock.Text = SelectedHero.Strength.ToString() + "+" + SelectedHero.IncStrength.ToString();
            AgilityBlock.Text = SelectedHero.Agility.ToString() + "+" + SelectedHero.IncAgility.ToString();
            IntelligenceBlock.Text = SelectedHero.Intelligence.ToString() + "+" + SelectedHero.IncIntelligence.ToString();
            DamageBlock.Text = SelectedHero.Damage.ToString();
            ArmorBlock.Text = SelectedHero.Armor.ToString();
            SpeedBlock.Text = SelectedHero.Speed.ToString();
            AttackSpeedBlock.Text = SelectedHero.AttackSpeed.ToString();
        }

        private void UpdateTalents()
        {
            TalentL1Block.Text = SelectedHero.Talents.First(x => x.Key == "L1").Value;
            TalentL2Block.Text = SelectedHero.Talents.First(x => x.Key == "L2").Value;
            TalentL3Block.Text = SelectedHero.Talents.First(x => x.Key == "L3").Value;
            TalentL4Block.Text = SelectedHero.Talents.First(x => x.Key == "L4").Value;
            TalentR1Block.Text = SelectedHero.Talents.First(x => x.Key == "R1").Value;
            TalentR2Block.Text = SelectedHero.Talents.First(x => x.Key == "R2").Value;
            TalentR3Block.Text = SelectedHero.Talents.First(x => x.Key == "R3").Value;
            TalentR4Block.Text = SelectedHero.Talents.First(x => x.Key == "R4").Value;

        }

        private void UpdateAbilities()
        {
            AbilityManacost.Text = AbilityCoolDown.Text = "";
            AbilityName.Text = SelectedAbility.Name.ToUpper();
            AbilityDescription.Text = SelectedAbility.Description;
            if (SelectedAbility.Active) AbilityType.Text = "Активная";
            else AbilityType.Text = "Пассивная";

            for (int i = 0; i < SelectedAbility.GetCoolDown().Length; i++)
            {
                AbilityCoolDown.Text += SelectedAbility.GetCoolDown()[i].ToString();
                AbilityManacost.Text += SelectedAbility.GetManacost()[i].ToString();
                if (i != SelectedAbility.GetCoolDown().Length-1)
                {
                    AbilityCoolDown.Text += '/';
                    AbilityManacost.Text += '/';
                }
                if (SelectedAbility.SameManaCost) AbilityManacost.Text = SelectedAbility.GetManacost()[0].ToString();
                if (SelectedAbility.SameCoolDown) AbilityCoolDown.Text = SelectedAbility.GetCoolDown()[0].ToString();
            }
        }

        private void UpdateImages()
        {            
            Uri uri = new Uri("pack://application:,,,/SourseImage/HeroImage/" + SelectedHero.Name + ".png");
            BitmapImage image = new BitmapImage(uri);
            HeroImage.Source = image;

            Uri uri1 = new Uri("pack://application:,,,/SourseImage/AbilityImage/" + SelectedHero.FirstSpell.Name + ".png");
            BitmapImage image1 = new BitmapImage(uri1);
            FirstSpellIcon.Source = image1;

            Uri uri2 = new Uri("pack://application:,,,/SourseImage/AbilityImage/" + SelectedHero.SecondSpell.Name + ".png");
            BitmapImage image2 = new BitmapImage(uri2);
            SecondSpellIcon.Source = image2;

            Uri uri3 = new Uri("pack://application:,,,/SourseImage/AbilityImage/" + SelectedHero.ThirdSpell.Name + ".png");
            BitmapImage image3 = new BitmapImage(uri3);
            ThirdSpellIcon.Source = image3;

            Uri uri4 = new Uri("pack://application:,,,/SourseImage/AbilityImage/" + SelectedHero.Ultimate.Name + ".png");
            BitmapImage image4 = new BitmapImage(uri4);
            UltimateIcon.Source = image4;
        }

        private void FirstSpell_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            SelectedAbility = SelectedHero.FirstSpell;
            UpdateAbilities();
            SecondSpellBorder.BorderThickness = ThirdSpellBorder.BorderThickness = UltimateBorder.BorderThickness = new Thickness(0);
            FirstSpellBorder.BorderThickness = new Thickness(5);
        }
        private void SecondSpell_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            SelectedAbility = SelectedHero.SecondSpell;
            UpdateAbilities();
            FirstSpellBorder.BorderThickness = ThirdSpellBorder.BorderThickness = UltimateBorder.BorderThickness = new Thickness(0);
            SecondSpellBorder.BorderThickness = new Thickness(5);
        }
        private void ThirdSpell_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            SelectedAbility = SelectedHero.ThirdSpell;
            UpdateAbilities();
            SecondSpellBorder.BorderThickness = FirstSpellBorder.BorderThickness = UltimateBorder.BorderThickness = new Thickness(0);
            ThirdSpellBorder.BorderThickness = new Thickness(5);
        }
        private void Ultimate_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            SelectedAbility = SelectedHero.Ultimate;
            UpdateAbilities();
            SecondSpellBorder.BorderThickness = ThirdSpellBorder.BorderThickness = FirstSpellBorder.BorderThickness = new Thickness(0);
            UltimateBorder.BorderThickness = new Thickness(5);
        }


        //control button//
        private void HeroCombo_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            SelectedHero = Controller.GetHero(HeroCombo.SelectedItem.ToString());
            UpdateHero();
        }
        
        private void Exit_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            Close();
        }

        private void Min_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            WindowState = WindowState.Minimized;
        }

        private void Move_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }

        private void CompareHero_Click(object sender, RoutedEventArgs e)
        {
            CompareWindow compareWindow = new CompareWindow(SelectedHero.Name);
            compareWindow.ShowDialog();
        }
    }
}
