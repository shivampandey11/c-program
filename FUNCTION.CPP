
  #include<stdio.h>
  #include<conio.h>
  void show (int m,int &n)
  {
   m++;
   n--;
   }
   void main()
   {
   int x=10,y=8;
   clrscr();
   show(x,y);
   printf("%d \t %d",x,y);
   getch();
   }
