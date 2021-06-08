#include <iostream>
using namespace std;

int main() {
	int total = 0;
	int num = 0;
	for (int i = 0; i < 5; i++) {
		int temp_total = 0;
		for (int j = 0; j < 4; j++) {
			int temp = 0;
			cin >> temp;
			temp_total += temp;
		}
		if (temp_total >= total){
		   total = temp_total;
		   num = i+1;
		}
	}
	cout << num << " " << total << endl;

	return 0;
}