#include <iostream>
using namespace std;

void fun1(){
	char x = 'a';
	cout << x << endl;
	return;
}

void fun2(){
	int y;
	// int s = 1;
	// cout << (y + s) << endl;
	cout << y << endl;
	return;
}

void fun3(){
	char z;
	cout << z << endl;
	return;
}

int main(){
	fun1();
	fun2();
	fun3();
	cout << "It's works!!\n";
	return 0; 
}