#include <iostream>
using namespace std;

int main(){
	const char *words[] = {"bee", "dog", "mouse"};
	short word[] = {1,2,1,2,0};
	short pos[] = {2,1,1,3,1};
	char secret[6];
	for (int i = 0; i < 5; ++i){
		secret[i] = *(*(words + *(word+i)) + *(pos + i));
	}
	secret[5] = '\0';
	return 0;
}