#include <iostream>
using namespace std;

int main(){
    int x0 = 0, x1 = 1, prev2 = x1, prev1 = x0, xn = prev1 + prev2, n = 0;
    cin >> n;
    if (n == 0){
        cout << x0 << endl;
        return 0;
    }
    if (n == 1){
        cout << x1 << endl;
        return 0;
    }
    if (n == 2){
        cout << xn << endl;
        return 0;
    }
    for (int i = 2; i <= n; i++){
        int some = xn;
        xn = prev2 + prev1;
        prev2 = xn;
        prev1 = some; 
    }
    cout << xn << endl;
}