#pragma once
#include <fstream>
#include "Students.h"
class DataBase {

private:
	string pathToFile;
public:
	void createDataBase(string _pathToFile);
	void addToData(string studentData);
};