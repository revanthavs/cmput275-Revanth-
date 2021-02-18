#include <iostream>
using namespace std;

int main(){
     cout << "Exercise 8:" << endl;
     unsigned int numArrays;
     cin >> numArrays;
     int **inceptionArray;
     inceptionArray = new int*[numArrays];
     int *arrayLengths = new int[numArrays];
     for (int i = 0; i < numArrays; i++) {
          cin >> arrayLengths[i];
     }

     for (int i = 0; i < numArrays; i++) {
          int *tempArray = new int[arrayLengths[i]];
          inceptionArray[i] = tempArray;
          for (int j = 0; j < arrayLengths[i]; j++) {
               cin >> tempArray[j];
          }
     }

     // printing it out to show we got everything
     cout << "Here are your arrays:" << endl;
     for (int i = 0; i < numArrays; i++) {
          for (int j = 0; j < arrayLengths[i]; j++) {
               cout << inceptionArray[i][j] << " ";
          }
          cout << endl;
     }

     // Exercise 9: Getting more comfortable with delete
     for (int i = 0; i < numArrays; i++) {
          delete[] inceptionArray[i];
     }
     delete[] inceptionArray;
     delete[] arrayLengths;

     return 0;
}