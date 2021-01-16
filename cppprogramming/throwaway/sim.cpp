#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
	int n = 0;
	cin >> n;
	string line, fline; vector<string> lines,flines;
	for (int i = 0; i <= n; i++){
		getline(cin,line);
		lines.push_back(line);
	}
	for (int i = 1; i <= n; i++){
		for (int j = 0; j < lines[i].length(); j++){
			char letter = lines[i][j];
			if ((letter == "[") || (letter == "]") || (letter == "<")){
				if (letter == "[")
					j = 0
			}
		}
	}
}