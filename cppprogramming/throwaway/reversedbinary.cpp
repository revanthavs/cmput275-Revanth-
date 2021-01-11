#include <iostream>
using namespace std;

int power(int n){
	int value = 1;
	if (n == 0){
		return 1;
	}
	else{
		while ( n != 0){
			value = value * 2;
			n--;
		}
	}
	return value;
}

int main(){
	int n = 0;
	cin >> n;
	int count = 1, breakpoint = 0;
	while (1){
		if (power(count) < n){
			count++;
			breakpoint++;
		}
		else{
			break;
		}
	}
	int binary[breakpoint];
	for (int i = 0; i <= breakpoint; i++){
		binary[i] = 0;
	}
	for (int i = breakpoint; i >= 0; i--){
		if (power(i) <= n){
			binary[i] = 1;
			n = n - power(i);
		}
		else{
			binary[i] = 0;
		}
	}
	int value = 0, binary1[breakpoint];
	for (int i = 0, j = breakpoint; i <= breakpoint; i++, j--){
		binary1[i] = binary[j];
	}
	for (int i = 0; i <= breakpoint; i++){
		if (binary1[i] == 1){
			value += power(i);
		}
	}
	cout << value << endl;
}