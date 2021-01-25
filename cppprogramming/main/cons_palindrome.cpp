#include <iostream>
#include <vector>
using namespace std;

int main(){
	int n,result = 0;
	cin >> n;
	char s; bool cflag = false; int index = 0;
	vector<char> word; vector<int> count;
	for (int i = 0; i < n; i++){
		cflag = false;
		cin >> s;
		for (int j = 0; j < word.size(); j++){
			if (word[j] == s){
				cflag = true;
				index = j;
				break;
			}
		}
		if (!cflag){
			word.push_back(s);
			count.push_back(1);
		}
		else
			count[index] = count[index] + 1;
	}
	for (int i = 0; i < word.size(); i++){
		cout << word[i] << " == " << count[i] << endl;
	}
	for (int i = 0; i < word.size(); i++){
		if (count[i]%2 == 0){
			result = result + count[i];
		}
		else if (result%2 == 0){
			result = result + count[i];
		}
		else if (result%2 != 0){
			result = result + (count[i] - 1);
		}
	}
	cout << result << endl;
	return 0;
}