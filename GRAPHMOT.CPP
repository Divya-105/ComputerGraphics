#include<stdio.h>
#include<conio.h>
#include<graphics.h>
#include<dos.h>

void main()
{
int gd=DETECT,gm;
int x,y,z=10,i;
initgraph(&gd,&gm,"C:\\turboc3\\bgi");

x=getmaxx()/2;
y=getmaxy()/2;

for(i=0;i<10;i++)
{
setcolor(i);
circle(x,y,z);
z+=10;
delay(500);
cleardevice();
}

cleardevice();
getch();
closegraph();
}