#include <iostream>
using namespace std;

int main(){
	int n = 0;
	cin >> n;
	char string[n];
	for (int i = 0; i < n; i++){
		cin >> string[i];
	}
	for (int i = 0; i < n; i++){
		cout << string[i];
	}
	cout << endl;
	for (int i = 0, j = n-1; i <= (n/2) ; i++, j--){
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