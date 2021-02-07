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
	char *string2 = new char[length+1];
	for (int i = 0; i < length; i++)
		cin >> string2[i];
	string2[length] = '\0';
	const char *pointers[2];
	pointers[0] = NULL;
	pointers[1] = NULL;
	pointers[0] = string;
	pointers[1] = string2;
	string = NULL;
	delete[] pointers[0];
	delete[] pointers[1];
	pointers[0] = NULL;
	pointers[1] = NULL;
	
	// delete[] string;
	string = NULL;
	string2 = NULL;
	return 0;
}