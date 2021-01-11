#include <stdio.h>

int main(void){

      int a = 5;
      double pi = 3.14;
      int *p;     //declaring the pointer before hand
      p = &a;               //sending the address of varibale a to pointer p
      double *pn = &pi;          //sending the address of variable pi to pointer pn
      printf("The value of a %d and value of pi %f\n",a,pi);
            *pn = *pn + *p ;  //doing addtion with pointers
      printf("The value of a %d and value of pi %f\n",a,pi);
      return 1;
}
