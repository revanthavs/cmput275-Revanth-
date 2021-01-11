#include <iostream>
#include <stack>
using namespace std;

int main(){
	stack<int> list;
	for (int i = 0; i < 5; i++){
		list.push(i);
	}
	while (list.size() > 0) {
		cout << list.top() << endl;
		list.pop(); // Remove the top element
	}
}