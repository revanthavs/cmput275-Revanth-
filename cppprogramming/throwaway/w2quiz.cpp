#include <iostream>
using namespace std;

// struct complex{
	// int re;
	// double img;
// }num1, num2[2];

// I am able to access the (num2+1)->re; but not with *(num2+1).re; aren't they same

struct Point2D{
	int x = 0;
	int y = 0;
	char label[8] = "origin";
} pointA, pointB[2];

int main(){
	cout << sizeof(pointA) << endl;
	(pointB+1)->x = -1;
	(*(pointB)).x = 2;
	pointA.x = 1;
	Point2D * ptr = &pointB[1];
	cout << ptr->x << endl;
	// int * const ptr = NULL, var; ptr = &var;
	// double *ptr = 0x7ffeebfa2a9c;
	// char word[20] = "first name"; &word[4] = NULL;
	// unsigned int var = 10; const unsigned int * ptr = &var; var += *ptr;
	return 0;
}