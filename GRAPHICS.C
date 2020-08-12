#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
void main()
{
int gd=DETECT,gm;
int x,y;
initgraph(&gd,&gm,"C:\\turboc3\\BGI");
x=getmaxx()/2;
y=getmaxy()/2;
setbkcolor(6);
arc(x-10,y,55,70,40);
arc(x+10,y,110,125,40);
delay(500);
ellipse(x-30,y-40,0,360,10,20);
ellipse(x+30,y-40,0,360,10,20);
delay(500);
line(x,y-20,x,y+40);
delay(500);
arc(x,y,200,330,50);
delay(500);
circle(x,y,70);
delay(500);
bar(150,180,200,300);
delay(500);
bar(450,180,500,300);
delay(500);
outtextxy(x-20,y-100,"Divya");
getch();
closegraph();
}