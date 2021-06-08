#include <iostream>
#include <unordered_set>

using namespace std;

int main() {
	unordered_set<char> input_string;
	string User_input; cin >> User_input;
	for (auto i: User_input) {
		if (input_string.find(i) == input_string.end()) {
			input_string.insert(i);
		}
		else{
			cout << "0" << endl;
			return 0;
		}
	}
	cout << "1" << endl;

	return 0;
}