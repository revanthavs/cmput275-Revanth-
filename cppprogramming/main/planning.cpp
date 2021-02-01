#include <iostream>
using namespace std;

int main(){
	// Declare your variables
	int n,t,max_t = -1, min_t = 100001, count_i = 1, count = 1, hours = 0;
	// Read the input
	cin >> n >> t;
	int s[n], e[n];
	for (int i = 0; i < n; i++){
		cin >> s[i] >> e[i];
	}
	// Solve the problem. Good luck! :)
	max_t = s[0];
	for (int i = 1; i < n; i++){
		if (max_t < s[i]){
			max_t = s[i];
		}
	}
	for (int i = 0; i < n; i++){
		if (max_t < e[i] && min_t > e[i]){
			min_t = e[i];
		}
	}
	// Output the answer
	if (min_t == 100001){
		cout << "IMPOSSIBLE\n";
		return 0;
	}
	hours = min_t - max_t;
	count = hours;
	while (t > count){
		count_i++;
		count = hours * count_i;
	}
	cout << count_i << endl;
	return 0;
}