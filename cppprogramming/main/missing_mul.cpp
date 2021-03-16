#include <iostream>
using namespace std;


int main(){
	// Declare your variables
	unsigned int n = 1, m = 0;
	cin >> n >> m;
	int array[n] = {}; long long int prefix[n] = {}, suffix[n] = {}, result[n] = {};
	// Read the input
	for (unsigned int i = 0; i < n; i++){
		cin >> array[i];
	}
	// Solve the problem. I believe in you!

	prefix[0] = 1; suffix[n-1] = 1;
	for (unsigned int i = 1; i < n; i++){
		prefix[i] = prefix[i-1] * array[i-1];
	}
	for (int i = n-2; i >= 0; i--){
		suffix[i] = suffix[i+1] * array[i+1];
	}
	// Output the answer
	for (int i = 0; i < n; i++){
		int start_i = i-m, end_i = i+m;
		if (start_i <= 0 && end_i >= (n-1)){
			result[i] = 0;
			continue;
		}
		(start_i < 0)? start_i = 0: start_i = start_i;
		(end_i > (n-1))? end_i = n-1: end_i = end_i;
		result[i] = prefix[start_i] * suffix[end_i];
	}
	for (int i = 0; i < n; i++){
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}

// #include <iostream>
// #include <unordered_set>
// using namespace std;


// int main(){
// 	// Declare your variables
// 	unsigned int n = 1, m = 0;
// 	cin >> n >> m;
// 	int array[n] = {}; long long int product = 1, result[n] = {};
// 	unordered_set<unsigned int> zero_index;
// 	// Read the input
// 	for (unsigned int i = 0; i < n; i++){
// 		cin >> array[i];
// 		if (array[i] == 0)
// 			zero_index.insert(i);
// 		product *= array[i];yf
// 	}
// 	// Solve the problem. I believe in you!
// 	if (m < (n/2)){
// 		for (unsigned int i = 0; i < n; i++){
// 			if (product != 0){
// 				int start_i = (i-m), end_i = (i+m);
// 				(start_i < 0) ? start_i = 0 : start_i = start_i;
// 				(end_i > n-1) ? end_i = n-1 : end_i = end_i;
// 				long int prod = 1;
// 				if ((start_i+end_i) == (n-1)){
// 					result[i] = 0;
// 					continue;
// 				}

// 			}
// 		}
// 	}
// 	else if (m >= (n/2)){

// 	}
// 	// Output the answer

// 	return 0;
// }