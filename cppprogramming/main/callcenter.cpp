#include <iostream>
using namespace std;

int main(){
	unsigned int n, q;
	cin >> n >> q;
	unsigned int calls[n], result[q], sums[n];
	for (unsigned int i = 0; i < n; i++)
		cin >> calls[i];
	for (unsigned int i = 0; i < n; i++)
		sums[i] = calls[i];
	for (unsigned int i =1; i < n; i++)
		sums[i] = sums[i] + sums[i-1];
	for (unsigned int i = 0; i < n; i++){
		unsigned int start, end;
		cin >> start >> end;
		if (start == 1){
			result[i] = sums[end - 1];
		}
		else if (start == end){
			result[i] = calls[start - 1];
		}
		else{
			result[i] = sums[end - 1] - sums[start - 2];
		}
	}

	for (unsigned int i = 0; i < q; i++){
		cout << result[i] << endl;
	}
	return 0;
}