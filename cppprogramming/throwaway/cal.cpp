#include <iostream>
using namespace std;

int main(){
	// calculator('a',256.0);
	char letters[] = "a long sentence";
	cout << sizeof(letters) << endl;
	cout << sizeof(char) << endl;
	cout << sizeof "tricky" << endl;
	cout << strlen("tricky") << endl;
	return 0;
}