#include <iostream>
using namespace std;

int main(){
	int n = 100000;
	cout << n << endl;
	for (int i = n; i >= 0 ;i--){
		if (i != 0)
			cout << i << " ";
		else
			cout << i << endl;
	}
	return 0;
}