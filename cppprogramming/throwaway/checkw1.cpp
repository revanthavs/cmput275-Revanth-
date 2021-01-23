#include <iostream>
#include <string>
using namespace std;

int main(){
	char* p1, p2;
	p1 = "revanth";
	p2 = 'A';
	cout << p2 << " " << p1 << endl;
	cout << sizeof(char*) << " " << sizeof(char) << endl;
	cout << sizeof(p1) << " " << sizeof(p2) << endl;
	return 0;
}