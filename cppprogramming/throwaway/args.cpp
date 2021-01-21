#include <iostream>
using namespace std;

void swap(int& , int&);
void pow(int *, int);
int main(){
	int num1 = 10, num2 = 20;
	cout << num1 << " " << num2 << endl;
	swap(num1, num2);	
	cout << num1 << " " << num2 << endl;
	int array[5] = {1,2,3,4,5};
	pow(array, 5);
	for (auto x: array)
		cout << x << " ";
	cout << endl;
	return 0;
}

void pow(int *array, int len){
	for (int i = 0 ; i < len; i++)
		*(array + i) *= *(array + i);
}

void swap(int& num1, int& num2){
	int tmp = num1;
	num1 = num2;
	num2 = tmp;
	return;
}