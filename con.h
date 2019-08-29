#include <termios.h>
#include <stdio.h>

static struct termios old, neww;

void initTermios(int echo) 
{
  tcgetattr(0, &old);
  neww = old;
  neww.c_lflag &= ~ICANON;
  neww.c_lflag &= echo ? ECHO : ~ECHO;
  tcsetattr(0, TCSANOW, &neww);
}

void resetTermios(void) 
{
  tcsetattr(0, TCSANOW, &old);
}
 
char getch_(int echo) 
{
  char ch;
  initTermios(echo);
  ch = getchar();
  resetTermios();
  return ch;
}
 

char getch(void) 
{
  return getch_(0);
}
 
char getche(void) 
{
  return getch_(1);
}

void clrscr(void)
{
    system("clear");
}
