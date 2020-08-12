#include<iostream.h>
#include<conio.h>
#include<graphics.h>
#include<math.h>
#include<dos.h>

void ddaline(int ch1);
void bresenhem(int ch2);
void main()
{
int gd=DETECT,gm,i;
float x,xend,p,y,x1,y1,x2,y2,t;
float wx,wy,m,dx,dy,steps,xinc,yinc;
int choice,ch1,ch2;
initgraph(&gd,&gm,"c:\\turboc3\\BGI");
char c='y';
while(c=='y')
{
cout<<"Choose your algorithm:\n1.DDA\n2.Bresenhem\n3.Exit\n";
cin>>choice;
switch(choice)
{
case 1:
cout<<"Give the line type:\n1.Thin\n2.Dotted\n3.Exit\n";
cin>>ch1;
ddaline(ch1);
break;
case 2:
cout<<"Give the line type:\n1.Thin\n2.Thick\n3.Exit\n";
cin>>ch2;
bresenhem(ch2);
break;
case 3:
cout<<".....Program exited.....\n";
break;
default:
cout<<"Wrong choice.Please give another choice.\n";
}
cout<<"Do you want to try again then press y.. or else press any other key..\n";
c=getch();
}
closegraph();
getch();
}

void ddaline(int ch1)
{
int gd=DETECT,gm,i;
float x,y,x1,y1,x2,y2,dx,dy,steps,xinc,yinc;
initgraph(&gd,&gm,"c:\\turboc3\\BGI");
switch(ch1)
{
case 1:
cout<<"Drawing thin line...\n";
cout<<"Enter endpoint coordinates:\n";
cout<<"Enter starting point:\n";
cin>>x1>>y1;
cout<<"Enter ending point:\n";
cin>>x2>>y2;
dx=abs(x2-x1);
dy=abs(y2-y1) ;

if(dx >=dy)
   steps=dx;
else
   steps=dy;

xinc=dx/steps;
yinc=dy/steps;
x=x1;
y=y1;
putpixel(x,y,15);
for(i=1;i<steps;i++)
{
 x=x+xinc;
 y=y+yinc;
 x1=x+0.5;
 y1=y+0.5;
 putpixel(x1,y1,15);
}
delay(1000);
cleardevice();
break;

case 2:
cout<<"Drawing dotted line...\n";
cout<<"Enter endpoint cocordinates\n";
cout<<"Enter starting point:\n";
cin>>x1>>y1;
cout<<"Enter ending point:\n";
cin>>x2>>y2;
dx=abs(x2-x1);
dy=abs(y2-y1) ;

if(dx >=dy)
   steps=dx;
else
   steps=dy;

xinc=dx/steps;
yinc=dy/steps;
x=x1;
y=y1;
putpixel(x,y,15);
for(i=1;i<steps;i++)
{
 x=x+xinc;
 y=y+yinc;
 x1=x+0.5;
 y1=y+0.5;
 if(i%2==0)
 {
 putpixel(x1,y1,15);
 }
}
delay(1000);
cleardevice();
break;

case 3:
cout<<"Exiting DDA algorithm..\n";
break;
default:
cout<<"Oops.! Wrong choice...\n";
}
}

void bresenhem(int ch2)
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"c:\\turboc3\\BGI");
switch(ch2)
{
case 1:
cout<<"Drawing bresenhem thin line...\n";
int dx,dy,x,y,xend,p;
float xa,xb,ya,yb;
cout<<"Enter endpoint coordinates:\n";
cout<<"Enter starting point:\n";
cin>>xa>>ya;
cout<<"Enter ending point:\n";
cin>>xb>>yb;
dx=abs(xa-xb);
dy=abs(ya-yb);
p=2*dy-dx;

if(xa>xb)
{
x=xb;
y=yb;
xend=xa;
}
else
{
x=xa;
y=ya;
xend=xb;
}

putpixel(x,y,1);

while(x<xend)
{
x=x+1;
if(p<0)
{
p=p+2*dy;
}
else
{
y=y+1;
p=p+2*(dy-dx);
}
putpixel(x,y,15);
}
delay(1000);
cleardevice();
break;
case 2:
cout<<"Drawing Bresenhem thick line...\n";
float x1,x2,wx,wy,y1,y2,m;
int i,t;
cout<<"Enter the endpoint coordinates:\n";
cout<<"Enter starting point:\n";
cin>>x1>>y1;
cout<<"Enter ending point:\n";
cin>>x2>>y2;
cout<<"enter the thickness:\n";
cin>>t;
line(x1,y1,x2,y2);
if((y2-y1)/(x2-x1) < 1)
{
wy=(t-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*fabs(x2-x1));
for(i=0;i<wy;i++)
{
line(x1,y1-i,x2,y2-i);
line(x1,y1+i,x2,y2+i);
}
}
else
{
wx=(t-1)*sqrt(pow((x2-x1),2)+pow((y2-y1),2))/(2*fabs(y2-y1));
for(i=0;i<wx;i++)
{
line(x1-i,y1,x2-i,y2);
line(x1+i,y1,x2+i,y2);
}
}
cout<<"This is the line of thickness "<<t<<".\n";
delay(1000);
cleardevice();

break;
case 3:
cout<<"Exiting Bresenhem algorithm...\n";
break;
default:
cout<<"Oops..! Wrong choice..!\n";
}
}

