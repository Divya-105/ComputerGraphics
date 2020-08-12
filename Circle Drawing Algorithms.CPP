#include<iostream.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

void Midpoint(int opt);
void Bresenhem(int opt);
void Draw(int x,int y,int Xc,int Yc);
void main()
{
int choice;

char c='y';
while(c=='y')
{
cout<<"1.BRESENHEM circle algorithm\n2.MIDPOINT Circle Algorithm\n";
cout<<"Enter your choice:";
cin>>choice;
switch(choice)
{
case 1:
cout<<"1.Draw one circle\n2.OLYMPIC Symbol\n3.Exit Bresenhem algorithm\n";
cout<<"Enter your choice:";
cin>>choice;
Bresenhem(choice);
break;

case 2:
cout<<"1.Draw one circle\n2.AUDI Symbol\n3.Exit Midpoint algorithm\n";
cout<<"Enter your choice:";
cin>>choice;
Midpoint(choice);
break;
default:
cout<<"Wrong choice..";
}
cout<<"If you want to try again, then press y..\n";
c=getch();
}
getch();
closegraph();
}

void Bresenhem(int opt)
{
int gd=DETECT,gm,r;
float Xc,Yc;
initgraph(&gd,&gm,"C:\\turboc3\\BGI");
switch(opt)
{
case 1:
cout<<"Enter the radius of the circle:";
cin>>r;
cout<<"Enter the centre coordinates:";
cin>>Xc>>Yc;
int x=0,y=r,d=3-2*r;
while(x<=y)
{
Draw(x,y,Xc,Yc);
if(d<=0)
{
d=d+4*x+6;
}
else
{
d=d+4*(x-y)+10;
y=y-1;
}
x++;
}
delay(1000);
cleardevice();
break;

//For drawing olympic symbol
case 2:
cout<<"Enter the radius of the circle:";
cin>>r;
cout<<"Enter the centre coordinates:";
cin>>Xc>>Yc;
int a=Xc;
int b=Yc,j=1;
for(int i=0;i<5;i++)
{
x=0;y=r;d=3-2*r;
while(x<=y)
{
Draw(x,y,Xc,Yc);
if(d<0)
{
d=d+4*x+6;
}
else
{
d=d+4*(x-y)+10;
y=y-1;
}
x++;
}
if(i<2)
{
Xc=Xc+2*(r+(r/10));
}
else
{
Xc=a+(j)*(r+(r/10));
Yc=b+r;
j+=2;
}
if(i==4)
{break;
}
/*if(i%2!=0)
{
Xc=Xc+r;
Yc=Yc+r;
}
else
{
Xc=r+(r/10);
Yc=Yc-r;
}  */
Draw(x,y,Xc,Yc);
}
delay(2000);
cleardevice();
break;

case 3:
return;

default:
cout<<"Wrong choice..\n";
}
}



void Midpoint(int opt)
{
int gd=DETECT,gm,Xc,Yc,r;
initgraph(&gd,&gm,"C:\\turboc3\\BGI");
switch(opt)
{
case 1:
cout<<"Enter the radius of the circle:";
cin>>r;
cout<<"Enter the circle coordinates:";
cin>>Xc>>Yc;
int x=0,y=r,d=1-r;
while(x<=y)
{
x++;
if(d<0)
{
d=d+2*x+3;
}
else
{
d=d+2*(x-y)+5;
y--;
}
Draw(x,y,Xc,Yc);
}
delay(2000);
cleardevice();
break;

case 2:
cout<<"Enter the radius of the circle:";
cin>>r;
cout<<"Enter the circle coordinates:";
cin>>Xc>>Yc;

int i=0;
while(i<4)
{
x=0;y=r;d=1-r;
Draw(x,y,Xc,Yc);
while(x<=y)
{
x++;
if(d<0)
{
d=d+2*x+3;
}
else
{
d=d+2*(x-y)+5;
y--;
}
Draw(x,y,Xc,Yc);
}
Xc=Xc+(2*r-(r/2));
i++;
}

delay(2000);
cleardevice();
break;

case 3:
cout<<"Exiting Midpoint algorithm..\n";
break;

default:
cout<<"Wrong choice..Enter valid choice.\n";
}
}

void Draw(int x,int y,int Xc,int Yc)
{
putpixel(Xc+x,Yc+y,15);
putpixel(Xc-x,Yc+y,15);
putpixel(Xc+x,Yc-y,15);
putpixel(Xc-y,Yc+x,15);
putpixel(Xc+y,Yc-x,15);
putpixel(Xc+y,Yc+x,15);
putpixel(Xc-x,Yc-y,15);
putpixel(Xc-y,Yc-x,15);
}