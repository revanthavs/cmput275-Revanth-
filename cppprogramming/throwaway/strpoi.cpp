#include <iostream>
using namespace std;

typedef struct complex{
	int rel;
	int img;
}complex;

int main(){
	complex a;
	a.rel = 10;
	a.img = 5;
	cout << a.rel << "+i" << a.img << endl;
	return 0;
}