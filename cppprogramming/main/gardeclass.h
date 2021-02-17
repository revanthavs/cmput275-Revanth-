#ifndef __GRADECLASS_H__
#define __GRADECLASS_H__
#include <string>
#include <vector>


struct StudentRecord{
	int ID;
	string name;
	float GPA;
};


class GradeBook{
	GradeBook(){	}

	void addStudent(int ID, string name, float GPA);

	void getGPA(int ID);

	void setGPA(int ID, float GPA);

	private :
		vector<StudentRecord> students;
};

#endif