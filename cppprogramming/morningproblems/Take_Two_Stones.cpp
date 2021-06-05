#include <iostream>
using namespace std;

int main() {
	long long int N;
	cin >> N;
	((N % 2) == 0) ? cout << "Bob\n" : cout << "Alice\n";

	return 0;
}