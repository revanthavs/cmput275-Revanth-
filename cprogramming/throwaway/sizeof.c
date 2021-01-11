#include <stdio.h>

int main(){
    unsigned short int x1 = 0; short int x2 = 0; unsigned int x3 = 0; int x4 = 0; long x5 = 0; unsigned long x6 = 0; long long int x7 = 0;
    unsigned long long int x8 = 0;
    printf("USI = %hu\nSI = %hi\nUI = %i\nI = %d\nLI = %li\nULI = %lu\nLLI = %lli\nULLI = %llu\n",sizeof(x1),sizeof(x2),sizeof(x3),sizeof(x4),
    sizeof(x5),sizeof(x6),sizeof(x7),sizeof(x8));
    return -1;
}