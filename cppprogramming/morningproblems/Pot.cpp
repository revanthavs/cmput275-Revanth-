#include <iostream>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	long long int total = 0;
	for (int i = 0; i < N; i++) {
		int temp = 0; cin >> temp;
		long long temp1 = 1;
		int value =  temp / 10, power = temp % 10;
		for (int j = 0; j < power; j++){
			temp1 *= value;
		}
		total += temp1;
	}
	cout << total << endl;

	return 0;
}