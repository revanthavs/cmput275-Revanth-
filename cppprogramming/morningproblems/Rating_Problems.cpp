#include <iostream>
using namespace std;

int main() {
	int n = 0, k = 0;
	cin >> n >> k;
	// int ratings[k] = {};
	double count = 0;
	for (int i = 0; i < k; i++){
		int temp = 0; cin >> temp;
		count += temp;
	}
	double min_rating = count, max_rating = count;
	for (int i = 0; i < (n-k); i++) {
		min_rating += -3;
		max_rating += 3;
	}
	cout << (min_rating)/n << " " << (max_rating)/n << endl;

	return 0;
}