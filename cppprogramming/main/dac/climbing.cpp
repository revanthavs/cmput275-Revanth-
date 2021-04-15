#include <iostream>
#include <vector>

using namespace std;

typedef unsigned int uint;

bool climb(const uint *heights, uint length, uint rest, uint limit, uint key) {
	if (key < heights[0]) return false;
	if (key >= heights[length - 1]) return true;

	uint start = 0, num_rests = 0, tot_climbing = key;
	uint i = start;

	// for (i = start; i < length; i++) {
	while (i < length) {
		if (i == length - 1) {
			if (tot_climbing >= heights[i]) {
				if (heights[length - 1] + (num_rests * rest) <= limit) {
					return true;
				}
				else return false;
			}
			else if (tot_climbing < heights[i]) {
				num_rests++;
				tot_climbing = heights[i-1] + key;
				// start = i;
				uint diff = heights[i] - heights[i-1];
				if (key < diff) return false;
				continue;
			}
		}
		if (tot_climbing > heights[i]) {
			i++;
			continue;
		}
		else if (tot_climbing <= heights[i]) {
			if (tot_climbing == heights[i]) {
				num_rests++;
				tot_climbing = heights[i] + key;
				// start = i + 1;
				uint diff = heights[i+1] - heights[i];
				i++;
				if (key < diff) return false;
				continue;
			}
			else if (tot_climbing < heights[i]) {
				num_rests++;
				tot_climbing = heights[i-1] + key;
				// start = i;
				uint diff = heights[i] - heights[i-1];
				if (key < diff) return false;
				continue;
			}
		}
	}
}

uint climbing(const uint *heights, uint length, uint rest, uint limit) {
    // Your implementation goes here
	// vector<uint> mim_burst;
	uint mim_burst = 0;
    int high = length - 1;
    int low = 0;
    // To check if the largest number satisfies
    bool check = climb(heights, length, rest, limit, heights[high]);
    // if (check) mim_burst.push_back(heights[high]);
    if (check) mim_burst = heights[high];
    else return -1;
    // To check if the lowest number satisfies
    check = climb(heights, length, rest, limit, heights[low]);
    // if (check) mim_burst.push_back(heights[low]);
    if (check) (mim_burst < heights[low]) ? mim_burst = mim_burst : mim_burst = heights[low];
    int middle = (high + low) / 2;
    while (low <= high) {
    	middle = (high + low) / 2;

    	check = climb(heights, length, rest, limit, heights[middle]);
    	if (check) {
    		// mim_burst.push_back(heights[middle]);
    		(mim_burst < heights[middle]) ? mim_burst = mim_burst : mim_burst = heights[middle];
    		high = middle - 1;
    		continue;
    	}
    	else {
    		low = middle + 1;
    	}
    }
    // for (auto it: mim_burst)
    // 	cout << it << endl;
    // uint something = 0;
    // return something;
    return mim_burst;
}

// int main() {
// 	uint mountain5[] = {13, 14, 15, 18, 20, 22, 23, 28, 30, 31, 32, 36, 40, 42};
//     std::cout << climbing(mountain5, sizeof(mountain5) / sizeof(uint), 2 ,48) << std::endl;
// }

// int main(){
// 	uint n = 0;
// 	cin >> n;
// 	uint a[n];
// 	for (uint i = 0; i < n; i++) {
// 		cin >> a[i];
// 	}
// 	// uint a[] = {30, 70, 95, 120, 145, 190};
// 	uint key = 0; int out = 0;
// 	// cin >> key;
// 	// uint check = climbing(a, 6, 10, 210);
// 	// (check) ? out = 1: out = -1;
// 	cout << check << endl;
// 	return 0;
// }