#include <iostream>
#include <cmath>	// To use sqrt() function
using namespace std;

/*
	Formal Arguments : int num (number to check)
	return : bool (true or false)
	Checks wheather a given number is prime or non prime number.
	The function runs in O(√n) time.
*/
bool isPrime(int num){
	for (int i = 2; i <= sqrt(num); i++){
		if (num % i == 0)
			// Since the given number is divisble by other number
			return false;
	}
	// Since the given number is divisible by only 1 and itself
	return true;
}

/*
	Formal Arguments : int num (number of twinprimes to print)
	return : None
	Prints the num number of twin primes.
	The function runs in O(n*√n) time.
*/
void twinPrimes(int num){
	int prev = 2, next = 3, count = 0;
	while (count < num){
		// twin prime pairs is of the form (p, p+2).
		if (prev == (next - 2)){
			cout << prev << " " << next << endl;
			prev = next;
			// Since it's a twinprime pair
			count++;
			// updating the next value to next prime
			while (!isPrime(++next))
				continue;
		}
		else{
			prev = next;
			// updating the next value to next prime
			while (!isPrime(++next))
				continue;
		}
	}
}

int main(){
	char type; int num;
	cin >> type >> num;
	if (type == 'p')
		(isPrime(num)) ? cout << "prime" << endl : cout << "not prime" << endl;
	else if (type == 't')
		twinPrimes(num);
	else
		cout << "Enter either in the form of:-\n'p n' p - prime n - number\n't k' t - twinprimes k - number of pairs"<<endl;
	return 0;
}