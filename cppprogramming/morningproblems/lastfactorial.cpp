#include <iostream>
using namespace std;

int value(int n){
	return (n % 10);
}

int factorial(int n){
	if (n == 1){
		return 1;
	}
	return n * factorial(n-1);
}

int main(){
	int n = 0;
	cin >> n;
	int numbers[n], fact[n], val[n];
	for (int i = 0; i < n; i++){
		cin >> numbers[i];
	}
	for (int i = 0; i < n; i++){
		fact[i] = factorial(numbers[i]);
	}
	for (int i = 0; i < n; i++){
		val[i] = value(fact[i]);
	}
	for (int i = 0; i < n; i++){
		cout << val[i] << endl;
	}
}