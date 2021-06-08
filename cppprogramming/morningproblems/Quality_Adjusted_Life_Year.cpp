#include <iostream>
using namespace std;

int main() {
	int N = 0;
	cin >> N;
	double total_q = 0;
	for (int i = 0; i < N; i++) {
		double q = 0, y = 0;
		cin >> q >> y;
		total_q += (q * y);
	}
	cout << total_q << endl;

	return 0;
}