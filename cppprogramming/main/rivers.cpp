/*
	Name: Atmakuri Venkata Sai Revanth
	ID: 1684293
	CMPUT 275, Winter 2021

	Exercise 4: Rivers(Interview Problem)
*/
#include <iostream>
#include <vector>	// To keep track of the river sequence
using namespace std;

/*
	Returns the first connecting river to based on the rivers sequence
	Runs in O(n) times.

	Arguments:
		a(int *): Array of the sequence of rivers
		n(int): Number of rivers
		u(int): First river in query
		v(int): Second river in query

	Returns:
		int: The first connecting river
*/

int query(int *a, int n, int u, int v){
	if (u == v){
		// Since given two rivers are same and the
		// first river in the sequence would be itself
		return u;
	}

	// To keep track of the sequence
	vector<int> sequence; int index = 0, temp = u;

	// Since the first river is nothing but ocean
	if (temp == 0)
		sequence.push_back(temp);

	// To find out the sequence of the first river
	while (temp != 0){
		sequence.push_back(temp);
		index++;
		temp = a[temp-1];
	}
	// Since every sequence will finally be connected to ocean(0)
	sequence.push_back(0); index++;
	temp = v; int j = 0;

	// To find the first river at which both the rivers will be connected
	while (temp != 0){
		if (temp == sequence[j]){
			// Since this is the first river found in the sequence
			return temp;
		}
		// Advancing the sequence index such that it's smaller than
		// or equal to second river
		else if (sequence[j] > temp){
			j++;
			continue;
		}
		// Updating the temp to the next connecting river
		temp = a[temp-1];
	}
	return temp;
}

int main(){
	// Reading the input in
	int n, q;
	cin >> n >> q;
	int a[n] = {};
	for (int i = 0; i < n; i++)
		cin >> a[i];
	// Reading the input of query and calling the query function
	// at same time and storing the result in result array
	int u, v, result[q];
	for (int i = 0; i < q; i++){
		cin >> u >> v;
		result[i] = query(a, n, u, v);
	}
	// Printing out the result found for query
	for (int i = 0; i < q; i++){
		cout << result[i] << endl;
	}
	return 0;
}