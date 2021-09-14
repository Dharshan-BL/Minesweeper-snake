#include<ctype.h>
#include<string.h>
#include<graphics.h>
#include<iostream.h>
#include<conio.h>
#include<dos.h>
#include<stdlib.h>
#include<process.h>
#include<stdio.h>
#include<fstream.h>

char ch='d';
int len=4,count=0,maxx=500,maxy=300;

class snake{
	    public:
	      void level();
	      void init();
	      int check_limits();
	      int intersect();
	      void check();
	      void check1();
	      void disp();
	      void food();
	      void move();
	      void menu();
	      int a[50][2],fpos[1][2];
	    }s;


class scr{
	  public:
	    char name[100];
	    int hscore;
	    void score_calc();
	    void store();
	    void display();
	    scr();
	}nw;
void scr::display()
{
  int cnt=0;
  scr max;
  ifstream f2("score.dat",ios::binary);
  if(f2)
  {
  while(f2.read((char*)&nw,sizeof(nw)))
  {
      if(cnt==0)
      max=nw;
      if(max.hscore<nw.hscore)
	max=nw;
      cnt++;

  }
  cleardevice();
  gotoxy(30,8);
  cout<<"HIGHSCORE";
  gotoxy(30,10);
  cout<<"name:"<<max.name<<endl;
  gotoxy(30,11);
  cout<<"highscore:"<<max.hscore<<endl;
  getch();
  s.menu();
  }
  else
  {
      cleardevice();
      gotoxy(30,0);
      cout<<"ERROR 404";

      gotoxy(26,8);
      cout<<" Entries not found";
      getch();
      s.menu();
  }


}

scr::scr()
{
 hscore=0;

 strcpy(name,"\0");
}
void  scr::score_calc()
{
  int count=len-4;

  hscore=count*5;
}


void scr::store()
{
  scr temp;
  temp.score_calc();
  scr max;
  int cnt=0;
  ifstream f2("score.dat",ios::binary);
  if(f2)
  {
  while(f2.read((char*)&nw,sizeof(nw)))
  {
      if(cnt==0)
	max=nw;
      if(max.hscore<nw.hscore)
	max=nw;
      cnt++;

  }
  }
  if(temp.hscore>=max.hscore)
  {
  ofstream f1("score.dat",ios::app | ios::binary);
  cleardevice();
  gotoxy(30,5);
  cout<<"CONGRATULATIONS";
  gotoxy(32,10);
  cout<<"enter name:";
  cin>>temp.name;
  f1.write((char*)&temp,sizeof(temp));
  f1.close();
  }
}



void snake::init()
{
   for(int i=0;i<50;++i)
      {
	    a[i][0]=-1;
		  a[i][1]=-1;
      }
}
void snake::menu()
{
   int x=380,y=135;
   cleardevice();
   char ch2;

   setcolor(1);
   settextstyle(DEFAULT_FONT,HORIZ_DIR,2);

   outtextxy(x-30,y,"->");
   setcolor(15);
   outtextxy(x,135,"NEW GAME");
   outtextxy(x,180,"HIGHSCORE");
   outtextxy(x,225,"QUIT");


   while(1)
   {
       ch2=getch();
       if(ch2==13)
	 break;
       else
       {

	 if(ch2==72 && y>135)
	 {

	   cleardevice();
	   setcolor(1);
	   cleardevice();
	   outtextxy(x-30,y-=45,"->");
	 }


	 if(ch2==80 && y<225)
	 {
	   cleardevice();
	   setcolor(1);
	   cleardevice();
	   outtextxy(x-30,y+=45,"->");
	 }


	 setcolor(15);
	 settextstyle(DEFAULT_FONT,HORIZ_DIR,2);
	 outtextxy(x,135,"NEW GAME");
	 outtextxy(x,180,"HIGHSCORE");
	 outtextxy(x,225,"QUIT");

	  }

   }


  if(y==135)
    {
       food();
       level();
    }

    else if(y==180)
	  {
	    nw.display();
	    menu();
	   }

	   else
		 exit(0);
   }

int snake::check_limits()
{
  int i=0;
  if(ch=='w')
  {
    if(13>a[0][1]-6)
	i++;
  }
  else if(ch=='a')
       {
	   if(a[0][0]-6<13)
	     i++;
	}

	else  if(ch=='s')
	      {
		if(a[0][1]+6>maxy-3)
		  i++;
	      }
	       else  if(ch=='d')
		     {
			if(a[0][0]+6>maxx-3)
			  i++;
		      }
if(i==0)
    return 1;
  else
    return 0;
}

int snake::intersect()
{
  int i=1;
  if(ch=='w')
  {
    for(i=1;i<=len;++i)
     if(a[i][0]==a[0][0] && a[i][1]==a[0][1]-6)
       break;
  }
  else if(ch=='a')
       {
	 for(i=1;i<=len;++i)
	 if(a[i][0]==a[0][0]-6 && a[i][1]==a[0][1])
	   break;
	}

	else  if(ch=='s')
	      {
		for(i=1;i<=len;++i)
		if(a[i][0]==a[0][0] && a[i][1]==a[0][1]+6 )
		 break;
	      }
	       else  if(ch=='d')
		     {
			for(i=1;i<=len;++i)
			     if(a[i][0]==a[0][0]+6 && a[i][1]==a[0][1])
				break;
		      }
if(i==len+1)
    return 1;
  else
    return 0;

}




void snake::disp()
{
  char choice;
  if(ch=='w')
   if(intersect()==1 && check_limits()==1)
       a[0][1]-=6;
   else
   {
     outtextxy(200,200,"GAME OVER");
     getch();
     nw.store();
     nw.display();
   }
  if(ch=='a')
   if(intersect()==1 && check_limits()==1)
      a[0][0]-=6;
    else
   {
     outtextxy(200,200,"GAME OVER");
     getch();
     nw.store();
     nw.display();
     }
  if(ch=='s')
    if(intersect()==1 && check_limits()==1)
      a[0][1]+=6;
     else
   {
     outtextxy(200,200,"GAME OVER");
     getch();
     nw.store();
     nw.display();
     }
  if(ch=='d')
    if(intersect()==1 && check_limits()==1)
      a[0][0]+=6;
   else
   {
     outtextxy(200,200,"GAME OVER");
     getch();
     nw.store();
     nw.display();
     }
  cleardevice();
  setcolor(10);
  rectangle(10,10,maxx+3,maxy+3);
  rectangle(13,13,maxx,maxy);
  setcolor(9);
  settextstyle(DEFAULT_FONT,HORIZ_DIR,3);
  outtextxy(510,10,"SNAKE");
  setcolor(15);

  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);

  setcolor(2);
  outtextxy(10,maxy+10,"Instructions");
  outtextxy(10,maxy+20," w : up");
  outtextxy(10,maxy+30," s : down");
  outtextxy(10,maxy+40," a : left");
  outtextxy(10,maxy+50," d : right");
  settextstyle(DEFAULT_FONT,HORIZ_DIR,1);
  move();
  check();



 setcolor(1);
 //cout<<fpos[0]<<' '<<fpos[0][1];getch();

 circle(fpos[0][0],fpos[0][1],3);
 setfillstyle(1,15);
 floodfill(fpos[0][0],fpos[0][1],1);


 int i=0;
 do{
     setfillstyle(1,2);
     setcolor(2);
     rectangle(a[i][0]-3,a[i][1]-3,a[i][0]+3,a[i][1]+3);
     i++;
   }while(a[i][0]!=-1);
}


void snake::move()
{
   for(int i=len;i>0;--i)
   {
     a[i][0]=a[i-1][0];
     a[i][1]=a[i-1][1];
   }
}


void snake::food()
{

  int i;
  //srand makes it infinite loop

  fpos[0][0]=random(500-13)+13;
  fpos[0][1]=random(300-13)+13;

  //cout<<' '<<fpos[0][0]<<' '<<fpos[0][1];getch();
    for(i=0;i<=len;++i)
  {
    if(a[i][0]==fpos[0][0] && a[i][1]==fpos[0][1])
      { food();
	}

  }
  if(fpos[0][1]%6!=0 || fpos[0][0]%6!=0)
   { food();
    }
}

void snake::check()
{

  if(a[0][0]==fpos[0][0] && a[0][1]==fpos[0][1])
  {
      ++len;
      food();

  }
}
void snake::level()
{
   char temp=ch,dir;
   int ch1,x1=200,y1=230,n;
   cleardevice();
   len=4;
   s.init();
   s.a[0][0]=60;
   s.a[0][1]=240;

   for(int i=1;i<=len;++i)
   {
     s.a[i][0]=s.a[i-1][0]-6;
     s.a[i][1]=s.a[i-1][1];
   }

    settextstyle(0,HORIZ_DIR,2);
    setcolor(15);
    outtextxy(200,200,"Select level");
    outtextxy(200,230,"Easy ");
    outtextxy(200,250,"Medium ");
    outtextxy(200,270,"Hardcore");

     setcolor(1);
     outtextxy(x1-30,y1,">");

     while(1)
     {
       ch1=getch();
       if(ch1==13)
	 break;
       else if(ch1!=27 && ch1!=8)
	    {
		if(ch1==72 && y1>230)
		 {
		   cleardevice();
		   setcolor(1);
		   outtextxy(x1-30,y1-=20,">");
		 }
		 if(ch1==80 && y1<270)
		 {
		   cleardevice();
		   setcolor(1);
		   outtextxy(x1-30,y1+=20,">");
		 }
	     }
	     else
	       menu();
    setcolor(15);
    outtextxy(200,200,"Select level");
    outtextxy(200,230,"Easy ");
    outtextxy(200,250,"Medium ");
    outtextxy(200,270,"Hardcore ");
   }
   if(y1==230)
     n=1;
   else if(y1==250)
     n=2;
     else if(y1==270)
     n=3;
 ch='d';
 temp=ch;
 while(temp!=13)
 {
  if(kbhit()==0)
  {

    if(n==1)
    { s.disp();
    delay(100);
    }
    else if(n==2)
    { s.disp();
    delay(50);
    }
    else if(n==3)
    {s.disp();
    delay(20);
    }
  }
  else
  {
    if(temp=='w' || temp=='s')
      dir='v';
    else
      dir='h';
    ch=getch();
    if(ch=='w' || ch=='s' || ch=='a' || ch=='d' || ch==13)
    {
    if(dir=='v' && (ch=='w'  || ch=='s'))
      ch=temp;
    else if(dir=='h' && (ch=='a' || ch=='d'))
	   ch=temp;
	 else
	    temp=ch;
    }
    else
      ch=temp;

   }

 }
 }
void main()
{
 srand(time(0));
 int gd=DETECT,gm;
 initgraph(&gd,&gm,"c:/turboc3/bgi");
 s.menu();

 s.food();
 //cout<<s.fpos[0][0]<<' '<<s.fpos[0][1]<<' ';getch();

 s.level();

// nw.display();
 getch();

}