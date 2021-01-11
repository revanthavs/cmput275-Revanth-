#include <iostream>
using namespace std;

int main(){
    int n = 0, i = 0, x = 0;
    cin >> n;
    while (4){
        if (i == 2)
        {
            x < 0 ? (x = -x) : (n = x);
            cout << x << endl;
            break;
        }
        x = n % 10; n = n / 10;
        i++;
        if (n == 0){
            if (i == 2){
                x < 0 ? (x = -x) : (n = x);
                cout << x << endl;
                break;
            }
            cout << n << endl;
            break;
        }
    }
    return -1;
}