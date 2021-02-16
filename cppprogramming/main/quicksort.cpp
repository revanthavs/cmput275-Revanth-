#include <iostream>
using namespace std;

template <typename T>
void swap(T* ele1, T* ele2){
	T* temp = *ele1;
	*ele1 = *ele2;
	*ele2 = *temp;
	return;
}

template <typename T>
int partition(T* arr, int low, int high){
	int pivotIndex = (low - 1);
	T pivotKey = arr[high];

	for (int i = low; i < high; i++){
		if (arr[i] <= pivotKey){
			pivotIndex++;
			swap(arr[pivotIndex], arr[i]);
		}
	}

	swap(arr[pivotIndex+1], arr[high]);

	return (pivotIndex + 1);
}

template <typename T>
void quickSort(T* arr, int low, int high){
	if (low < high){
		int pivotIndex = partition(arr, low, high);

		quickSort(arr, low, pivotIndex - 1);
		quickSort(arr, pivotIndex + 1, high);
	}
}

int main(){
	int n = 0;
	cin >> n;
	int array[n];
	for (int i = 0; i < n; i++)
		cin >> array[i];
	quickSort(array, 0, n-1);
	cout << "Sorted array is: \n";
	for (int i = 0; i < n; i++){
		cout << array[i] << " ";
	}
	cout << endl;
	return 0;
}