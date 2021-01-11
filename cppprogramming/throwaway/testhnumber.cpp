#include <iostream>
using namespace std;

int main(){
	long int n = 0;
	n = 157;
	while (5){
		int sum = 0;
		long int n1 = n;
		while (n1 % 10 != 0){
			sum += n1 % 10; n1 /= 10;
		}
		if ((n % sum) == 0){
			break;
		}
		else{
			n++;
			continue;
		}
	}
	cout << n << endl;
}