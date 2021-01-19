#include <iostream>
using namespace std;

int main(){
	int a[5] = {};
	for (int i = 0; i < 5; i++){
		a[i] = i;
		cout << a[i] << endl;
	}
	int * b;
	b = a;
	for (int i = 0; i < 5; i++){
		*(b + i) = i + 1;
		cout << *(b + i) << " == " << *(a + i) << endl;
	}
	cout << sizeof(b) << " == " << sizeof(a) << endl;;
	return 0;
}