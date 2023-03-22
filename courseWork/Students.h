#pragma once
#include "structures.h"
#include <iostream>
#include <vector>
#include <string>
class Student
{
private:
	char studentName[64];
	birthday studentBirthday;
	int admissionYear;
	char faculty[64];
	char department[64];
	char group[64];
	char recordBookId[64];
	char gender[64];
	vector<resSession> session;
public:
	Student();
	Student(const char _studentName[64], birthday _studentBirthday, int _admissionYear, const char _faculty[64], const char _department[64], const char _group[64], const char _recordBookId[64], const char _gender[64], vector<resSession> _session);
	void setStudentName(const char _studentName[64]);
	void setStudentBirthday(birthday _studentBirthday);
	void setAdmissionYear(int _admissionYear);
	void setFaculty(const char _faculty[64]);
	void setDepartment(const char _department[64]);
	void setGroup(const char _group[64]);
	void setRecordBookId(const char _recordBookId[64]);
	void setGender(const char _gender[64]);
	void setSession(vector<resSession> _session);

	char* getStudentName();
	birthday getStudentBirthday();
	int getAdmissionYear();
	char* getFaculty();
	char* getDepartment();
	char* getGroup();
	char* getRecordBookId();
	char* getGender();
	vector<resSession> getSession();
	char* getDataForDB();
	char* getResSession(int _sessionNum);
	char* getResAllSession();
};