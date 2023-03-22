#pragma once
#include <fstream>
#include "Students.h"
class DataBase {

private:
	string pathToFile;
	char* studentData;
public:
	DataBase();
	void createDataBase(string _pathToFile);
	void addToData(const char* _studentData);
	void setPathToFile(string _pathToFile);

	char * getData();
	vector<char*> getStrStudents();
	vector<Student*> getStudents();
	
};