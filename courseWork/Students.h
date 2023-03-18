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
	char faculty[32];
	char department[32];
	char group[16];
	int recordBookId;
	char gender[3];
	resAllSession session;
public:
	Student();
	void setStudentName(const char _studentName[64]);
	void setStudentBirthday(birthday _studentBirthday);
	void setAdmissionYear(int _admissionYear);
	void setFaculty(const char _faculty[32]);
	void setDepartment(const char _department[32]);
	void setGroup(const char _group[16]);
	void setRecordBookId(int _recordBookId);
	void setGender(const char _gender[3]);
	void setSession(resAllSession _session);

	char* getStudentName();
	birthday getStudentBirthday();
	int getAdmissionYear();
	char* getFaculty();
	char* getDepartment();
	char* getGroup();
	int getRecordBookId();
	char* getGender();
	resAllSession getSession();
	char* getDataForDB();
};