#include <iostream>
#include <vector>
using namespace std;

int query(int *a, int n, int u, int v){
	if (u == v){
		return u;
	}
	vector<int> sequence; int index = 0, s = u, result = 1;
	if (s == 0)
		sequence.push_back(s);
	while (s != 0){
		sequence.push_back(s);
		index++;
		s = a[s-1];
	}
	sequence.push_back(0); index++;
	s = v; int j = 0;
	while (s != 0){
		if (s == sequence[j]){
			return s;
		}
		else if (sequence[j] > s){
			j++;
			continue;
		}
		s = a[s-1];
	}
	return s;
}

int main(){
	int n, q;
	cin >> n >> q;
	int a[n] = {};
	for (int i = 0; i < n; i++)
		cin >> a[i];
	int u, v, result[q];
	for (int i = 0; i < q; i++){
		cin >> u >> v;
		result[i] = query(a, n, u, v);
	}
	for (int i = 0; i < q; i++){
		cout << result[i] << endl;
	}
	return 0;
}