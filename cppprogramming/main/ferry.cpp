#include <iostream>
#include <queue>
using namespace std;

int main() {
	// Read in the input
	int n_w = 0, n_e = 0; bool west = true;
	cin >> n_w >> n_e;
	unsigned long long int total_time = 0;
	queue<unsigned long int> west_side;
	queue<unsigned long int> east_side;
	for (int i = 0; i < n_w; i++){
		unsigned long int temp = 0;
		cin >> temp;
		west_side.push(temp);
	}
	for (int i = 0; i < n_e; i++){
		unsigned long int temp = 0;
		cin >> temp;
		east_side.push(temp);
	}
	unsigned long int current_time = 0;
	// current_time = west_side.front();
	// total_time += current_time + 100;
	// west_side.pop(); west = false;
	// Solve the problem
	while (!west_side.empty() || !east_side.empty()){
		if (!west_side.empty() && !east_side.empty()){
			unsigned long temp1 = west_side.front(), temp2 = east_side.front();
			if (total_time <= temp1 || total_time <= temp2){
				if (total_time <= temp1 && total_time <= temp2){
					if (temp1 <= temp2){
						if (west){
							current_time = west_side.front() - total_time;
							total_time += current_time + 100;
							west_side.pop(); west = false;
							continue;
						}
						else{
							current_time = west_side.front() - total_time;
							total_time += current_time + (100*2);
							west_side.pop(); west = false;
							continue;
						}
					}
					else if(temp2 <= temp1){
						if (west){
							current_time = east_side.front() - total_time;
							total_time += current_time + (100*2);
							east_side.pop(); west = true;
							continue;
						}
						else{
							current_time = east_side.front() - total_time;
							total_time += current_time + 100;
							east_side.pop(); west = true;
							continue;
						}
					}	
				// 	if (west){
				// 		current_time = west_side.front();
				// 		current_time = current_time - total_time;
				// 		total_time += current_time + 100;
				// 		west_side.pop(); west = false;
				// 		continue;
				// 	}
				// 	else{
				// 		current_time = east_side.front();
				// 		current_time = current_time - total_time;
				// 		total_time += current_time + 100;
				// 		east_side.pop(); west = true;
				// 		continue;
				// 	}
				}
				else if (temp1 <= total_time){
					if (west){
						current_time = west_side.front();
						total_time += 100;
						west_side.pop(); west = false;
						continue;
					}
					else{
						current_time = west_side.front();
						total_time += (100*2);
						west_side.pop(); west = false;
						continue;
					}
				}
				else if (temp2 <= total_time){
					if (west){
						current_time = east_side.front();
						total_time += (100*2);
						east_side.pop(); west = true;
						continue;
					}
					else{
						current_time = east_side.front();
						total_time += 100;
						east_side.pop(); west = true;
						continue;
					}

				}
				else if (total_time <= temp2){
					if (west){
						current_time = east_side.front();
						total_time += current_time + (100*2);
						east_side.pop(); west = true;
						continue;
					}
					else{
						current_time = east_side.front();
						total_time += current_time + 100;
						east_side.pop(); west = true;
					}
				}
			}
			else if(temp1 < temp2){
				if (west){
					total_time += 100;
					west_side.pop(); west = false;
					continue;
				}
				else{
					total_time += (100*2);
					west_side.pop(); west = false;
					continue;
				}
			}
			else if(temp1 > temp2){
				if (west){
					total_time += (100*2);
					east_side.pop(); west = true;
					continue;
				}
				else{
					total_time += 100;
					east_side.pop(); west = true;
					continue;
				}
			}
		}
		else if (!west_side.empty()){
			if (total_time <= west_side.front()){
				if (west){
					current_time = west_side.front();
					current_time = current_time - total_time;
					total_time += current_time + 100;
					west_side.pop(); west = false;
					continue;
				}
				else{
					current_time = west_side.front();
					current_time = current_time - total_time;
					total_time += current_time + (100*2);
					west_side.pop(); west = false;
					continue;
				}
			}
			else if (west){
				total_time += 100;
				west_side.pop(); west = false;
				continue;
			}
			else{
				total_time += (100*2);
				west_side.pop(); west = false;
				continue;
			}
		}
		else{
			if (total_time <= east_side.front()){
				if (west){
					current_time = east_side.front();
					current_time = current_time - total_time;
					total_time += current_time + (100*2);
					east_side.pop(); west = true;
					continue;
				}
				else{
					current_time = east_side.front();
					current_time = current_time - total_time;
					total_time += current_time + 100;
					east_side.pop(); west = true;
					continue;
				}
			}
			if(west){
				total_time += (100*2);
				east_side.pop(); west = true;
				continue;
			}
			else{
				total_time += 100;
				east_side.pop(); west = true;
				continue;
			}
		}

	}


	// Output the result
	cout << total_time << endl;

	return 0;
}


				// else if(total_time <= temp1){
				// 	if (west){
				// 		current_time = west_side.front();
				// 		total_time += current_time + 100;
				// 		west_side.pop(); west = false;
				// 		continue;
				// 	}
				// 	else{
				// 		current_time = west_side.front();
				// 		total_time += current_time + (100*2);
				// 		west_side.pop(); west =false;
				// 		continue; 
				// 	}
				// }