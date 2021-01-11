#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
	int numbers[5] = {1,2,3,2,5};
	unordered_set<int> hashtable;
	for (int i = 0; i < 5; i++){
		if (hashtable.find(numbers[i]) != hashtable.end()){
			cout << numbers[i] << " is a dublicate" << endl;
		}
		else
			hashtable.insert(numbers[i]);
	}
}