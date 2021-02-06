// Created by Jordan Van Den Bruel
// January 18, 2020
// Accompanied by the worksheet on eClass for Lecture 6 (read before doing the exercises)

#include <iostream>
#include <string>
using namespace std;

int main()
{
     // Exercise 1: Stack or Heap
     // 1. Stack
     int number = 5;

     // 2. Heap
     string *word = new string;
     *word = "hello";

     // 3. Heap
     bool *boolean = new bool;
     *boolean = true;

     // 4. Stack
     int heapNumbers[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

     // 5. Heap
     char *character = new char;
     *character = 'X';

     // Exercise 2: Make this on the heap instead
     char *heapLetter = new char;
     char stackLetter = 's';
     *heapLetter = 'h';

     bool *heapBoolean = new bool;
     bool stackBoolean = false;
     *heapBoolean = true;

     float *heapArray = new float[3];
     float stackArray[3];
     stackArray[0] = 1.0;
     stackArray[1] = 1.1;
     stackArray[2] = 1.2;

     // float heapArray[3];
     heapArray[0] = 1.0;
     heapArray[1] = 1.1;
     heapArray[2] = 1.2;

     // Exercise 3: Check where it's stored
     // note that this won't work properly for the heap elements until you make them
     cout << "Stack letter location: " << (void *)&stackLetter << endl;
     cout << "Stack boolean location: " << &stackBoolean << endl;
     cout << "Stack array location: " << &stackArray << endl;
     cout << "First item in stack array location: " << &stackArray[0] << endl
          << endl;

     cout << "heap letter location: " << (void *)heapLetter << endl;
     cout << "heap boolean location: " << heapBoolean << endl;
     cout << "heap array location: " << heapArray << endl;
     cout << "First item in heap array location: " << &heapArray[0] << endl
          << endl;

     cout << endl;

     // Exercise 4: Remember to delete
     // delete the character here
     // delete heapLetter;

     // delete the boolean here
     // delete heapBoolean;
     // delete the array here. Be careful with this one!
     // delete[] heapArray;
     // Exercise 5: Which variables can you use?

     // first set of variables
     int num1 = 3;
     int *num2 = new int;
     *num2 = 5;

     // what will this print?
     // 3 and address of num2
     // address of num1 and 5
     cout << "num1: " << num1 << " num2: " << num2 << endl;
     cout << "&num1: " << &num1 << " *num2: " << *num2 << endl;
     cout << endl;

     // next group of variables
     int num3 = num1 - 1;//2
     // int *num4 = new int;
     // num4 = num3;
     int *num5 = new int;
     num5 = &num3;

     // what will this print?
     cout << "num3: " << num3 << " &num3: " << &num3 << endl;
     cout << "num4: " << num4 << " &num4: " << &num4 << " *num4: " << *num4 << endl;
     cout << "num5: " << num5 << " &num5: " << &num5 << " *num5: " << *num5 << endl;
     cout << endl;

     // final set of variables
     // int *num6 = new int;
     // num6 = num1;
     num1 = 5;
     int *num7 = new int;
     num7 = num2;
     *num2 = 8;
     int *num8 = new int;
     num8 = &num1;
     int **num9 = &num5;

     // what will each of these print?
     cout << "num6: " << num6 << " &num6: " << &num6 << " *num6: " << *num6 << endl;
     cout << "num7: " << num7 << " &num7: " << &num7 << " *num7: " << *num7 << endl;
     cout << "num8: " << num8 << " &num8: " << &num8 << " *num8: " << *num8 << endl;
     cout << "num9: " << num9 << " &num9: " << &num9 << " *num9: " << *num9 << " **num9: " << **num9 << endl;

     // Exercise 6: Examine the code
     cout << "Exercise 6" << endl;
     unsigned int n;
     cin >> n;
     int **array = new int*[n];
     for (int i = 0; i < n; i++) {
          array[i] = new int;
          cin >> *array[i];
     }

     cout << "You entered:";
     for (int i = 0; i < n; i++) {
          cout << ' ' << *array[i];
          delete array[i];
     }
     cout << endl;

     delete[] array;

     // Exercise 7: Declaring multiple varisables
     char a, b;
     char *c, d;
     char **e, f;

     // Exercise 8: Dynamic Memory Inception
     cout << "Exercise 8" << endl;

     // Exercise 9: Getting more comfortable with delete

     return 0;
}
