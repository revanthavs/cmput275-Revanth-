#include <iostream>
using namespace std;

int main() {
	int input_num1, input_num2; cin >> input_num1 >> input_num2;
	int digits1[3] = {}, digits2[3] = {};
	for (int i = 0; i < 3; i++) {
		digits1[i] = input_num1 % 10; input_num1 = input_num1 / 10;
		digits2[i] = input_num2 % 10; input_num2 = input_num2 / 10;
 	}
 	for (int i = 0; i < 3; i++) {
 		if (digits1[i] == digits2[i]) continue;
 		else if (digits1[i] < digits2[i]) {
 			cout << digits2[0] << digits2[1] << digits2[2] << endl;
 			return 0;
 		}
 		else if (digits1[i] > digits2[i]) {
 			cout << digits1[0] << digits1[1] << digits1[2] << endl;
 			return 0;
 		}
 	}
 	
 	return 0;
}