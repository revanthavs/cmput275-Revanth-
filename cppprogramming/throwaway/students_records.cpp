#include <iostream>
#include <string>
using namespace std;

struct StudentRecord{
	long unsigned int Student_ID;
	string name;
	float gpa;
};

int main(){
	StudentRecord Alice = {12345678, "ALICE", 4.0};
	StudentRecord Bob;
	Bob.Student_ID = 2345789;
	Bob.name = "Bob";
	Bob.gpa = 3.2;
	cout << Alice.Student_ID << " has a GPA of " << Alice.gpa << ".\n";
	cout << Bob.Student_ID << " has a GPA of " << Bob.gpa << ".\n";
	return 0;
}