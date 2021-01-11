#include <iostream>
using namespace std;

int main(){
	int n = 0,i = 0;
	cin >> n;
	int r[n], e[n], c[n];
	for (i = 0; i < n; i++){
		cin >> r[i] >> e[i] >> c[i];
	}
	for (i = 0; i < n; i++){
		if (r[i] < e[i] - c[i]){
			cout << "advertise" << endl;
		}
		else{

			if (r[i] == e[i] - c[i]){
				cout << "does not matter" << endl;
				}
			else {
				cout << "do not advertise" << endl;
				}
			}
		}	
}