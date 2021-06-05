#include <iostream>
using namespace std;

int main() {
	int X, N;
	long long int count = 0;
	cin >> X >> N;

	for (int i = 0; i < N; i++) {
		int temp = 0;
		cin >> temp;
		count += (X - temp);
	}
	count += X;
	cout << count << endl;

	return 0;
}