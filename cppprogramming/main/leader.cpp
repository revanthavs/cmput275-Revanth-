#include <iostream>
using std::cin;
using std::cout;
using std::endl;

void swap(int &val1, int &val2){
	int temp;
	temp = val1;
	val1 = val2;
	val2 = temp;
	return;
}

void reverse(int *begin, int *end){
	if (begin == end || begin > end)
		return;
	int total = end - begin;
	for (int i = 0; i < total/2; i++){
		swap(*(begin+i),*(end-i-1));
	}
	return;
}

int main(){
	int n, led = 0, i = 0, arrindex = 0, count = 0;
	cin >> n;
	int elements[n]; int leaders[n] = {};
	for (i = 0; i < n; i++){
		cin >> elements[i];
		leaders[i] = -1;
	}
	while (led < n){
		for (i = led+1; i<n; i++){
			if (elements[led] <= elements[i]){
				led = i;
				continue;
			}
		}
		if (i == n){
			leaders[arrindex] = led;
			arrindex++;led++;count++;
		}
	}
	// int count = 0;
	for (i = 0; i < count ; i++){
		if (i != (count-1))
			cout << elements[leaders[i]] << " ";
		else
			cout << elements[leaders[i]] << endl;
	}
	cout << count << endl;
	for (i = 0; i < count; i++){
		if (i == 0)
			reverse(elements,elements+leaders[i]);
		else
			reverse(elements+leaders[i-1]+1,elements+leaders[i]);
	}
	for (i = 0; i < n; i++)
		if (i != (n-1))
			cout << elements[i] << " ";
		else
			cout << elements[i] << endl;
	// cout << endl;
	return 0;
}

