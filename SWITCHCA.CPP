#include<iostream.h>
#include<conio.h>
void main()
{
 clrscr();
 int z;
 cout<<"enter your choice\n\n";
 cout<<"1.ADTION\t 2.SUBSTRACTION\t 3.MULTIPLICATION\t 4.DIVISION\t\n";
 cin>>z;
 switch(z)
 {
  case 1: cout<<"ADITION\n";
	  int a,b,c;
	  cout<<"enter value of a and b\n";
	  cin>>a>>b;
	  c=a+b;
	  cout<<"\n sum="<<c;
	  break;

  case 2: cout<<"SUBSTRACTION\n";
	  int x,y,r;
	  cout<<"enter value of x and y\n";
	  cin>>x>>y;
	  r=x-y;
	  cout<<"\n sub="<<r;
	  break;

  case 3: cout<<"MULTIPLICATION\n";
	  int p,q,w;
	  cout<<"enter value of p and q\n";
	  cin>>p>>q;
	  w=p*q;
	  cout<<"\n multi="<<w;
	  break;

  case 4: cout<<"division\n";
	  int j,k,l;
	  cout<<"enter value of j and k\n";
	  cin>>j>>k;
	  l=j/k;
	  cout<<"\n divi="<<l;
	  break;

    default : cout<<"select correctoption";
   }
getch();
}



