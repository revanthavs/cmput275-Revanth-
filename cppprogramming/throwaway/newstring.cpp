#include <iostream>
using namespace std;

int main(){
	int length = 0;
	cin >> length;
	char *string = new char[length+1];
	for (int i = 0; i < length; i++)
		cin >> string[i];
	string[length] = '\0';
	for (int i = 0; i < length; i++)
		cout << string[i];
	cout << endl;
	delete[] string;
	return 0;
}