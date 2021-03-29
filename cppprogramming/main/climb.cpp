#include <iostream>
using namespace std;

int main() {
    // I've heard that climbing is a good workout for your legs.
    // But I haven't moved from my chair in years, so I might not be the best person to ask.
    // Good luck with the problem! The term is almost over! :)

	// Read in the input
	int n = 0;
	cin >> n;
	int waypoints[n] = {};
	for (int i = 0; i < n; i++){
		cin >> waypoints[i];
	}

	// Solve the problem
	int temp = waypoints[0];
	int result[n] = {};
	for (int i = 1; i < n; i++){
		if (temp < waypoints[i]){
			result[i-1] = -1;
			temp = waypoints[i];
			continue;
		}
		else{
			result[i-1] = 0;
			temp = waypoints[i];
			continue;
		}
	}

	int count = 1;
	for (int i = (n-1); i > 0; i--){
		if (result[i] == -1){
			result[i] = count;
			count++;
		}
		else{
			count = 1;
		}
	}
	// Output the result

	for (int i = 0; i < n; i++){
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}