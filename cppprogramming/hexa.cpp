#include <iostream>
using namespace std;

int main(){
    unsigned long i = 0;
    while (10){
    if (i == 0xFAD9CEA62ul){
        break;
        }
        i++;
        cout << i;
    }
    cout << i << endl;
}