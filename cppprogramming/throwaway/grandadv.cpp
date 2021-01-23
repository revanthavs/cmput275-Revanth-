#include <iostream>
#include <string>
#include <queue>
#include <stack>
using namespace std;

int main(){
	int n = 0;
	cin >> n;
	string inputs[n];
	string symbols[n];
	string results[n];
	char dot = '.';
	char res[2]; res[0] = '$'; res[1] = '|'; res[2] = '*';
	for (int i = 0; i < n; i++)
		cin >> inputs[i];
	for (int i = 0; i < n; i++){
		for (int j = 0; j < inputs[i].length(); j++){
			if (inputs[i][j] != dot)
				symbols[i] += inputs[i][j];
		}
	}
	for (int i = 0; i < n; i++){
		stack<char> chars;
		for (int j = 0; j < symbols[i].length(); j++){
			if ((symbols[i][j] == '$') || (symbols[i][j] == '|') || (symbols[i][j] == '*'))
				chars.push(symbols[i][j]);
			else if ((symbols[i][j] == 'b') || (symbols[i][j] == 't') || (symbols[i][j] == 'j')){
				if (symbols[i][j] == 'b')
					if (chars.pop() == '$')
						continue;
					else
						break;
				else
					if (symbols[i][j] == 't')
						if (chars.pop() == '|')
							continue;
						else
							break;
					else
						if (symbols[i][j] == 'j')
							if (chars.pop() == '*')
								continue;
							else
								break;
			}
		}
			if (chars.empty())
				results[i] = "YES";
			else
				results[i] = "NO";
	}
	for (int i = 0; i < n; i++)
		cout << results[i] << endl;
	return 0;
}