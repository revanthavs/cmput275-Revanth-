#include <iostream>
#include <set>
using namespace std;

int main(){
	set<int> myset = {1,3,5};
	auto some = myset.begin();
	// cout << *some << endl;
	for (auto iter = myset.begin(); iter != myset.end(); iter++){
		cout << *iter << endl;
	}
	return 0;
}