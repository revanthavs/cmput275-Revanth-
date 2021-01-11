#include <stdio.h>

int main(void){
	unsigned short int x = 65535;
	unsigned short int w = x + 1;
	printf("%d\n",w);
	x = x + 1;
	printf("%d\n",x);
	unsigned short int z = 0;
	int y = sizeof(z);
	printf("%d\n",y);
	return 0;
}