#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector<char> string;
	char n;int count = 0;
	while (cin >> n){
		string.push_back(n);
		count++;
	}
	char fstring[count];
	for (int i = 0; i < count; i++){
		int k = int(string[i]+3);
		if (string[i] != 'x' && string[i] != 'X' && string[i] != 'y' && string[i] != 'Y' && string[i] != 'z' && string[i] != 'Z'){
			fstring[i] = string[i] + 3;
		}
		else if (string[i] == 'x' || string[i] == 'X'){
			if (string[i] == 'x')
				fstring[i] = 'a';
			else
				fstring[i] = 'A';
		}
		else if (string[i] == 'y' || string[i] == 'Y'){
			if (string[i] == 'y')
				fstring[i] = 'b';
			else
				fstring[i] = 'B';
		}
		else if (string[i] == 'z' || string[i] == 'Z'){
			if (string[i] == 'z')
				fstring[i] = 'c';
			else
				fstring[i] = 'C';
		}
	}
	for (int i = 0; i < count; i++){
		cout << fstring[i];
	}
	cout << endl;
}