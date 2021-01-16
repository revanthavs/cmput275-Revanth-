#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	// string line, word;
	int boo = 0; char letter;
	vector<char> line;
	while (cin.get(letter)){
		line.push_back(letter);
	}
	int n = line.size();
	for (int i = 0; i < n; i++)
		cout << line[i];
	cout << endl;
	// cout << line.size() << endl;
	return 0;
}