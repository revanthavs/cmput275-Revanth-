#include <iostream>
using namespace std;

int main(void){
    unsigned short int x1 = 0; short int x2 = 0; unsigned int x3 = 0; int x4 = 0; long x5 = 0; unsigned long x6 = 0; long long int x7 = 0;
    unsigned long long int x8 = 0;
    cout << "USI = " << sizeof(x1) << endl;
    cout << "SI = " << sizeof(x2) << endl;
    cout << "UI = " << sizeof(x3) << endl;
    cout << "I = " << sizeof(x4) << endl;
    cout << "LI = " << sizeof(x5) << endl;
    cout << "ULI = " << sizeof(x6) << endl;
    cout << "LLI = " << sizeof(x7) << endl;
    cout << "ULLI = " << sizeof(x8) << endl;
    return -1; 
}