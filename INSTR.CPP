#include<fstream.h>
#include<dos.h>
#include<string.h>
#include<graphics.h>
#include<conio.h>
void rules()
{
  ifstream f1("rule.txt");
  int y=0;
  char a[20],cha[200]="\0";
  cleardevice();
 if(f1)
 {
  do{
      f1>>a;
      if(a[0]=='~')
       {
	y+=20;
	settextstyle(COMPLEX_FONT,HORIZ_DIR,1);
	setcolor(6);
	outtextxy(20,y,cha);
	for(int i=0;i<200;++i)
	  cha[i]='a';
	strcpy(cha,"\0");
       }
     // getch();
     if(a[0]!='~')
     {
       strcat(cha,a);
       strcat(cha," ");
     }
     }while(f1.eof()==0);

 }
  setcolor(1);
  textcolor(0);
  textbackground(1);
  while(kbhit()==0)
  {


   delay(500);
   gotoxy(20,25);

   int x=wherex();
   int y=wherey();

   cout<<"press any key to continue...";

   delay(500);
   gotoxy(x,y);

   clreol();
   }
}

