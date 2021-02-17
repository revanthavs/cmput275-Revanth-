#include "gardeclass.h"
#include <iostream>
#include <string>
using namespace std;

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