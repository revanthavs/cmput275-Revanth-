#include <iostream>
using namespace std;

int main() {
	int X, Y, N; cin >> X >> Y >> N;
	string fizz = "Fizz", buzz = "Buzz", fizzbuzz = "FizzBuzz";
	for (int i = 1; i <= N; i++) {
		if ((i < X) && (i < Y)) cout << i << endl;
		else if ((i >= X) || (i >= Y)) {
			if (i < X) {
				((i % Y) == 0) ? cout << buzz << endl : cout << i << endl; 
			}
			else if (i < Y) {
				((i % X) == 0) ? cout << fizz << endl : cout << i << endl;
			}
			else if ((i >= X) && (i >= Y)) {
				if ( ((i % X) == 0) && ((i % Y) == 0) ) cout << fizzbuzz << endl;
				else if ((i % X) == 0) cout << fizz << endl;
				else if ((i % Y) == 0) cout << buzz << endl;
				else cout << i << endl;
			}
		}
	}

	return 0;
}