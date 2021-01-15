#include <iostream>
#include <cctype>
using std::cout;
using std::cin;
using std::endl;

int main(){
	cout << "Security\n";
	cout << "Enter your code:____\b\b\b\b";
	int code;
	cin >> code;
	if (code == 1234){
		cout << "Your password is correct\n";
	}
	else
		cout << "Worng password!\a\n";
	cout << "You entered " << code << endl;
	return 0;
	char c;
	cin.get(c);
	// if (c <= 'b')
		// c++;
	if (islower(c))
		c = toupper(c);
	cout << "c is: " << c << endl;
}