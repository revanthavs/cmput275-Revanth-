#include <iostream>
using namespace std;

int* maxSubArraySum(int a[], int size) 
{ 
    int max_so_far = INT_MIN, max_ending_here = 0, 
       start =0, end = 0, s=0; 
  
    for (int i=0; i< size; i++ ) 
    { 
        max_ending_here += a[i]; 
  
        if (max_so_far < max_ending_here) 
        { 
            max_so_far = max_ending_here; 
            start = s; 
            end = i; 
        } 
  
        if (max_ending_here < 0) 
        { 
            max_ending_here = 0; 
            s = i + 1; 
        } 
    } 
    int b[2];
    b[0] = start;
    b[1] = end;
    return b;
}

int main() 
{ 
    int N = 0 , P = 0;
    cin >> N >> P;
    int a[N];
    for (int i = 0; i < N ; i++){
        cin >> a[i];
    }
    int sum = 0; 
    int n = sizeof(a)/sizeof(a[0]); 
    int* max_sum = maxSubArraySum(a, n);
    int price = max_sum[1] - max_sum[0];
    for (int i = max_sum[0]; i <= max_sum[1]; i++){
        sum += a[i];
    }
    cout << price<< endl;
    price = P * price;
    cout << price<<endl;
    cout << sum<<endl;
    cout << (sum - price) << endl;
    return 0;
} 