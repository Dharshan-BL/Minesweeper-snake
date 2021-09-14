#include"project.cpp"
#include"draft.cpp"
void main()
{
  int j=0;
  while(j<=3)
  {
    delay(250);
    if(j==1)
    {
     sound(2500); delay(2);
     nosound();
    }
    if(j==3)
    {
     sound(30);delay(70);
     nosound();
    }
    cleardevice();
    ubisoft();
    delay(500);

    j++;
  }
  select();
}