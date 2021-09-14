#include<conio.h>
#include<graphics.h>
void select()
{
  int ching,gd=DETECT,gm;
  int y1,x1;
  initgraph(&gd,&gm,"c:\turboc3\bgi");

  cleardevice();
  setcolor(1);
  outtextxy(x1=70,y1=100,"->");

  outtextxy(50,50,"SELECT A GAME");
  outtextxy(100,100,"MINESWEEPER");
  outtextxy(100,130,"SNAKE");
  while(1)
  {
     ching=getch();
     if(ching==13)
	break;
      else if(ching!=27 || ching!=8)
      {
	if(ching==72 && y1==130)
	{
	   cleardevice();
	   setcolor(1);
	   outtextxy(x1,y1-=30,"->");
	 }
	 if(ching==80 && y1==100)
	 {

	      cleardevice();
	      setcolor(1);
	      outtextxy(x1,y1+=30,"->");
	 }

      }
      if(ching==27 || ching==8)
	select();
      setcolor(15);
      outtextxy(50,50,"SELECT A GAME");
      outtextxy(100,100,"MINESWEEPER");
      outtextxy(100,130,"SNAKE");
   }
   if(y1==100)
	minesweep();
      else if(y1==130)
	 snake();

}
