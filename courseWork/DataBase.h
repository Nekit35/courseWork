#pragma once
#include <fstream>
#include "Students.h"
#include "CryptoTools.h"
class DataBase {

private:
	string pathToFile;
	char* studentData;
public:
	void setPathToDB(string path) { pathToFile = path; }
	string getPathToDB() { return pathToFile; }
	DataBase();
	void createDataBase();
	void addToData(const char* _studentData);

	char * getDataFromDB();
	MyList<char*> getStrStudents();
	MyList<Student*> getStudents();
	
};