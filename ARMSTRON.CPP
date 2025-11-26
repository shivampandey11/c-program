#include<stdio.h>
#include<conio.h>
#include<math.h>
void main()
{
clrscr();
int m,n,r,s=0;
printf("enter any number\n");
scanf("%d",&n);
m=n;
while(n>0)
{
r=n%10;
s=s+pow(r,3);
n=n/10;
}
if(s==m)
{
printf("it's a armstrong\n");
}
else
{
printf("it's a not armstrong\n");
}
getch();
}