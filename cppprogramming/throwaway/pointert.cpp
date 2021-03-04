#include <iostream>
using namespace std;

int main(){
	int coins[7] = {1, 2, 3, 4, 5 ,6, 7};
	double expenses[2] = {100.0, 200.0};
	int *i_ptr = coins; double *d_ptr = expenses;
	cout << *i_ptr << " " << *d_ptr << endl;
	i_ptr += 1; d_ptr += 1;
	// i_ptr++; d_ptr++;
	cout << *i_ptr << " " << *d_ptr << endl;
	return 0;
}