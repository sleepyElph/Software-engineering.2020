   M S B A M L   `   `   `  ����I  EExpenceManager, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null/clr-namespace:ExpenceManagerExpenceManager  5   	       ExpenceManager.MainWindow   5   	   \ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35e aSystem.Windows.Controls.Ribbon, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35F 9http://schemas.microsoft.com/winfx/2006/xaml/presentation     5   	   R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5   	   @d2http://schemas.microsoft.com/expression/blend/2008     5   	   Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5   	   .localclr-namespace:ExpenceManager     5   	     � Icon$q  kC:\Users\Тыща\Desktop\ПРИНЖ_КР\ExpenceManager-master\ExpenceManager\Resources\PieDiagramIcon.png��5   	    � Title$ Expence manager��5	   	   $	��600��5
   	   $
��1300��5   	   .��5      � -   5         �Name$ MainGrid��5      $
|�True��5      ���#6C2680 � ColumnDefinitions 5   
   �� 5      $
��Auto �6   �� 5      $��0.25* �6   �� 5      .+�5   
   � $��0��6    K� ZIndex$ 10��6    � RowDefinitions 5      �� 5      $
��Auto �6    �� 5      .+�5      �� -   5         ��Name$ 	AddButton��5      $��0��5      $
��Left=�5         ImageSquareButton#��[  5       .��5"      �� $q��kC:\Users\Тыща\Desktop\ПРИНЖ_КР\ExpenceManager-master\ExpenceManager\Resources\AddExpenceIcon.png��6   5#      �� 5%      $��1��6   $	��Top=�5&      $��6,20,6,4q�5'       �� Orientation$ 
Horizontal=�5(      .+�5*      �� -   5         ��Name$ 
UploadIcon��5*      $m��gC:\Users\Тыща\Desktop\ПРИНЖ_КР\ExpenceManager-master\ExpenceManager\Resources\UploadIcon.png��5+      	 � ToolTip$	 	Load from��5,      $��30��5-      $��30��6'   �� 5/      -   5        
 ��Name$
 LoadFromComboBox��5/        ComboBox#��[ 50      .@�52      �� 
 � Tag$	 TXT��6#   $��From txt��55   0   	 56      �� 57      .+�58   "   �� Watch sample!6;   �� 59   "   $m��gC:\Users\Тыща\Desktop\ПРИНЖ_КР\ExpenceManager-master\ExpenceManager\Resources\ExportIcon.png��6(   5:      5<      �� 5=      $ EXCEL��6#   .��6/   
From excel6;   5>      5@      �� 5B      $��1��6   $��Center=�5C      $ 
Horizontal=�5D      $��6,10,6,4q�5E      .+�5G      �� $m��gC:\Users\Тыща\Desktop\ПРИНЖ_КР\ExpenceManager-master\ExpenceManager\Resources\ExportIcon.png��6   $	 	Export to��5H      ��5I      ��  �� ElementName$ 
UploadIcon�� �� Path$ 	MaxHeight���5J      �� $ 
UploadIcon��$ MaxWidth��� 5L      -   5        $��ExportComboBox��5L      #��[ 5M      .@�5O      �� $ EXCEL��6#   .��6/   
To excel69   5P      5R      5T      &   System.Windows.Controls.Calendar  5V   
   -   5          Name$ ManagerCalendar��5V      $��1��5W      $��	20,20,0,0q�5X      ���#E999FF   SelectionMode$ MultipleRange=�5Z         IsTodayHighlighted$ False��5[      $ 10��5]      �� 5_   
   ���#D84DFF$��0��6&   $��2��66   $��1,2,3,2q�6J   �� 5b   
   -   5         ��Name$ LoadingTextBlockAnimation��5b      $��Center=�5c      $��Center=�5d      $y�	Collapsed=�5e      $��25(�5f      $��0��5g      $
��Jopa��5h      $��3��5i      5j      5k      