#include <stdio.h>

int main(){
    unsigned long i = 0;
    while (10){
        if (i == 0xFAD9CEA62ul)
            break;
        else
            i++;
    }
    printf("%lu",i);
    return 0;
}