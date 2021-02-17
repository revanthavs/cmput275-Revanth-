#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct StudentRecord{
	int ID;
	string name;
	float GPA;
};

class GradeBook{
	GradeBook(){	}

	void addStudent(int ID, string name, float GPA){
		if (ID < 10000000 || ID > 99999999){
			cout << "Could not add new student: Student ID incorrect length \n";
			return;
		}
		if (GPA < 0) GPA = 0;
		if (Gpa > 4) GPA = 4;

		StudentRecord newStudent = {ID, name, GPA};
		students.push_back(newStudent);
	}

	void getGPA(int ID){
		for(auto student: students){
			if (student.ID == ID){
				cout << "Student " << ID << " has a GPA of " << student.GPA << endl;
				return;
			}
		}
		cout << "Student " << ID << " not found." << endl;
		return;
	}

	void setGPA(int ID, float GPA){
		for (auto& student : students){
			if (student.ID == ID){
				student.GPA = GPA;
				return;
			}
		}
		cout << "Student " << ID << " not found.\n";
		return;
	}

	private :
		vector<StudentRecord> students;
}