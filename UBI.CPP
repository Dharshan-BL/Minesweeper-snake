
#include <graphics.h>
#include <string.h>
#include <iostream.h>
#include <conio.h>
void ubisoft()
{
  int gdriver=DETECT,gmode;
  char ch;
  initgraph(&gdriver, &gmode, "c:/turboc3/BGI");
    floodfill(0,0,15);
  setcolor(0);
  circle(324,224,157);
  circle(324,224,147);
  circle(324,224,135);
  setfillstyle(1,0);
  floodfill(188,224,0);
  floodfill(460,224,0);

 for(int i=20;i<=115;++i)
  arc(293,254,i,i+i,73+i/6);


 for(i=10;i<115;++i)
 arc(293,254,i,i+i,75+i/6);

 circle(310,248,58);
 circle(310,248,49);


 circle(300,260,34);
 circle(300,260,27);

 circle(300,247,15);


 setfillstyle(SOLID_FILL,0);
 floodfill(300,250,0);
 floodfill(270,260,0);
 floodfill(330,260,0);
 floodfill(360,260,0);
 floodfill(260,260,0);
 floodfill(0,0,0);

 settextstyle(BOLD_FONT,HORIZ_DIR,6);
 setcolor(15);
 outtextxy(165,370,"UBISOFT");
 settextstyle(SMALL_FONT,HORIZ_DIR,6);
 outtextxy(504,390,"R");
 circle(507,400,8);

}

