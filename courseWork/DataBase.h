#pragma once
#include <fstream>
#include "Students.h"
class DataBase {

private:
	string pathToFile;
public:
	void createDataBase(string _pathToFile);
	void addToData(const char* studentData);
	void setPathToFile(string _pathToFile);
};