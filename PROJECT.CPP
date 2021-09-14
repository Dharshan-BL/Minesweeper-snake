#include"nopro.cpp"
#include<fstream.h>
#include<iomanip.h>
#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<graphics.h>
#include<string.h>
#include<ctype.h>
#include<math.h>
#include "tutorial.cpp"
#include "instr.cpp"
#include "ubi.cpp"
//global var.
int x,y,i=0,j,lose=0;
//int count1=65;
char ch4,quit;
int row,col;
int overwrite=0;
int nom,now;
float percent;

void cap(float x,float y,int r,int theta)
{


  float x1,y1,x2,y2,x3,y3,x4,y4;
  float ang1,ang2,ang3,ang4;

  ang1=(theta-7)*3.14159265;
  ang1/=180;

  ang2=(theta-4)*3.14159265;
  ang2/=180;

  ang3=(theta+4)*3.14159265;
  ang3/=180;

  ang4=(theta+7)*3.14159265;
  ang4/=180;



  x2=r*cos(ang2);
  y2=r*sin(ang2);

  x3=r*cos(ang3);
  y3=r*sin(ang3);
  if(theta==45)
  {
   x3+=(x+r/6);
   y3+=(y+r/6);
   x2+=(x+r/6);
   y2+=(y+r/6);
  }
  if(theta==135)
  {
   x3+=(x-r/6);
   y3+=(y+r/6);
   x2+=(x-r/6);
   y2+=(y+r/6);
  }

  if(theta==315)
  {
   x3+=(x+r/6);
   y3+=(y-r/6);
   x2+=(x+r/6);
   y2+=(y-r/6);
  }

  if(theta==180)
  {
   x3+=(x-r/4);
   y3+=y;
   x2+=(x-r/4);
   y2+=y;
  }
  if(theta==270)
  {

   x3+=x;
   y3+=(y-r/4);
   x2+=x;
   y2+=(y-r/4);
  }

  if(theta==225)
  {
   x3+=(x-r/6);
   y3+=(y-r/6);
   x2+=(x-r/6);
   y2+=(y-r/6);
  }
  if(theta==0)
  {
   x3+=(x+r/4);
   y3+=y;
   x2+=(x+r/4);
   y2+=y;
  }
  if(theta==90)
  {
   x3+=x;
   y3+=(y+r/4);
   x2+=x;
   y2+=(y+r/4);
  }

  //14
  x1=r*cos(ang1);
  y1=r*sin(ang1);
  x1+=x;
  y1+=y;

  x4=r*cos(ang4);
  y4=r*sin(ang4);
  x4+=x;
  y4+=y;

  line(x1,y1,x2,y2);
  line(x2,y2,x3,y3);
  line(x3,y3,x4,y4);

}

void mines(int h,int k,int r)
{
  //cleardevice();
  setcolor(4);

  circle(h,k,r);

  int n=0;

  if(r>=30)
  {
    float r1,r2;
    r1=r*3;r1/=4;
    r2=r*41.6;r2/=100;
    arc(h,k,90,180,r1);
    arc(h,k,90,180,r2);
    line(h,k-r1,h,k-r2);
    line(h-r1,k,h-r2,k);
    setfillstyle(1,7);
    floodfill((h+h-r1)/2,k-10,4);
  }
  setfillstyle(1,4);
  floodfill(h,k,4);

  for(int i=0;n<8;i+=45)
  {
    cap(h,k,r,i);
    n++;
  }
}


class game{
	    public:
	      int sav;
	      char win_per[5];
	      char no_of_mat[10],win_mat[50];
	      void stats();
	      void save_game();
	    };


void game::stats()
{
  int rst;
  cleardevice();

  percent=100*now;
  percent/=nom;

  gcvt(percent,3,win_per);
  settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
  setcolor(2);
  outtext("Matches played:");
  setcolor(13);
  outtext(no_of_mat);
  setcolor(2);
  outtextxy(0,20,"Matches won :");
  setcolor(13);
  outtextxy(getx()-20,20,win_mat);
  setcolor(2);
  outtextxy(0,40,"Win percentage:");
  setcolor(13);
  outtextxy(getx(),40,win_per);

  outtextxy(200,200,"Reset(R)");


  rst=getch();
  if(rst=='r' || rst=='R')
  {

      strcpy(no_of_mat,"0");
       strcpy(win_mat,"0");
       strcpy(win_per,"00");
       nom=0;
       now=0;
       percent=0;
    save_game();
    stats();
  }
}


class board:public game
{
	char user_brd[30][30];
	int brd[30][30],mine;
	int b,c;
	public:
	    int check();
	    void copy();
	    void pause();
	    void user_interface();
	    void main_menu();
	    void set_cord();
	    void brd_create();
	    void manip(int,int,int);
	    void mode();
	    void bored()
	    {
	     // cout<<b;getch();
	      for(int i=0;i<=b;++i)
	       for(int j=0;j<=c;++j)
		 brd[i][j]=48;
	    }
	    int ret()
	    {
		return mine;
	    }
	    void store(int i)
	    {
		mine=i;
	    }
}player;

void board::pause()
 {
     int x1,y1;
     char ch1,tch;
     settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);//though i have given the font
     cleardevice();			//at times it gouse back to default
     setcolor(15);
     outtextxy(50,50,"Game paused");//sometimes the letter of the words
     outtextxy(100,100,"Resume");   //are over written one on the other then the program stops
     outtextxy(100,130,"Main menu");
     outtextxy(100,160,"Controls");
     outtextxy(100,190,"Stats");
     outtextxy(100,220,"Exit to windows");
     setcolor(1);
     outtextxy(x1=70,y1=100,"->");
     while(1)
     {
       ch1=getch();
       if(ch1==13)
	 break;
       else
       {
	 if(ch1==72 && y1>=130)
	 {
	   cleardevice();
	   setcolor(1);
	   outtextxy(x1,y1-=30,"->");
	 }
	 if(ch1==80 && y1<220)
	 {
	   cleardevice();
	   setcolor(1);
	   outtextxy(x1,y1+=30,"->");
	 }
       }
      setcolor(15);
      outtextxy(50,50,"Game paused");
      outtextxy(100,100,"Resume");
      outtextxy(100,130,"Main menu");
      outtextxy(100,160,"Controls");
      outtextxy(100,190,"Stats");
      outtextxy(100,220,"Exit to windows");
      setcolor(14);
     }
  if(ch1==13)
  {   if(y1==100)
	user_interface();
      else if(y1==130)
	     main_menu();
	   else if(y1==160)
	     instructions();
		else if(y1==190)
		       stats();
		     else
		     {
		       cleardevice();
		       setcolor(15);
		       outtextxy(50,50,"are you sure you wanna exit?");
		       outtextxy(100,100,"yes");
		       outtextxy(100,130,"no");
		       setcolor(1);
		       outtextxy(x1=70,y1=100,"->");
		       while(1)
		       {
			  tch=getch();
			  if(tch==13)
			    break;
			  else
			  {
			    if(tch==72 && y1==130)
			    {
			      cleardevice();
			      setcolor(1);
			      outtextxy(x1,y1-=30,"->");
			    }
			    if(tch==80 && y1==100)
			    {

			      cleardevice();
			      setcolor(1);
			      outtextxy(x1,y1+=30,"->");
			    }
			  }
			  setcolor(15);
			  outtextxy(50,50,"are you sure you wanna exit?");
			  outtextxy(100,100,"yes");
			  outtextxy(100,130,"no");
		       }
		  }
		   if(tch==13)
		     if(y1==100)
		     {
		       sav=1;
		       save_game();
		       exit(0);
		     }
		     else if(y1==130)
			    pause();

   }
}
void flag(int x,int y)
{
   x=x+3;y+=3;
   int poly[8];
   setcolor(14);
   poly[0]=x;
   poly[1]=y;

   poly[2]=x+15;
   poly[3]=y;

   poly[4]=x;
   poly[5]=y+10;

   poly[6]=poly[0];
   poly[7]=poly[1];

   drawpoly(4,poly);
   setfillstyle(1,14);
   fillpoly(4,poly);
   line(x,y,x,y+20);
}

void game::save_game()
{
  ofstream f2("minesweeper.txt");
  f2.write((char*)&player,sizeof(player));
}

int board::check()
{

//  cout<<b;getch()
  for(int i=0;i<=b;++i)
    for(int j=0;j<=c;++j)
      if(user_brd[i][j]!=brd[i][j])
	return 0;
  return 1;


}

void board::main_menu()
{
   int x=180,y=135;
   cleardevice();


   if(sav==1)
   {
     y=90;
     setcolor(15);
     settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
     outtextxy(x,y,"LOAD GAME");
   }
   setcolor(1);
   settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
   outtextxy(x-30,y,"->");

   setcolor(15);
   settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
   outtextxy(x,135,"NEW GAME");


   settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
   outtextxy(x,180,"STATS");

   settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
   outtextxy(x,225,"CONTROLS");

   settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
   outtextxy(x,270,"TUTORIAL");


   settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
   outtextxy(x,315,"CHANGE GAME");

   settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
   outtextxy(x,360,"EXIT TO WINDOWS");



   while(1)
   {
       ch4=getch();
       if(ch4==13)
	 break;
       else
       {

	 if(ch4==72 )
	 {
	   cleardevice();
	   setcolor(1);
	   settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	   cleardevice();
	   if(sav==1 && y==135 || y>135)
	     outtextxy(x-30,y-=45,"->");
	   else
	     outtextxy(x-30,y,"->");
	 }


	 if(ch4==80 && y<360)
	 {
	   cleardevice();
	   setcolor(1);
	   settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	   cleardevice();
	   outtextxy(x-30,y+=45,"->");
	 }

	 if(sav==1)
	 {
	   setcolor(15);
	   settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
	   outtextxy(x,90,"LOAD GAME");
	 }
	 setcolor(15);
	 settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
	 outtextxy(x,135,"NEW GAME");

	 settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
	 outtextxy(x,180,"STATS");

	 settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
	 outtextxy(x,225,"CONTROLS");

	 settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
	 outtextxy(x,270,"TUTORIAL");

	 settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
	 outtextxy(x,315,"CHANGE GAME");

	 settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);
	 outtextxy(x,360,"EXIT TO WINDOWS");

       }
   }

   if(y==180)
   {
      player.stats();
      main_menu();
   }

   else if(y==135)
	  {
	    mode();
	    brd_create();
	    set_cord();
	   }

	   else if(y==225)
		{
		  instructions();
		  main_menu();
		}
		else if(y==90)
		     {

		      user_interface();
		     }
		     else if(y==270)
			  {
			     rules();    getch();
			     main_menu();
			  }
			  else if(y==315)

			       else
				   exit(0);

}

void board::copy()
{
  if(col-1>=0 && row-1>=0)
    if(user_brd[col-1][row-1]==' ')
    {
      user_brd[col-1][row-1]=(char)brd[col-1][row-1];
      if(brd[col-1][row-1]==48)
      {
	col--;row--;
	copy();
	col++;row++;
      }
    }
    if(col-1>=0)
      if(user_brd[col-1][row]==' ')
      {
	user_brd[col-1][row]=(char)brd[col-1][row];
	if(brd[col-1][row]==48)
	{
	  col--;
	  copy();
	  col++;
	}
      }
     if(col-1>=0 && row+1<player.b+1)
       if(user_brd[col-1][row+1]==' ')
       {
	 user_brd[col-1][row+1]=(char)brd[col-1][row+1];
	 if(brd[col-1][row+1]==48)
	 {
	   col--;row++;
	   copy();
	   col++;row--;
	 }
       }
       if(row-1>=0)
	 if(user_brd[col][row-1]==' ')
	 {
	   user_brd[col][row-1]=(char)brd[col][row-1];
	   if(brd[col][row-1]==48)
	   {
	     row--;copy();
	     row++;
	   }
	 }
       if(row+1<player.b+1)
	 if(user_brd[col][row+1]==' ')
	 {
	   user_brd[col][row+1]=(char)brd[col][row+1];
	     if(brd[col][row+1]==48)
	     {
	       row++;
	       copy();
	       row--;
	     }
	 }
       if(col+1<player.b+1 && row-1>=0)
	 if(user_brd[col+1][row-1]==' ')
	 {
	   user_brd[col+1][row-1]=(char)brd[col+1][row-1];
	   if(brd[col+1][row-1]==48)
	   {
	     row--;col++;
	     copy();
	     row++;col--;
	   }
	 }
       if(col+1<player.b+1)
	 if(user_brd[col+1][row]==' ')
	 {
	   user_brd[col+1][row]=(char)brd[col+1][row];
	   if(brd[col+1][row]==48)
	   {
	     col++;
	     copy();
	     col--;
	   }
	 }
       if(col+1<player.b+1 && row+1<player.b+1)
	 if(user_brd[col+1][row+1]==' ')
	 {
	   user_brd[col+1][row+1]=(char)brd[col+1][row+1];
	   if(brd[col+1][row+1]==48)
	   {
	     col++;row++;
	     copy();
	     col--;row--;
	   }
	 }

}

void board::manip(int x,int y,int game)
{
  col=y/25-1;
  row=x/25-1;
  if(game==1)
  {

    if(brd[col][row]==48)
      copy();
    else if(brd[col][row]==15)
	   lose++;
   user_brd[col][row]=(char)brd[col][row];

  }

  if(game==0)
  {
    if(user_brd[col+1][row+1]==15)
    {
      user_brd[col+1][row+1]=32;
      mine++;
    }
    else if(user_brd[col+1][row+1]==32)
	 {
	   user_brd[col+1][row+1]=15;
	   mine--;
	 }


  }


}

void board::mode()
{
  int x=120,y=135;
  char ch4,m,back[]="<<BACK";
  do{

      i=0;

      cleardevice();
      settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
      setcolor(1);
      outtextxy(x-30,y,"->");

      settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
      setcolor(4);
      outtextxy(20,20,back);
      setcolor(15);
      settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
      outtextxy(x,y,"1.Casual");
      outtextxy(x,y+30,"2.Hardcore");
      outtextxy(x,y+60,"3.Insane");
      settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
      setcolor(8);
      outtextxy(400,375,"QUIT");

      while(1)
      {
	ch4=getch();
	if(ch4==13)
	  break;
	else  if(ch4!=27 && ch4!=8)
	      {
		if((ch4==72) && (y==165 || y==195 || y==375))
		{

		  cleardevice();
		  settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		  setcolor(1);
		  if(y==375)
		    outtextxy(x-30,y=195,"->");
		  else
		    outtextxy(x-30,y-=30,"->");
		 }
		 if((ch4==80) &&  (y<=195 || y==375))
		 {

		    cleardevice();
		    setcolor(1);
		    settextstyle(SANS_SERIF_FONT,HORIZ_DIR,3);
		    if(y==195 || y==375)
		      outtextxy(370,y=375,"->");
		    else if(y<195)
			   outtextxy(x-30,y+=30,"->");
		  }
		  settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
		  if(y==135)
		    outtextxy(350,105,"9X9 tile grid - 10 mines");
		  if(y==165)
		    outtextxy(350,105,"16X16 tile grid - 40 mines");

		  if(y==195)
		    outtextxy(350,105,"16X30 tile grid - 99 mines");
		  settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
		  setcolor(4);
		  settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
		  outtextxy(20,20,back);
		  settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
		  setcolor(15);
		  outtextxy(x,135,"1.Casual");
		  outtextxy(x,165,"2.Hardcore");
		  outtextxy(x,195,"3.Insane");
		  settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
		  setcolor(8);
		  outtextxy(400,375,"QUIT");
	      }
	      else
		  main_menu();

      }

      int x1,y1;

      if(y==375 && ch4==13)
      {

	cleardevice();
	setcolor(15);
	settextstyle(SIMPLEX_FONT,HORIZ_DIR,3);
	outtextxy(50,50,"are you sure you wanna exit?");

	outtextxy(100,100,"yes");
	outtextxy(100,130,"no");
	setcolor(1);
	outtextxy(x1=70,y1=100,"->");
	while(1)
	{
	  ch4=getch();
	  if(ch4==13)
	    break;
	  else
	  {
	    if(ch4==72 && y1==130)
	    {

	      cleardevice();
	      setcolor(1);
	      outtextxy(x1,y1-=30,"->");
	    }
	    if(ch4==80 && y1==100)
	    {

	      cleardevice();
	      setcolor(1);
	      outtextxy(x1,y1+=30,"->");
	    }

	  }
	  setcolor(15);
	  outtextxy(50,50,"are you sure you wanna exit?");
	  outtextxy(100,100,"yes");
	  outtextxy(100,130,"no");
	}
      }
      if(y1==100)
	exit(0);
      else if(y1==130)
	 mode();




      if(y==135)
      {
	sav=0;
	mine=10;
	player.b=9; player.c=9;
      }
      else if(y==165)
	   {
	     sav=0;
	     mine=40;
	     player.b=16; player.c=16;
	   }
	   else if(y==195)
		{
		  sav=0;
		  mine=199;
		  player.b=16;
		  player.c=20;
		}
		else
		  i++;
    }while(i!=0);
}
void board::brd_create()
{
  bored();
  srand(time(0));
  int z=mine;
  do{
      x=random(b+1);
      y=random(c+1);

      if(brd[x][y]!=15)
      {
	z--;
	brd[x][y]=15;
	if(brd[x][y-1]!=15)
	  if(y-1>=0)
	    brd[x][y-1]++;

	if(brd[x-1][y-1]!=15)
	  if(x-1>=0 && y-1>=0)
	    brd[x-1][y-1]++;

	if(brd[x-1][y]!=15)
	  if(x-1>=0)
	    brd[x-1][y]++;

	if(brd[x-1][y+1]!=15)
	  if(x-1>=0 && y<=c+1)
	    brd[x-1][y+1]++;
	if(brd[x][y+1]!=15)
	  if(y+1<=c+1)
	    brd[x][y+1]++;

	if(brd[x+1][y+1]!=15)
	  if(y+1<c+1 && x+1<b+1)
	    brd[x+1][y+1]++;

	if(brd[x+1][y]!=15)
	  if(x+1<b+1)
	    brd[x+1][y]++;

	if(brd[x+1][y-1]!=15)
	  if(x+1<b+1 && y-1>=0)
	   brd[x+1][y-1]++;
      }
    }while(z>0);
}


void board::set_cord()
{
  //User's brd
  for(int i=0;i<30;++i)
    for(int j=0;j<30;++j)
      user_brd[i][j]=' ';

 }
void board::user_interface()
{

 cleardevice();
 int left,top,bottom,right;
 int l,t,bot,r;
 static int entry=1;


 left=25;
 top=25;
 right=(player.c+1)*25;
 bottom=(player.b+1)*25;

 char ch4;
 int x,y;

 for(t=25;t<=bottom;t+=25)
   for(l=25;l<=right;l+=25)
   {
     r=l+25;
     bot=t+25;

     setcolor(15);
     rectangle(l,t,r,bot);
     settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,3);
   }
   for(int i=0;i<=player.b;++i)
     for(int j=0;j<=c;++j)
     {
       char temp[2];
       temp[0]=user_brd[i][j];
       temp[1]='\0';
       settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,3);
       setcolor(4);
       outtextxy(j*25+28,i*25+25,temp);
       if((int)temp[0]==15)
	 flag(j*25+28,i*25+25);
     }


 setcolor(2);
 rectangle(25,25,50,50);
   getch();
 y=25;x=25;
 ch4=0;

 lose=0;

 do
 {
   ch4=getch();

   if(ch4==13)
     manip(x,y,1);      //enter to reveal
   else if(ch4==32)
	  manip(x-25,y-25,0);   // space to mark
	else
	{


	  if(ch4==75)
	  {
	    if(x>25)
	      x-=25;
	    else
	      x=bottom;
	  }
	  if(ch4==77)
	  {
	    if(x<bottom)
	      x+=25;
	    else
	      x=25;
	  }
	  if(ch4==72)
	  {
	    if(y>25)
	      y-=25;
	    else
	      y=bottom;
	  }
	  if(ch4==80)
	  {
	    if(y<bottom)
	      y+=25;
	    else
	      y=25;
	  }


	}
   if(ch4==27)
     pause();


   cleardevice();

   for(t=25;t<=bottom;t+=25)
    for(l=25;l<=right;l+=25)
    {
      r=l+25;
      bot=t+25;
      setcolor(15);
      rectangle(l,t,r,bot);
    }

  setcolor(2);
  rectangle(x,y,x+25,y+25);



  for(int i=0;i<=b;++i)
     for(int j=0;j<=c;++j)
     {
       char temp[2];
       temp[0]=user_brd[i][j];
       temp[1]='\0';
       settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,3);
       setcolor(4);
       outtextxy(j*25+28,i*25+25,temp);
       if((int)temp[0]==15)
	 flag(j*25+28,i*25+25);
     }
  settextstyle(SIMPLEX_FONT,HORIZ_DIR,4);

  char acr[10];
  itoa(player.ret(), acr , 10);

  if(check()!=0)
 {
   now+=1;
   for(int i=0;i<250;i++)
   {
     int lvl;
     cleardevice();
     setfillstyle(1,3);
     bar(25,i+25,275,25+i+3);
     for(t=25;t<=bottom;t+=25)
    for(l=25;l<=right;l+=25)
    {
      r=l+25;
      bot=t+25;
      setcolor(15);
      rectangle(l,t,r,bot);
    }
    lvl=i/25;
    for(int creed=0;creed<=lvl;++creed)
     for(int j=0;j<=c;++j)
     {
       char temp[2];
       temp[0]=(char)brd[creed][j];
       temp[1]='\0';
       settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,3);
       setcolor(2);
       outtextxy(j*25+28,creed*25+25,temp);
       setcolor(1);
       if((int)temp[0]==15)
	 mines((j+1)*25+12,(creed+1)*25+12,6);
     }

    delay(30);

   }
   cout<<"you win";
   getch();
   itoa(now,player.win_mat,10);
   nom++;
   itoa(nom,player.no_of_mat,10);
   break;
 }


  if(lose==1)
  {
    cleardevice();


    for(t=25;t<=bottom;t+=25)
    for(l=25;l<=right;l+=25)
    {
      r=l+25;
      bot=t+25;
      setcolor(15);
      rectangle(l,t,r,bot);
    }
    setfillstyle(CLOSE_DOT_FILL,15);
    floodfill(x+12,y+12,15);
    setcolor(10);
    rectangle(x,y,x+25,y+25);
    for(int i=0;i<=b;++i)
     for(int j=0;j<=c;++j)
     {
       char temp[2];
       temp[0]=(char)brd[i][j];
       temp[1]='\0';
       settextstyle(TRIPLEX_SCR_FONT,HORIZ_DIR,3);
       setcolor(8);
       outtextxy(j*25+28,i*25+25,temp);
       setcolor(1);
       if((int)temp[0]==15)
	 mines((j+1)*25+12,(i+1)*25+12,6);
     }
     getch();

   nom++;
   itoa(nom,player.no_of_mat,10);
   break;
  }
 }while(1);

}

void minesweep()
{
   //int gdriver=DETECT,gmode;
   //initgraph(&gdriver, &gmode, "c:/Turboc3/BGI");


  cleardevice();

 settextstyle(SIMPLEX_FONT,HORIZ_DIR,6);
 delay(1500);


 ifstream f1("minesweeper.txt");
 f1.read((char*)&player,sizeof(player));


  for(int k=1;k<=4;++k)
   {
     j=i=280;
     for(i;i>=0 && j<=getmaxx();i--,j++)
     {

       cleardevice();
       delay(10);
       setcolor(k);
       rectangle(i,i,j,j);
     }
   }

   char title[]={"MINESWEEPER"};
   char ac3[20];
   ac3[0]='\0';
   for(int i=200;i<450;i+=10)
   {
     cleardevice();
     setcolor(15);
     static int j=0;
     for(j;j<(i-200)/20;++j)
    {
       ac3[j]=title[j];
       ac3[j+1]='\0';
       settextstyle(BOLD_FONT,HORIZ_DIR,3);
       outtextxy(100,200,ac3);

     }
     mines(i,200,60);
     delay(400);
     if(i+10>450)
       break;

   }
   delay(3000);
   char ch4,regame;
   do
   {
      nom=atoi(player.no_of_mat);
      now=atoi(player.win_mat);
      player.main_menu();

      cleardevice();


      itoa(nom,player.no_of_mat,10);
      player.user_interface();


      cleardevice();
      if(lose!=0)
	cout<<"you lose :(";



      cout<<"do you wanna play again? - yes(y) or no(n)";
      nom++;
      cin>>regame;
      player.sav=0;
      player.save_game();
   }while(toupper(regame)=='Y');
}

