#include <iostream>
using namespace std;

int sumDigit(int n){
	int x = 0;
	while (n != 0){
		x += n % 10;
		n /= 10;
	}
	return x;
}

int main(){
	int n = 0;
	cin >> n;
	int sum = sumDigit(n);
	cout << sum << endl;
	
	return 0;
}