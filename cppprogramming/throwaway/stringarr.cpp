#include <iostream>
#include <string>
using namespace std;

int main(){
	int n;
	cin >> n;
	string inputs[n];
	for (int i = 0; i < n; i++)
		cin >> inputs[i];
	for (int i = 0; i < n; i++)
		cout << inputs[i] << endl;
	return 0;
}