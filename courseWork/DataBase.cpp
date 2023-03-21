#include "DataBase.h"
void DataBase::createDataBase(string _pathToFile) {
	pathToFile = _pathToFile;
	ofstream oFile(pathToFile);
	oFile.close();
}
void DataBase::addToData(const char * studentData) {
	ofstream file;
	file.open(pathToFile, ios::app | ios::binary);
	file << studentData;
	file.close();
}
void DataBase::setPathToFile(string _pathToFile)
{
	pathToFile = _pathToFile;
}
