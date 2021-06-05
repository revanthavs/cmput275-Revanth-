#include <iostream>
using namespace std;

int main() {
	long long int count = 0;
	int N;
	cin >> N;
	if (N % 2 != 0){
		long long int temp = 0;
		for (int i = 0; i < N; i++) cin >> temp; 
		cout << "still running\n";
		return 0;
	}
	else {
		for (int i = 0; i < N; i++) {
			long long int temp = 0;
			cin >> temp;
			count = (temp - count);
		}
		cout << count << endl;
		return 0;
	}
	return 0;
}