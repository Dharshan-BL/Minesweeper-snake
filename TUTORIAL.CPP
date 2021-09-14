#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
void  instructions()
{

  char ch[2];
      cleardevice();
  rectangle(50,100,525,250);
//  delay(225);

  rectangle(120,225,270,245);
 // delay(100);
  //down
  rectangle(390,225,410,245);
  ch[0]=(char)25;
  ch[1]='\0';
  outtextxy(392,236,ch);
  //left
  rectangle(368,225,388,245);
  ch[0]=(char)27;
  ch[1]='\0';
  outtextxy(371,227,ch);
  //right
  rectangle(412,225,432,245);
  ch[0]=(char)26;
  ch[1]='\0';
  outtextxy(424,227,ch);
  //up arrow
  rectangle(390,203,410,223);
  ch[0]=(char)24;
  ch[1]='\0';
  outtextxy(392,206,ch);


  //enter
  line(320,148,320,170);
  line(320,148,350,148);
  line(350,148,350,185);
  line(350,185,300,185);
  line(300,185,300,170);
  line(300,170,320,170);
  ch[0]=(char)27;
  ch[1]='\0';
  outtextxy(330,175,ch);
  settextstyle(SMALL_FONT,HORIZ_DIR,4);
  outtextxy(302,172,"Enter");
  line(330,178,343,178);
  line(343,178,343,175);

  //escape
  rectangle(55,105,75,125);
  outtextxy(57,109,"Esc");

  //esc
  setcolor(9);
  circle(65,115,3);
  setfillstyle(1,9);
  floodfill(65,115,9);
  lineto(65,50);
  lineto(145,50);
  settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
  outtextxy(149,35,"PAUSE");

  setcolor(14);
  circle(335,160,4);
  setfillstyle(1,14);
  floodfill(335,160,14);
  lineto(435,160);
  lineto(435,50);
  settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
  outtextxy(380,23,"UNCOVER BLOCK");

  setcolor(4);
  circle(195,235,4);
  setfillstyle(1,4);
  floodfill(195,235,4);
  lineto(195,295);
  lineto(235,295);
  settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
  outtextxy(239,280,"PUT/REMOVE FLAG");

  setcolor(10);
  setfillstyle(1,10);
  circle(400,235,2);
  floodfill(400,235,10);
  lineto(400,255);
  lineto(456,255);


  circle(378,235,2);
  floodfill(378,235,10);
  lineto(378,255);
  lineto(400,255);

  circle(422,235,2);
  floodfill(422,235,10);
  lineto(422,255);

  circle(400,213,2);
  floodfill(400,213,10);
  lineto(400,193);
  lineto(445,193);
  lineto(445,255);
  lineto(500,255);
  lineto(500,350);
  settextstyle(COMPLEX_FONT,HORIZ_DIR,2);
  outtextxy(460,347,"NAVIGATE");

  setcolor(1);
  textcolor(0);
  textbackground(1);

  while(kbhit()==0)
  {


   delay(300);
   gotoxy(20,25);

   int x=wherex();
   int y=wherey();

   cout<<"press any key to continue...";

   delay(300);
   gotoxy(x,y);

   clreol();
   }
 getch();
}