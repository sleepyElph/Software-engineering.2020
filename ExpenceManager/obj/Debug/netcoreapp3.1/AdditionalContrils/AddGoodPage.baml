   M S B A M L   `   `   `  ����I  EExpenceManager, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullU/clr-namespace:ExpenceManager.AdditionalContrils!ExpenceManager.AdditionalContrils  5      3    -ExpenceManager.AdditionalContrils.AddGoodPage   5      \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      Alocal/clr-namespace:ExpenceManager.AdditionalContrils     5        N� Title$  Add good��5      $	��400��5	      $	��250��6    N� ShowsNavigationUI$ False��5
      .��5      � -   5         �Name$ MainGrid��5      ���#D84DFF$
|�True��5       � ColumnDefinitions 5   
   �� 5      �� 5       � RowDefinitions 5   
   �� 5      �� 5      �� 5      �� 5      .+�5   
   �� -   5         ��Name$ FrameBorder��5      $��4,0,4,0q�5      ���#6C2680$y�Hidden=�5       $��Center=�5!      $��0��5"      $��1��5#      $��2��5$      $��0q�5%      ._�5&       � -   5          �Name$ NewGoodTypeFrame��5&      $��0q�5'      $��2q�5(      $��Stretch=�5)      $��Stretch=�5*      5+      �� 5-   
   $��0��6   $��0��6"   $
��Left=�5.      .+�5/      �� $��Product type��6      OnAdditionTextBlock#��[  6,   �� 51      -   5         ��Name$ TypeComboBox��51        ComboBox#��[ 52      $��Stretch=�53      .@�55      �� 
 � Tag$ NewItem��6   .��6-   New62   56      57      �� 59   
   $��0��6   $��1��6"   $
��Left=�5:      .+�5;      �� $
��Name��6   #��[  6$   �� 5=      -   5        	 ��Name$	 NameTextBox��5=      $��Stretch=�5>        OnAdditionTextBox#��[ 5?      5@      5B      �� 5D   
   $��1��6   $��1��6"   $
��Left=�5E      .+�5F      �� $��Price��6   #��[  6%   �� 5H      -   5        $	 PriceTextBox��5H      $��Stretch=�5I      #��[ 5K      5M      �� 5O   
   $��2��6   $��1��6"   $
��Left=�5P      .+�5Q      �� $��Amount��6   #��[  6&   �� 5S      -   5        $	 AmountTextBox��5S      $��Stretch=�5T      #��[ 5V      5X      �� 5Z   
   -   5        
 ��Name$
 	AddButton��5Z      $��0��5[        CircleImageButton#��[ 5]      $��3��5^      .��5_      �� $j��dC:\Users\Тыща\Desktop\ПРИНЖ_КР\ExpenceManager-master\ExpenceManager\Resources\AddIcon.png��6   5`      5b      5c      