#include <stdio.h>

int main(void){
    
    int x=2,y=8;
    y=x+3*x/(y=4);
    printf("x=%d and y=%d\n",x,y);
    return 0;
}
