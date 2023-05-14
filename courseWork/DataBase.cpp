#include "DataBase.h"
void DataBase::createDataBase() {
	ofstream oFile(pathToFile);
	oFile.close();
}
void DataBase::addToData(const char* _studentData) {
	ofstream file;
	file.open(pathToFile, ios::app | ios::binary);
	file << _studentData;
	file.close();

}
DataBase::DataBase() {
	string standartPath = "db.bin";
	pathToFile = standartPath;
}
char * DataBase::getDataFromDB()
{
	char* result = new char[102400];
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
MyList<char*> DataBase::getStrStudents()
{
	MyList<char*> res;
	int i = 0;
	int flag = 0;
	getDataFromDB();
	while (getDataFromDB()[i] != '\0')
	{
		int j = 0;
		char* str = new char[1024];
		char k = getDataFromDB()[i];
		char m = getDataFromDB()[i++];
		char n = getDataFromDB()[i--];
		if ((getDataFromDB()[i] == '\0') || (getDataFromDB()[i++] == '\0') || (getDataFromDB()[i--] == '\0')) { break; }
		if ((getDataFromDB()[i] == ';')&&(flag==0)) flag = 1;
		if ((getDataFromDB()[i] == ';') && (flag == 1)) flag = 0;
		if ((getDataFromDB()[i] == ';') && (flag == 0)&&(getDataFromDB()[i++] == ';')) flag = 1;
		if (flag) {
			while ((flag)&&(getDataFromDB()[i] != ';')) {
				str[j] = getDataFromDB()[i];
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
MyList<Student*> DataBase::getStudents()
{
	MyList<Student*> res;
	MyList<char*> students = getStrStudents();
	for (int i = 0; i < students.size(); i++) {
		res.push_back(new Student);
		char* strStud = students[i];
		char* studName = new char[64];
		char* studSurName = new char[64];
		char* studPatro = new char[64];
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
		while (strStud[j] != ':') {
			studSurName[k] = strStud[j];
			j++;
			k++;
		}
		studSurName[k] = '\0';
		k = 0;
		j++;
		res[i]->setStudentSurName(studSurName);
		while (strStud[j] != ':') {
			studPatro[k] = strStud[j];
			j++;
			k++;
		}
		studPatro[k] = '\0';
		k = 0;
		j++;
		res[i]->setStudentPatronymic(studPatro);
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
		char* resAllSession = new char[10240];
		while (strStud[j] != '\0') {
			resAllSession[k] = strStud[j];
			j++;
			k++;
		}
		resAllSession[k] = '\0';
		k = 0;
		j++;
		res[i]->setAllSession(resAllSession);
	}
	
	return res;
}
