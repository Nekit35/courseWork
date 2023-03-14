#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Student.cpp"
using namespace std;
class ImportToFile
{
private:
	string filename;

public:
	void setFileName(string _fileName)
	{
		filename = _fileName;
	}
	void recordToDAtaBase(Student::Student)
	{

	}
};

