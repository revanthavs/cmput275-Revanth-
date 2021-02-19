#include <iostream>
using namespace std;

int main(){
	unsigned int num_rows, num_cols;
	float init;
	cin >> num_rows >> num_cols >> init;
	float **totalarray = new float*[num_rows];
	for (int i = 0; i < num_rows; i++){
		totalarray[i] = new float[num_cols];
	}
	for (int i = 0; i < num_rows; i++){
		for (int j = 0; j < num_cols; j++){
			totalarray[i][j] = init;
		}
	}

	cout << "The Matrix entered is: \n";
	for (int i = 0; i < num_rows; i++){
		for (int j = 0; j < num_cols; j++){
			cout << totalarray[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < num_rows; i++){
		delete[] totalarray[i];
		totalarray[i] = NULL;
	}

	delete[] totalarray;
	totalarray = NULL;
	return 0;
}