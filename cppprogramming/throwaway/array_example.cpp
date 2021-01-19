#include <iostream>
using namespace std;

int main(){
	int i = 25, *j, *k;
	j = &i;
	k = &i;
	cout << (j - k) << endl;
	return 0;
}