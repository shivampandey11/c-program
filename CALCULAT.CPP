#include<stdio.h>
#include<conio.h>
void sum()//function difinition
{
int a,b,c ;
printf("\t\t\t ADDITION\n");
printf("\n enter value of a and b\n");
scanf("%d%d",&a,&b);
c=a+b;
printf("\n sum=%d",c);
}
void sub()//function difinion 2
{
int a,b,c ;
printf("\t\t\t SUBTRACTION\n");
printf("\n enter value of a and b\n");
scanf("%d%d",&a,&b);
c=a-b;
printf("\ndiffrence=%d",c);
}
void multi()//function difinition3
{
int a,b,c ;
printf("\t\t\t multiplication\n");
printf("\n enter value of a and b\n");
scanf("%d%d",&a,&b);
c=a*b;
printf("\nproduct=%d",c);
}
void main()
{
clrscr();
sum(); //function calling 1
sub();//function calling 2
multi();//function calling 3
getch();
}