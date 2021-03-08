#include <iostream>
#include <string>
#include <map>
#include <set>
using namespace std;

int main(){
	unsigned int n = 0, track_i = 0, dir_i = 0;
	cin >> n;
	string track[n];
	set<string> files[n];
	track[track_i] = "/";
	map<string, set<string>> directorys;
	directorys.insert(pair<string, set<string>>(track[track_i], files[dir_i]));
	dir_i++;
	for (int i = 0; i < n; i++){
		string command, name;
		cin >> command >> name;
		if (command == "ls"){
			directorys[track[track_i]].insert(name);
			continue;
		}
		else if (command == "cd"){
			if (name != ".."){
				track_i++;
				if (track_i - 1)
					track[track_i] = track[track_i - 1] + "/" + name;
				else if ((track_i - 1) == 0)
					track[track_i] = track[track_i - 1] + name;
				directorys.insert(pair<string, set<string>>(track[track_i], files[dir_i]));
				dir_i++;
			}
			else if (name == ".."){
				track_i--;
			}
		}
	}
	map<string, set<string>>::iterator itr;
 	set<string>::iterator itr1;
 	for (itr = directorys.begin(); itr != directorys.end(); ++itr){
 		cout << itr->first;
		for (itr1 = itr->second.begin(); itr1 != itr->second.end(); ++itr1){
			cout << " " << *itr1;
		}
		cout << endl;
	}
	return 0;
}

// int main(){
// 	set<string> s1[10];
// 	map<string, set<string>> gquiz1;
// 	s1[0].insert("f1");
// 	s1[0].insert("myfile");
// 	s1[1].insert("f2");
// 	s1[1].insert("testfile");
// 	s1[1].insert("f3");
// 	s1[2].insert("f3");
// 	gquiz1.insert(pair<string, set<string>>("/", s1[0]));
// 	gquiz1.insert(pair<string, set<string>>("/dir1", s1[1]));
// 	gquiz1.insert(pair<string, set<string>>("/dir1/subdir1/subsubldir1", s1[6]));
// 	gquiz1.insert(pair<string, set<string>>("/dir1/subdir2", s1[2]));
// 	gquiz1.insert(pair<string, set<string>>("/dir2", s1[3]));
// 	gquiz1.insert(pair<string, set<string>>("/dir2/subdir3", s1[4]));
// 	gquiz1.insert(pair<string, set<string>>("/dir1/subdir1", s1[5]));
// 	gquiz1["/dir1/subdir1"].insert("f2");
// 	// s1[0].insert("dir1");
// 	// s1[0].insert("dir2");
// 	// s1[1].insert("subdir2");
// 	// s1[1].insert("subdir1");
// 	// s1[1].insert("subdir3");
// 	// s1[2].insert("subsubldir1");
// 	// gquiz1.insert(pair<int, set<string>>(0, s1[0]));
// 	// gquiz1.insert(pair<int, set<string>>(1, s1[1]));
// 	// gquiz1.insert(pair<int, set<string>>(2, s1[2]));
// 	map<string, set<string>>::iterator itr;
// 	set<string>::iterator itr1;
// 	for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr){
// 		cout << "key: " << itr->first << endl;
// 		for (itr1 = itr->second.begin(); itr1 != itr->second.end(); ++itr1){
// 			cout << *itr1 << endl;
// 		}
// 	}
// 	cout << endl;
// 	// set<string>::iterator itr;
// 	// for (itr = s1.begin(); itr != s1.end(); itr++){
// 	// 	cout << *itr << " ";
// 	// }
// 	// cout << endl;
// 	return 0;
// }