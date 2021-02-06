// Remember, style matters!
#include <iostream>
using namespace std;

bool BinarySearch(unsigned int array[], int high,unsigned int key){
	int low = 0, mid = 0;
	if (array[low] >= key){
		if (array[low] == key)
			return true;
		else
			return false;
	}
	
	while (high > low){
		mid = (low + high) / 2;
		if (array[low] < key || array[high] > key){
			if (array[low] == key)
				return true;
			else if (array[high] == key)
				return true;
			else if (array[mid] == key)
				return true;
			else{
				if (array[mid] > key)
					high = mid - 1;
				else if (array[mid] < key)
					low = mid + 1;
			}
		}
	}
	return false;
}

int main(){
	unsigned int n; long unsigned int T; bool cflag = true;
	cin >> n >> T;
	unsigned int prices[n]; int last_i = 0;
	for (unsigned int i = 0; i < n; i++){
		cin >> prices[i];
		if (prices[i] <= T)
			last_i = i;
	}
	while (last_i >= 0){
		cflag = BinarySearch(prices, last_i-1, (T - prices[last_i]));
		if (cflag){
			cout << "YES\n";
			break; 
		}
		else{
			--last_i;
			continue;
		}
	}
	if (last_i < 0)
		cout << "NO\n";
	return 0;
}