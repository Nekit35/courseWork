#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "structures.h"
#include "structures.h"
using namespace std;
class Student
{
private:
	string studentName;
	birthday studentBirthday;
	int admissionYear;
	string faculty;
	string department;
	string group;
	int recordBookId;
	string gender;
	resAllSession session;
public:
	Student(string _studentName, birthday _studentBirthday, int _admissionYear, string _faculty, string _department, string _group, int _recordBookId, string _gender, resAllSession _session)
	{
		studentName = _studentName;
		studentBirthday = _studentBirthday;
		admissionYear = _admissionYear;
		faculty = _faculty;
		department = _department;
		group = _group;
		recordBookId = _recordBookId;
		gender = _gender;
		session = _session;
	}
	void setStudentName(string _name)
	{
		studentName = _name;
	}
	void setStudentBirthday(birthday _studentBirthday)
	{
		studentBirthday = _studentBirthday;
	}
	void setAdmissionYear(int _admissionYear)
	{
		admissionYear = _admissionYear;
	}
	void setFaculty(string _faculty)
	{
		faculty = _faculty;
	}
	void setDepartment(string _department)
	{
		department = _department;
	}
	void setGroup(string _group)
	{
		group = _group;
	}
	void setRecordBookId(int _recordBookId)
	{
		recordBookId = _recordBookId;
	}
	void setGender(string _gender)
	{
		gender = _gender;
	}
	void setSession(resAllSession _session)
	{
		session = _session;
	}


	string getStudentName()
	{
		return studentName;
	}
	birthday getStudentBirthday()
	{
		return studentBirthday;
	}
	int getAdmissionYear()
	{
		return admissionYear;
	}
	string getFaculty()
	{
		return faculty;
	}
	string getDepartment()
	{
		return department;
	}
	string getGroup()
	{
		return group;
	}
	int getRecordBookId()
	{
		return recordBookId;
	}
	string getGender()
	{
		return gender;
	}
	resAllSession getSession()
	{
		return session;
	}
};
