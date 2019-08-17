#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<graphics.h>
#include<dos.h>
#include<math.h>
void main()
{
 struct  time t;
 void drawclock(void);
 void intro(void);
 void sound(void);
 int gdriver=DETECT,gmode;
 initgraph(&gdriver,&gmode,"D:\tc\bgi");
 int i,j,k,s,m,h;
 intro();
 settextstyle(DEFAULT_FONT, HORIZ_DIR, 1);
 drawclock();
 gettime(&t);
 if(t.ti_sec>15)
   s=360-((t.ti_sec-15)*6);
 else
   s=90-(t.ti_sec*6);
 if(t.ti_min>15)
   m=360-((t.ti_min-15)*6);
 else
   m=90-(t.ti_min*6);
 if( (t.ti_hour==0)||(t.ti_hour==1)||(t.ti_hour==2)||(t.ti_hour==3))
    h=90-(t.ti_hour*30)-((t.ti_min/12)*6);
 else if((t.ti_hour>=4)&&(t.ti_hour<=12))
   h=360-((t.ti_hour-3)*30)-((t.ti_min/12)*6);
 else if((t.ti_hour>=13)&&(t.ti_hour<=23))
   h=360-((t.ti_hour-15)*30)-((t.ti_min/12)*6);
 else// if(t.ti_hour==12)
   h=90-((t.ti_hour-12)*30)-((t.ti_min/12)*6);
 for(k=0;k<=12;k++)
 {
  if(h==0)
   h=360;
   delay(1000);
   drawclock();
   for(j=0;j<=60;j++)
   {
     if(m==0)
       m=360;
     setcolor(4);
     sector(320,150,m,m+1,75,75);
     m=m-6;
     delay(1000);
     drawclock();
     for(i=0;i<=60;i++)
     {
     setcolor(4);
     sector(320,150,h,h+3,60,60);
       setcolor(4);
       sector(320,150,m,m+1,75,75);
	if(s==0)
	  s=360;
	  setcolor(1);
	  sector(320,150,s,s+1,80,80);
	sound();
	s=s-6;
	delay(1000);
	drawclock();
      if(kbhit())
	exit(0);
     }
      setcolor(6);
      sector(320,150,h,h+3,60,60);
   }
 }
 getch();
}
void drawclock()
{
 cleardevice();
 setbkcolor(15);
 setcolor(GREEN);
 circle(320,150,80);
 setcolor(BLUE);
 circle(320,150,95);
 circle(320,150,1);
 outtextxy(314,58,"12");
 outtextxy(268,70,"11");
 outtextxy(235,105,"10");
 outtextxy(233,147,"9");
 outtextxy(241,190,"8");
 outtextxy(273,225,"7");
 outtextxy(318,238,"6");
 outtextxy(362,225,"5");
 outtextxy(392,190,"4");
 outtextxy(403,147,"3");
 outtextxy(393,105,"2");
 outtextxy(361,70,"1");
 //outtextxy(302,200,"Poojitha");
}
void intro()
{
 int i;
 int u=installuserfont("TSCR.CHR");
 settextstyle(u,0,7);
 outtextxy(175,100,"Poojitha's");
 outtextxy(250,200,"Clock");
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(380,400,"Loading...");
 for(i=0;i<510;i++)
 {
   setcolor(BLUE);
   rectangle(50,100,50+i,110);
   delay(5);
 }
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(380,400,"Loading...");
 for( i=0;i<510;i++)
 {
   setcolor(WHITE);
   rectangle(50,100,50+i,110);
   delay(5);
 }
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(380,400,"Loading...");
 for(i=0;i<510;i++)
 {
   setcolor(LIGHTMAGENTA);
   rectangle(50,200,50+i,210);
   delay(5);
 }
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(380,400,"Loading...");
 setfillstyle(SOLID_FILL,1);
 //fillellipse(320,205,6,6);
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(380,400,"Loading...");
 for(i=0;i<510;i++)
 {
   setcolor(15);
   rectangle(50,300,50+i,310);
   delay(5);
 }
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(380,400,"Loading...");
 for( i=0;i<510;i++)
 {
   setcolor(2);
   rectangle(50,300,50+i,310);
   delay(5);
 }
 settextstyle(TRIPLEX_FONT, HORIZ_DIR, 1);
 outtextxy(380,400,"Loading...");
 delay(1000);
}
void sound()
{
 sound(2000);
 delay(100);
 nosound();
}
