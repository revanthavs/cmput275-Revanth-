#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
	int time = 0; char name;
	unordered_map<char, long int> final_scores;
	unordered_map<char, int> wrong_records;

	while (true) {
		string temp;
		cin >> time;
		if (time < 0) break;
		cin >> name;
		cin >> temp;
		if (temp.compare("right") == 0) {
			if (wrong_records.find(name) == wrong_records.end()) {
				final_scores[name] = time;
			}
			else {
				final_scores[name] = time + (wrong_records[name] * 20);
			}
		}
		else if (temp.compare("wrong") == 0) {
			if (wrong_records.find(name) == wrong_records.end())  {
				wrong_records[name] = 1;
			}
			else {
				wrong_records[name]++;
			}
		}
	}
	long int total_score = 0;
	for (auto i: final_scores) {
		total_score += i.second;
	}
	cout << final_scores.size() << " " << total_score << endl;
	return 0;
}