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
		res.push_back(new Student);
		char* strStud = students[i];
		char* studName = new char[64];
		birthday date;
		int j = 0;
		int k = 0;
		while (strStud[j] != ':') {
			studName[k] = strStud[j];
			j++;
			k++;
		}
		studName[k] = '\0';
		k = 0;
		j++;
		res[i]->setStudentName(studName);
		char* birthday = new char[11];
		while (strStud[j] != ':') {
			birthday[k] = strStud[j];
			j++;
			k++;
		}
		k = 0;
		j++;
		date.setDate(birthday);
		res[i]->setStudentBirthday(date);
		char* admissionYear = new char[11];
		while (strStud[j] != ':') {
			admissionYear[k] = strStud[j];
			j++;
			k++;
		}
		k = 0;
		j++;
		int admDate[5];
		sscanf_s(admissionYear, "%d", admDate);
		res[i]->setAdmissionYear(admDate[0]);
		char* faculty = new char[64];
		while (strStud[j] != ':') {
			faculty[k] = strStud[j];
			j++;
			k++;
		}
		faculty[k] = '\0';
		k = 0;
		j++;
		res[i]->setFaculty(faculty);
		char* department = new char[64];
		while (strStud[j] != ':') {
			department[k] = strStud[j];
			j++;
			k++;
		}
		department[k] = '\0';
		k = 0;
		j++;
		res[i]->setDepartment(department);
		char* group = new char[64];
		while (strStud[j] != ':') {
			group[k] = strStud[j];
			j++;
			k++;
		}
		group[k] = '\0';
		k = 0;
		j++;
		res[i]->setGroup(group);
		char* recordBookId= new char[64];
		while (strStud[j] != ':') {
			recordBookId[k] = strStud[j];
			j++;
			k++;
		}
		recordBookId[k] = '\0';
		k = 0;
		j++;
		res[i]->setRecordBookId(recordBookId);
		char* gender = new char[64];
		while (strStud[j] != ':') {
			gender[k] = strStud[j];
			j++;
			k++;
		}
		gender[k] = '\0';
		k = 0;
		j++;
		res[i]->setGender(gender);
		char* resAllSession = new char[2048];
		while (strStud[j] != ':') {
			resAllSession[k] = strStud[j];
			j++;
			k++;
		}
		resAllSession[k] = '\0';
		k = 0;
		j++;
	}

	return res;
}
