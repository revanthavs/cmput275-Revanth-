// Remember, style matters!
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
//#include <set>
#include <vector>
using namespace std;

// struct targets{
//     unsigned int t_files = 0;
//     unordered_map<string, unordered_set<string> > target;
// };

void make_target(string target, vector<string>& track, unordered_set<string>& made_target, unordered_map<string, vector<string>>& files){
    if ((made_target.find(target) != made_target.end()) || (files.find(target) == files.end())){
        return;
    }
    else{
        vector<string>::iterator it;
        for (it = files[target].begin(); it != files[target].end(); it++){
            make_target(*it, track, made_target, files);
        }
        track.push_back(target);
        made_target.insert(target);
    }
}

int main(){
    unsigned int n = 0, m = 0;
    cin >> n >> m;
    // Since the order matters using vector to store files in directory
    // Using unordered_map since find take constant time 
    unordered_map<string, vector<string> > targets;
    // targets names[n];
    for (unsigned int i = 0; i < n; i++){
        unsigned int num = 0; string temp1 = "", temp2 = "";
        cin >> num;
        // names[i].t_files = num;
        cin >> temp1;
        // To remove the : at the end of directory name
        for (unsigned int j = 0; j < temp1.size()-1; j++){
            temp2 += temp1[j];
        }
        // names[i].target[temp2];
        // Creating an empty directory
        targets[temp2];
        // Adding the files to the directory
        for (unsigned int j = 0; j < num; j++){
            string temp = "";
            cin >> temp;
            // names[i].target[temp2].insert(temp);
            targets[temp2].push_back(temp);
        }
    }
    // Since find take constand time using unordered_set
    unordered_set<string> made_target;
    // Since order matters using vector
    vector<string> result;
    for (unsigned int i = 0; i < m; i++){
        // Since we need to set the track for every make command
        // Creating new track for every make
        vector<string> track; string temp = "";
        // Since the first input would be make
        cin >> temp >> temp;
        make_target(temp, track, made_target, targets);
        // Since we haven't done any target the directory is up to date
        if (track.empty()){
            result.push_back("make: `"+temp+"' is up to date.");
            // cout << "make: '" << temp << "' is up to date\n";
        }
        else{
            string temp = "";
            for (auto it = track.begin(); it != track.end(); it++){
                if (it == track.begin())
                    temp += *it;
                else
                    temp += " "+ *it;
            }
            result.push_back(temp);
        }
    }
    for (auto it = result.begin(); it != result.end(); it++){
        cout << *it << endl;
    }
}
