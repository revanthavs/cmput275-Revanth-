#include <iostream>
using namespace std;

template <typename T>
struct Complex{
	T real;
	T imag;
	Complex operator+(Complex rhs){
		Complex result;
		result.real = real + rhs.real;
		result.imag = imag + rhs.imag;
		return result;
	}
};

int main(){
	Complex<int> a = {1,2};
	Complex<int> b = {3,4};
	Complex<int> c = a + b;
	cout << c.real << "+i" << c.imag << endl;
	return 0;
}