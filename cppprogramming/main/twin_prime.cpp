#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int n){
	for (int i = 2; i <= sqrt(n); i++){
		if (n % i == 0)
			return false;
	}
	return true;
}

void twinPrime(int n){
	int prev = 2, next = 3;
	int count = 0;
	while (count < n){
		if (prev == (next - 2)){
			cout << prev << " " << next << endl;
			prev = next;
			count++;
			while (!isPrime(++next))
				continue;
		}
		else{
			prev = next;
			while (!isPrime(++next))
				continue;
		}
	}
}

int main(){
	char type; int n;
	cin >> type >> n;
	// for (int i = 2; i < n; i++){
		// bool result = isPrime(i);
		// if (result)
			// cout << i << endl;
	// }
	if (type == 'p')
		if (isPrime(n))
			cout << "prime" << endl;
		else
			cout << "not prime" << endl;
	if (type == 't')
		twinPrime(n);
	return 0;
}