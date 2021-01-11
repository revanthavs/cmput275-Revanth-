#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

int main(){
	int n = 0;
	cin >> n;
	unordered_map<string, string> prizes;
	vector<string> universities;
	for (int i = 0; i < n; i++){
		string key, value;
		cin >> key >> value;
		if (prizes.find(key) == prizes.end()){
			prizes.insert(make_pair(key, value));
			universities.push_back(key);
		}
	}
	for (int i = 0; i < 12; i++){
		cout << universities[i] << " " << prizes[universities[i]] << endl;
	}
}