#include <iostream>
using namespace std;

int main(){
	int i = 25, *j;
	j = &i;
	cout << j << endl;
	j++;
	cout << j << endl;
	j = j - 3;
	cout << j << endl;
	return 0;
}