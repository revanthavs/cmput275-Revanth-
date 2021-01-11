#include <stdio.h>

int main(){
	int n = 0;
	scanf("%d",&n);
	char string[n];
	for (int i = 0; i < n; i++){
		scanf("%c",&string[i]);
	}
	for (int i = 0, j = n-1; i < (n/2); i++, j--){
		if (string[i] == string[j]){
			continue;
		}
		else{
			printf("Not a Palindrome\n");
			return 0;
		}
	}
	printf("Palindrome\n");
	return 0;
}