#include <iostream>
using namespace std;

int main() {
	string jon_lev, doctor_lev;
	cin >> jon_lev >> doctor_lev;
	int jon_count = 0, doctor_count = 0;
	for (auto i : jon_lev) (i == 'a') ? jon_count += 1 : jon_count += 0;
	for (auto i : doctor_lev) (i == 'a') ? doctor_count += 1 : doctor_count += 0;
	if (jon_count < doctor_count) cout << "no\n";
	else if (jon_count >= doctor_count) cout << "go\n";
	return 0;
}