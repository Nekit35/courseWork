#include "DataBase.h"
void DataBase::createDataBase(string _pathToFile) {
	pathToFile = _pathToFile;
	ofstream oFile(pathToFile);
}
void DataBase::addToData(string studentData) {
	ofstream file;
	file.open(pathToFile, ios::in | ios::binary);
	file << studentData;
	file.close();
}
