#include <iostream>
using namespace std;

int main(){
    int x = 1, y = 1;
    cin >> x;
    cin >> y;

    x >= 0 ? (y >= 0 ? cout << "1"<< endl : cout << "4" << endl) : (y > 0 ? cout << "2" << endl : cout << "3" << endl);
}