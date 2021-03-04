#include <iostream>
using namespace std;

int main(){
	char my_word[4] = {'c', 'a', 't', '\0'};
	cout << "My_word = \n" << my_word << endl;
	char mystr[6] = "cat";
	cout << "size = \n" << sizeof(mystr) << endl;
	return 0;
}