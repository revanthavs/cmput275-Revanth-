#include <iostream>
#include <queue>
using namespace std;

int main(){
	queue<int> my_queue;
	for (int i = 1; i <= 5; i++) {
		my_queue.push(i); // Add i to the back
	}
	while (my_queue.size() > 0) {
		cout << my_queue.front() << endl;
		my_queue.pop();
	} 
}