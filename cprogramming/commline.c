#include <stdio.h>
#define add3(x,y,z) ((x)+(y)+(z))

int main(int argc, char **argv){

   printf("The  value of the command line input = %d\n",argc);
   puts("hello this is from the puts output!!");
   printf("Enter some text for checking!");
   int some =add3(1,2,3);
   printf("The value=%d\n",some);
   return 0;
}
