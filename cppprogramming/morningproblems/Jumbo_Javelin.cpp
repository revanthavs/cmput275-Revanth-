#include <iostream>
using namespace std;

int main() {
	int N = 0; cin >> N;
	int Total = 0;
	for (int i = 0; i < N; i++) {
		int temp = 0; cin >> temp;
		Total += temp;
	}
	Total = Total - N + 1;
	cout << Total << endl;

	return 0;
}