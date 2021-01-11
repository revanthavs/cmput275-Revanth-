#include "stdio.h"

int main(){
	printf("It's working\n");
	int z;
	scanf("%d",&z);
	printf("x = %d\n",z);
	int x,y;
	scanf("%d %d",&x,&y);
	printf("total = %d\n", (x+y));
	float f;
	scanf("%f",&f);
	printf("float x = %3.2f\n",f);
	return -1;
}