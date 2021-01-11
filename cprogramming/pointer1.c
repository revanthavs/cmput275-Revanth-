#include <stdio.h>

int main(void){

      float pi = 3.14;
      float *i; int *j; char *k;
      i=&pi;
      j=&pi;
      k=&pi;
      printf("\n");
      printf("%f %d %c\n", *i, *j, *k);
      printf("%c %c %c %c\n", *k, *(k+1), *(k+2), *(k+3));
      printf("%d %d\n", *(j+1), *(j+2));
      return 0;
}
