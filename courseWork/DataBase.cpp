#include "DataBase.h"
void DataBase::createDataBase(string _pathToFile) {
	pathToFile = _pathToFile;
	ofstream oFile(pathToFile);
	oFile.close();
}
void DataBase::addToData(const char * _studentData) {
	ofstream file;
	file.open(pathToFile, ios::app | ios::binary);
	file << _studentData;
	file.close();
}
void DataBase::setPathToFile(string _pathToFile)
{
	pathToFile = _pathToFile;
}
DataBase::DataBase() {
	string standartPath = "Ñ:\\db.bin";
	pathToFile = standartPath;
}
char * DataBase::getData()
{
	char* result = new char[10240];
	string line;
	ifstream file;
	file.open(pathToFile);
	file.seekg(0);
	getline(file, line);
	file.close();
	const char* res = line.c_str();
	int i = 0;
	while (res[i] != '\0') {
		result[i] = res[i];
		i++;
	}
	result[i] = '\0';
	return result;
}
vector<char*> DataBase::getStrStudents()
{
	vector<char*> res;
	int i = 0;
	int flag = 0;
	getData();
	while (getData()[i] != '\0')
	{
		int j = 0;
		char* str = new char[1024];
		char k = getData()[i];
		char m = getData()[i++];
		char n = getData()[i--];
		if ((getData()[i] == '\0') || (getData()[i++] == '\0') || (getData()[i--] == '\0')) { break; }
		if ((getData()[i] == ';')&&(flag==0)) flag = 1;
		if ((getData()[i] == ';') && (flag == 1)) flag = 0;
		if ((getData()[i] == ';') && (flag == 0)&&(getData()[i++] == ';')) flag = 1;
		if (flag) {
			while ((flag)&&(getData()[i] != ';')) {
				str[j] = getData()[i];
				i++;
				j++;
			}
			str[j] = '\0';
		}
		i++;
		
		res.push_back(str);
	}

	return res;
}
vector<Student*> DataBase::getStudents()
{
	vector<Student*> res;
	vector<char*> students = getStrStudents();
	for (int i = 0; i < students.size(); i++) {
		Student stud;
		char* strStud = students[i];
		char* studName = new char[64];
		int j = 0;
		int k = 0;
		while (strStud[j] != ':') {
			studName[k] = strStud[j];
			j++;
			k++;
		}
		k = 0;
		j++;
		stud.setStudentName(studName);

	}
	return res;
}
