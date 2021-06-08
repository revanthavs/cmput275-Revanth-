#include <iostream>
using namespace std;

int main() {
	string user_input; cin >> user_input;
	int no_of_e_s = 0;
	for (auto i: user_input) {
		if (i == 'e') no_of_e_s++;
	}
	no_of_e_s = no_of_e_s * 2;
	string output_string = "h";
	for (int i = 0; i < no_of_e_s; i++) output_string += "e";
	output_string += "y";
	cout << output_string << endl;

	return 0;
}