#include <stdio.h>
int fib(int x){
	if (x == 0 || x == 1)
		return 1;
	else
		return fib(x-1) + fib(x-2);
}
int main(void){
	int x = 5;
	int y = fib(x);
	printf("%i",y);
}