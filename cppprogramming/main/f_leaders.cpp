/*
   Name: Atmakuri Venkata Sai Revanth
   ID: 1684293
   CMPUT 275, Winter 2021
   
   Interview Problem #2: Leaders
*/
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

/*
	Arguments: int &val1, int &val2 (references of the numbers to be swapped)
	Return: None (Since we are swapping the original variables)
	Swaps the two int number passed from the caller function
*/
void swap(int &val1, int &val2) {
	int temp;
	// temporary variblue to store the value of val1
	temp = val1;
	val1 = val2;
	val2 = temp;
	return;
}

/*
	Arguments: int *begin, int *end 
		(Pointers of start and end of array to be reversed)
	Return: None (Since we are reversing the original array passed)
	Reverses all entries between these pointers including the
	entry pointed to by begin but not the entry pointed to by end
*/
void reverse(int *begin, int *end) {
	// Since the range of items to be reversed is empty
	if (begin == end || begin > end)
		return;
	// Since pointer2 - pointer1 gives the number of elements
	int total = end - begin;
	for (int i = 0; i < total/2; i++) {
		swap(*(begin+i), *(end-i-1)); // Same as passing the address of begin[i] and end[i-1]
	}
	return;
}

int main() {
	// i == index
	int n, led_i = 0, i = 0, arr_i = 0, count = 0, max_ele = -1, max_i = -1;
	bool check = false;
	cin >> n;
	int elements[n] = {}; int leaders[n] = {};
	for (i = 0; i < n; i++) {
		cin >> elements[i];
		leaders[i] = -1;
	}
	// Loops terminates ones all the leaders are been identified
	while (led_i < n) {
		for (i = led_i+1; i < n; i++) {
			// To advance the leader index if there the maximum
			// element is found in subarray
			if ((led_i <= max_i) && check) {
				led_i = max_i + 1;
				leaders[arr_i] = max_i;
				arr_i++; max_i = -1; count++; max_ele = -1; check = false;
				break;
			}
			// If the element at that leader index fail to meet
			// the requirement
			if (elements[led_i] <= elements[i]) {
				led_i = i;
				continue;
			}
			// To find the second maximum number
			// So that we can advance the leader index
			else if (elements[led_i] > elements[i]) {
				if (max_ele <= elements[i]) {
					max_ele = elements[i]; max_i = i;
				}
			}
		}
		// Since the element at the index is grater than all indexs after it
		if (i == n) {
			leaders[arr_i] = led_i;
			arr_i++; led_i++; count++; check = true;
		}
	}
	// To print the leader element
	for (i = 0; i < count ; i++) {
		if (i != (count-1))
			cout << elements[leaders[i]] << " ";
		else
			cout << elements[leaders[i]] << endl;
	}
	// Reverse the elements in the array based on leader indexes
	for (i = 0; i < count; i++) {
		if (i == 0)
			reverse(elements, elements+leaders[i]);
		else
			reverse(elements+leaders[i-1]+1, elements+leaders[i]);
	}
	// The array elements after reversing them based on leader indexes
	for (i = 0; i < n; i++)
		if (i != (n-1))
			cout << elements[i] << " ";
		else
			cout << elements[i] << endl;
	return 0;
}
