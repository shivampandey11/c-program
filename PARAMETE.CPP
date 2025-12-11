#include<iostream.h>
#include<conio.h>
void addition(int x, int y)
{
 int sum;
 sum=x+y;
 cout<<"addition:"<<sum;
 }

 void main()
 {
  clrscr();
  int a,b;
  cout<<"enter two digits for addition:\n";
  cin>>a>>b;
  addition(a,b);
  getch();
  }