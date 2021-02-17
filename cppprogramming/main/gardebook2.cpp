#include <iostream>
#include <vector>
#include <string>
#include "gardeclass.h";
using namespace std;


void GradeBook::addStudent(int ID, string name, float GPA){
	if (ID < 10000000 || ID > 99999999){
		cout << "Could not add new student: Student ID incorrect length \n";
		return;
	}
	if (GPA < 0) GPA = 0;
	if (Gpa > 4) GPA = 4;

	StudentRecord newStudent = {ID, name, GPA};
	students.push_back(newStudent);
}

void GradeBook::getGPA(int ID){
	for(auto student: students){
		if (student.ID == ID){
			cout << "Student " << ID << " has a GPA of " << student.GPA << endl;
			return;
		}
	}
	cout << "Student " << ID << " not found." << endl;
	return;
}

void GradeBook::setGPA(int ID, float GPA){
	for (auto& student : students){
		if (student.ID == ID){
			student.GPA = GPA;
			return;
		}
	}
	cout << "Student " << ID << " not found.\n";
	return;
}


int main(){
	char tok;
	int ID;
	string name;
	float GPA;
	GradeBook grades;
	cin >> tok;

	while (tok != 'Q'){
		if(tok == 'A'){
			cin >> ID >> name >> GPA;
			grades.addStudent(ID, name, GPA);
		}else if(tok == 'G'){
			cin >> ID;
			grades.getGPA(ID);
		}else if(tok == 'S'){
			cin >> ID >> GPA;
			grades.setGPA(ID, GPA);
		}
		cin >> tok;
	}
}