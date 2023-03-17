﻿

#include <iostream>
#include <vector>
#include <string>
#include "structures.h"
#include <fstream>
#include "Student.cpp"
using namespace std;

class DataBase {
	
private:
	string pathToFile;
public:
	void createDataBase(string _pathToFile) {
		pathToFile = _pathToFile;
		ofstream oFile(pathToFile);
	}
	void addToData(string studentData) {
		ofstream file;
		file.open(pathToFile, ios::in | ios::binary);
		file << studentData;
		file.close();
	}
};


int main()
{
	DataBase db1;
	db1.createDataBase("db.bin");
	db1.addToData("gay");
	string kek = "string";
	const char* keks = kek.c_str();
	//res1 = { {1, {"phys", 1}}  };

	//name = "Алексей Русаков";
	//resAllSession res;
	Subject subj1 = { "matan", 2 };
	Subject subj2 = { "phys", 5 };
	Subject subj3 = { "math", 3 };
	Subject subj4 = { "rus", 4 };
	resSession res1 = { 1,{subj1, subj2} };
	resSession res2 = { 2,{subj3, subj4} };
	resAllSession reaall = {{res1, res2}};
	Student s1("Алексей Русаков", { 12, 12, 1980 }, 2000, "ИИТ", "Кб-1", "ИТИП-01-00", 1234, "m", reaall);
	return 0;
}
	
