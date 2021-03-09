#include <iostream>
#include <string>
using namespace std;

int main() {
  
  int a[100], b[100], product[200];
  int temp, n, m, i, j;
  string num1, num2;
  // char num1[101], num2[101];
  // Read the input
  cin >> n >> m;
  for (i = 0; i < n; i++){
    char a;
    cin >> a;
    num1 += a;
  }

  for (i = 0; i < m; i++){
    char b;
    cin >> b;
    num2 += b;
  }

  // Solve the problem
  
  for (i = n-1,j = 0; i >= 0; i--,j++){
    a[j] = num1[i] - '0';
  }
  for (i = m-1,j = 0; i >= 0; i--, j++){
    b[j] = num2[i] - '0';
  }
  for (i = 0; i < m; i++){
    for (j = 0; j < n; j++){
      product[i+j] += b[i]*a[j];
    }
  }
  for(i = 0; i < n+m; i++){
    temp = product[i]/10;
    product[i] = product[i]%10;
    product[i+1] = product[i+1] + temp;
  }
  for (i = (n+m)-1; i >= 0; i--){
    if (i != 0)
      cout << product[i]<< " ";
    else
      cout << product[i];
  }
  cout << endl;
  // for (i = n+m; i >= 0; i--){
  //   if (product[i] > 0)
  //     break;
  // }
  // for(;i >= 0; i--){
  //   if (i != 0)
  //     cout << product[i] << " ";
  //   else
  //     cout << product[i];
  // }
  // cout << endl;
  return 0;
}
