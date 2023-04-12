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
	MyList<resSession> session;
public:
	Student();
	Student(const char _studentName[64], birthday _studentBirthday, int _admissionYear, const char _faculty[64], const char _department[64], const char _group[64], const char _recordBookId[64], const char _gender[64], MyList<resSession> _session);
	bool setStudentName(const char _studentName[64]);
	bool setStudentBirthday(birthday _studentBirthday);
	bool setAdmissionYear(int _admissionYear);
	bool setFaculty(const char _faculty[64]);
	bool setDepartment(const char _department[64]);
	bool setGroup(const char _group[64]);
	bool setRecordBookId(const char _recordBookId[64]);
	bool setGender(const char _gender[64]);
	bool setSession(MyList<resSession> _session);
	bool setAllSession(const char* _session);

	char* getStudentName();
	birthday getStudentBirthday();
	int getAdmissionYear();
	char* getFaculty();
	char* getDepartment();
	char* getGroup();
	char* getRecordBookId();
	char* getGender();
	MyList<resSession> getSession();
	char* getDataForDB();
	char* getResSession(int _sessionNum);
	char* getResAllSession();
};