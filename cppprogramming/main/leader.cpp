#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int &val1, int &val2){
	int temp;
	temp = val1;
	val1 = val2;
	val2 = temp;
	return;
}

int main(){
	int n, led = 0, i = 0, arrindex = 0;
	cin >> n;
	int elements[n]; int leaders[n] = {};
	for (i = 0; i < n; i++){
		cin >> elements[i];
		leaders[i] = -1;
	}
	while (led < n){
		for (i = led+1; i<n; i++){
			if (elements[led] <= elements[i]){
				led = i;
				continue;
			}
		}
		if (i == n){
			leaders[arrindex] = led;
			arrindex++;led++;
		}
	}
	// leaders[arrindex] = n-1;
	for (i = 0; i< n ; i++){
		if (leaders[i] != -1)
			cout << elements[leaders[i]] << " ";
		// cout << leaders[i] << endl;
	}
	cout << endl;
	int a = 5, b = 10;
	cout << &a << " == " << a << endl;
	cout << &b << " == " << b << endl;
	swap(a,b);
	cout << &a << " == " << a << endl;
	cout << &b << " == " << b << endl;
	return 0;
}

