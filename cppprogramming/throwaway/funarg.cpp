#include <iostream>
using namespace std;

void fun1(){
	int x = 5;
	cout << x << endl;
	return;
}

void fun2(){
	int y;
	cout << y << endl;
	return;
}

int main(){
	fun1();
	fun2();
	cout << "It's works!!\n";
	return 0; 
}