   M S B A M L   `   `   `  ����I  EExpenceManager, Version=1.0.0.0, Culture=neutral, PublicKeyToken=nullU/clr-namespace:ExpenceManager.AdditionalContrils!ExpenceManager.AdditionalContrils  5   	   9    3ExpenceManager.AdditionalContrils.AddPurchaseWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   Alocal/clr-namespace:ExpenceManager.AdditionalContrils     5   	     � Icon$q  kC:\Users\Тыща\Desktop\ПРИНЖ_КР\ExpenceManager-master\ExpenceManager\Resources\AddExpenceIcon.png��5   	    � Title$ Purchase��5	   	    � WindowStartupLocation$ CenterScreen=�5
   	   $	��520��5   	   $	��890��5   	   $	��520��5   	   $	��890��5   	   .��5      � -   5         �Name$ MainGrid��5      ���#D84DFF$
|�True��5       � ColumnDefinitions 5   
   �� 5      $��6875* �6   �� 5      $��3125* �6    � RowDefinitions 5   
   �� 5      $	��88* �6   �� 5      $	��12* �6   .+�5   
   &   System.Windows.Controls.DataGrid  -   5          Name$ GoodsDataGrid��5      $��0��5       ���#E999FF$��0��5"         AutoGenerateColumns$ False��5#         Columns 5$      0  *System.Windows.Controls.DataGridTextColumn  5%      ,  &System.Windows.Controls.DataGridColumn	   Header$
	 Item��6%   1  +System.Windows.Controls.DataGridBoundColumn
   Binding
 63   ��  �� Path$
 Name�  5&      $	 Amount��6%   
 65   �� $ Amount�  5'      $	 Price��6%   
 64   �� $ Price�  5(      $	 Total price��6%   
 6:   �� $ GetTotal�5*      �� 5,   
   $��0��6   ���#6C2680$��1��5.      ._�5/       � -   5          �Name$ TheAddPageFrame��5/      $��8q�50        � NavigationUIVisibility$ Hidden=�51      $��Stretch=�52      $��Stretch=�53      54      �� 57   
    �� Orientation$ 
Horizontal=�6   $��1��58      $��Center=�59      $��Right=�5:      $��0��5;      .+�5<      �� $��Total: ��6    �� TextAlignment$ Right=�5=         OnAdditionTextBlock#��[  5>      �� 5?      -   5         ��Name$ TotalPriceTextBlock��5?      $
 Left=�5@      #��[  5A      5B      �� 5D   
   -   5         ��Name$ ConfirmButton��5D      $��1��5F      $��1��5G        ImageSquareButton#��[ 5H      $
��Left=�5I      $��50��5J      $��50��5K      .��5L      �� $q��kC:\Users\Тыща\Desktop\ПРИНЖ_КР\ExpenceManager-master\ExpenceManager\Resources\AddExpenceIcon.png��6   5M      5N      5P      