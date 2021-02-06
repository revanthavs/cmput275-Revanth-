#include <iostream>
using namespace std;

int main(){
	int vals[] = {1, 7, 6, 2, 8};
	int *ptr = (vals+2);
	*(ptr + 1) = 17;
	*(vals+vals[0]) = 5;
	for (int i = 0; i < 5; i++)
		cout << vals[i] << " ";
	cout << endl << *ptr << endl;
	return 0;
}