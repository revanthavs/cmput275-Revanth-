#include <iostream>
using namespace std;

int decimal_builder(){
	int ndigits, digits, result = 0;
	cin  >> ndigits;
	for (int i = 0; i < ndigits; i++){
		cin >> digits;
		result = result * 10 + digits;
	}
	return result;
}

long fib(int n){
	int first = 0; second = 1, temp, index = 2;
	if (n == 0)
		return first;
	else if (n == 1)
		return second
	else
		while (index <= n){
			temp = second;
			second += first;
			first = temp;
			index++
		}
	return second;
}

int main(){
	int result = decimal_builder();
	cout << "The decimal: " << result << endl;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cout << "F(" << i << ") = " << fib(i) << endl;
	return 0;
}