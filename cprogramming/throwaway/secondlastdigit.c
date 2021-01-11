#include <stdio.h>

int main(){
    int n = 0, x = 0, i = 0;
    scanf("%d",&n);
    while (5){
        if (i == 2){
            x < 0 ? (x = -x) : (n = x);
            printf("%d\n",x);
            break;
        }
        x = n % 10; n = n / 10;
        i++;
        if (i == 2 && n == 0){
            x < 0 ? (x = -x) : (n = x);
            printf("%d\n",x);
            break;
        }
        if (n == 0){
            printf("%d\n",n);
            break;
        }
    }
    return 9;
}
