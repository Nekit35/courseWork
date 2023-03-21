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
	int recordBookId;
	char gender[64];
	vector<resSession> session;
public:
	Student(const char _studentName[64], birthday _studentBirthday, int _admissionYear, const char _faculty[64], const char _department[64], const char _group[64], int _recordBookId, const char _gender[64], vector<resSession> _session);
	void setStudentName(const char _studentName[64]);
	void setStudentBirthday(birthday _studentBirthday);
	void setAdmissionYear(int _admissionYear);
	void setFaculty(const char _faculty[64]);
	void setDepartment(const char _department[64]);
	void setGroup(const char _group[64]);
	void setRecordBookId(int _recordBookId);
	void setGender(const char _gender[64]);
	void setSession(vector<resSession> _session);

	char* getStudentName();
	birthday getStudentBirthday();
	int getAdmissionYear();
	char* getFaculty();
	char* getDepartment();
	char* getGroup();
	int getRecordBookId();
	char* getGender();
	vector<resSession> getSession();
	char* getDataForDB();
	char* getResSession(int _sessionNum);
	char* getResAllSession();
};