#include <iostream>
#include <vector>
using namespace std;

int main(){
	int count = 0;
	char n;
	vector<char> string;
	while (cin >> n){
		string.push_back(n);
		count++;
	}
	for (int i = 0, j = count-1; i <= (count/2) ; i++, j--){
		cout << string[i] << " == " << string[j] << endl;
		if (string[i] == string[j]){
			continue;
		}
		else{
			cout << "Not a Palindrome" << endl;
			return 0;
		}
	}
	cout << "Palindrome" << endl;
	return -1;
}