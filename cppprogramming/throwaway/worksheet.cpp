#include <iostream>
using namespace std;

int main(){
	unsigned int a = 2, c = 3;
unsigned int* b = &a;
short d = *b*c**b*a-*b*5*a;
cout << d << endl;
return 0;
}