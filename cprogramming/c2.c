#include <stdio.h>

int main(void){
   int x, y;
   x=2;
   y=6;
//   y=x+4*x/(y-4);
   y = (x+3*x)*2/(y-4);
   printf("X=%d and Y=%d\n",x,y);
   return 0;
}
