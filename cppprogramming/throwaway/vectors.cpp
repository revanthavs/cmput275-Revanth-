#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n = 0;
	cin >> n;
	vector<char> string;
	for (int i = 0; i < n; i++){
		char c;
		cin >> c;
		string.push_back(c);
	}
	for (int i = n-1; i >= 0; i--){
		cout << string[i];
	}
	cout << endl;
}