#include <iostream>
using namespace std;
int main(){
	int n = 0;
	cin >> n;
	int a[n];
	int count = 0;
	for (int i = 0; i < n; i++){
		cin >> a[i];
		if (a[i] < 0){
			count++;
		}
	}
	cout << count << endl;
}