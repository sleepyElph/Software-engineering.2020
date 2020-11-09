using Dota2Helper.Heroes;
using System;
using System.Collections.Generic;
using System.Text;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Shapes;

namespace Dota2Helper
{
    /// <summary>
    /// Логика взаимодействия для CompareWindow.xaml
    /// </summary>
    public partial class CompareWindow : Window
    {
        private Hero Hero1;
        private Hero Hero2;
        private Controller Controller = new Controller();

        public CompareWindow(string h)
        {
            Hero1 = Controller.GetHero(h);
            Hero2 = Controller.GetHero("Axe");
            InitializeComponent();
            UpdateData();
            HeroCombo1.ItemsSource = Controller.GetAllHeroName();
            HeroCombo2.ItemsSource = Controller.GetAllHeroName();
            HeroCombo1.Text = h;
            HeroCombo2.Text = "Axe";
        }


        private void UpdateAttribute1()
        {
            HPBlock1.Text = Hero1.Hp.ToString();
            ManaBlock1.Text = Hero1.Mana.ToString();
            IncHPBlock1.Text = "+" + Hero1.IncHp.ToString();
            IncManaBlock1.Text = "+" + Hero1.IncMana.ToString();
            StrengthBlock1.Text = Hero1.Strength.ToString() + "+" + Hero1.IncStrength.ToString();
            AgilityBlock1.Text = Hero1.Agility.ToString() + "+" + Hero1.IncAgility.ToString();
            IntelligenceBlock1.Text = Hero1.Intelligence.ToString() + "+" + Hero1.IncIntelligence.ToString();
            DamageBlock1.Text = Hero1.Damage.ToString();
            ArmorBlock1.Text = Hero1.Armor.ToString();
            SpeedBlock1.Text = Hero1.Speed.ToString();
            AttackSpeedBlock1.Text = Hero1.AttackSpeed.ToString();
            if (Hero1 is RangeHero)
            {
                TypeAttackBlock1.Text = ((RangeHero)Hero1).AttackRange.ToString();
                ProjectileBlock1.Text = ((RangeHero)Hero1).ProjectileSpeed.ToString();
            }
            else
            {
                ProjectileBlock1.Text = "";
                TypeAttackBlock1.Text = ((MeleeHero)Hero1).AttackAnimationSpeed.ToString();
            }
        }        

        private void UpdateImages1()
        {
            Uri uri = new Uri("pack://application:,,,/SourseImage/HeroImage/" + Hero1.Name + ".png");
            BitmapImage image = new BitmapImage(uri);
            HeroImage1.Source = image;
           
        }

        private void UpdateAttribute2()
        {
            HPBlock2.Text = Hero2.Hp.ToString();
            ManaBlock2.Text = Hero2.Mana.ToString();
            IncHPBlock2.Text = "+" + Hero2.IncHp.ToString();
            IncManaBlock2.Text = "+" + Hero2.IncMana.ToString();
            StrengthBlock2.Text = Hero2.Strength.ToString() + "+" + Hero2.IncStrength.ToString();
            AgilityBlock2.Text = Hero2.Agility.ToString() + "+" + Hero2.IncAgility.ToString();
            IntelligenceBlock2.Text = Hero2.Intelligence.ToString() + "+" + Hero2.IncIntelligence.ToString();
            DamageBlock2.Text = Hero2.Damage.ToString();
            ArmorBlock2.Text = Hero2.Armor.ToString();
            SpeedBlock2.Text = Hero2.Speed.ToString();
            AttackSpeedBlock2.Text = Hero2.AttackSpeed.ToString();
            if (Hero2 is RangeHero)
            {
                TypeAttackBlock2.Text = ((RangeHero)Hero2).AttackRange.ToString();
                ProjectileBlock2.Text = ((RangeHero)Hero2).ProjectileSpeed.ToString();
            }
            else
            {
                ProjectileBlock2.Text = "";
                TypeAttackBlock2.Text = ((MeleeHero)Hero2).AttackAnimationSpeed.ToString();
            }
        }

        private void UpdateImages2()
        {
            Uri uri = new Uri("pack://application:,,,/SourseImage/HeroImage/" + Hero2.Name + ".png");
            BitmapImage image = new BitmapImage(uri);
            HeroImage2.Source = image;           
        }

        private void Compare()
        {
            if(Controller.DamageCompare(Hero1, Hero2))
            {
                DamageBlock1.Foreground = Brushes.SpringGreen;
                DamageBlock2.Foreground = Brushes.Crimson;
            }
            if (Controller.DamageCompare(Hero2, Hero1))
            {
                DamageBlock2.Foreground = Brushes.SpringGreen;
                DamageBlock1.Foreground = Brushes.Crimson;
            }
            if (Controller.ArmorCompare(Hero1, Hero2))
            {
                ArmorBlock1.Foreground = Brushes.SpringGreen;
                ArmorBlock2.Foreground = Brushes.Crimson;
            }
            if (Controller.ArmorCompare(Hero2, Hero1))
            {
                ArmorBlock2.Foreground = Brushes.SpringGreen;
                ArmorBlock1.Foreground = Brushes.Crimson;
            }
            if (Controller.SpeedCompare(Hero1, Hero2))
            {
                SpeedBlock1.Foreground = Brushes.SpringGreen;
                SpeedBlock2.Foreground = Brushes.Crimson;
            }
            if (Controller.SpeedCompare(Hero2, Hero1))
            {
                SpeedBlock2.Foreground = Brushes.SpringGreen;
                SpeedBlock1.Foreground = Brushes.Crimson;
            }
            if (Controller.AttackSpeedCompare(Hero1, Hero2))
            {
                AttackSpeedBlock1.Foreground = Brushes.SpringGreen;
                AttackSpeedBlock2.Foreground = Brushes.Crimson;
            }
            if (Controller.AttackSpeedCompare(Hero2, Hero1))
            {
                AttackSpeedBlock2.Foreground = Brushes.SpringGreen;
                AttackSpeedBlock1.Foreground = Brushes.Crimson;
            }

            if ((Hero1 is MeleeHero)&&(Hero2 is MeleeHero))
            {
                if(Controller.AnimationAttackCompare((MeleeHero)Hero1,(MeleeHero)Hero2))
                {
                    TypeAttackBlock1.Foreground = Brushes.SpringGreen;
                    TypeAttackBlock2.Foreground = Brushes.Crimson;
                }
                if (Controller.AnimationAttackCompare((MeleeHero)Hero2, (MeleeHero)Hero1))
                {
                    TypeAttackBlock2.Foreground = Brushes.SpringGreen;
                    TypeAttackBlock1.Foreground = Brushes.Crimson;
                }
            }

            if ((Hero1 is RangeHero) && (Hero2 is RangeHero))
            {
                if (Controller.AttackRangeCompare((RangeHero)Hero1,(RangeHero)Hero2))
                {
                    TypeAttackBlock1.Foreground = Brushes.SpringGreen;
                    TypeAttackBlock2.Foreground = Brushes.Crimson;
                }
                if (Controller.AttackRangeCompare((RangeHero)Hero2, (RangeHero)Hero1))
                {
                    TypeAttackBlock2.Foreground = Brushes.SpringGreen;
                    TypeAttackBlock1.Foreground = Brushes.Crimson;
                }

                if (Controller.ProjectileSpeedCompare((RangeHero)Hero1, (RangeHero)Hero2))
                {
                    ProjectileBlock1.Foreground = Brushes.SpringGreen;
                    ProjectileBlock2.Foreground = Brushes.Crimson;
                }
                if (Controller.ProjectileSpeedCompare((RangeHero)Hero2, (RangeHero)Hero1))
                {
                    ProjectileBlock2.Foreground = Brushes.SpringGreen;
                    ProjectileBlock1.Foreground = Brushes.Crimson;
                }
            }
        }

        private void AllDeafault()
        {
            DamageBlock1.Foreground = DamageBlock2.Foreground =
            ArmorBlock1.Foreground = ArmorBlock2.Foreground =
            SpeedBlock1.Foreground = SpeedBlock2.Foreground =
            AttackSpeedBlock1.Foreground = AttackSpeedBlock2.Foreground =
            TypeAttackBlock1.Foreground = TypeAttackBlock2.Foreground = 
            ProjectileBlock1.Foreground = ProjectileBlock2.Foreground =
            Brushes.LightGray;

            Hero1Str.Visibility = Hero1Agi.Visibility = Hero1Int.Visibility =
            Hero2Str.Visibility = Hero2Agi.Visibility = Hero2Int.Visibility =
            Visibility.Hidden;
        }

        private void UpdateData()
        {
            AllDeafault();
            UpdateAttribute1();
            UpdateImages1();
            UpdateAttribute2();
            UpdateImages2();
            UpdateMainAttribute();
            Compare();
        }

        private void UpdateMainAttribute()
        {
            if (Hero1.MainAttribute == 1) Hero1Str.Visibility = Visibility.Visible;
            if (Hero1.MainAttribute == 2) Hero1Agi.Visibility = Visibility.Visible;
            if (Hero1.MainAttribute == 3) Hero1Int.Visibility = Visibility.Visible;
            if (Hero2.MainAttribute == 1) Hero2Str.Visibility = Visibility.Visible;
            if (Hero2.MainAttribute == 2) Hero2Agi.Visibility = Visibility.Visible;
            if (Hero2.MainAttribute == 3) Hero2Int.Visibility = Visibility.Visible;
        }

        private void Move_MouseLeftButtonDown(object sender, MouseButtonEventArgs e)
        {
            DragMove();
        }

        private void Min_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            WindowState = WindowState.Minimized;
        }

        private void Exit_MouseLeftButtonUp(object sender, MouseButtonEventArgs e)
        {
            Close();
        }

        private void HeroCombo1_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Hero1 = Controller.GetHero(HeroCombo1.SelectedItem.ToString());
            UpdateData();
        }

        private void HeroCombo2_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
            Hero2 = Controller.GetHero(HeroCombo2.SelectedItem.ToString());
            UpdateData();
        }
    }
}
