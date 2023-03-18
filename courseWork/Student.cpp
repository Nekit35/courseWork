#pragma once
#include <iostream>
#include <vector>

#include "Students.h"
using namespace std;
Student::Student(){
}
void Student::setStudentName(const char _studentName[64])
{
	int i = 0;
	while (_studentName[i] != '\0') {
		studentName[i] = _studentName[i];
		i++;
	}
	studentName[i] = '\0';
	
}

void Student::setStudentBirthday(birthday _studentBirthday)
{
	Student::studentBirthday = _studentBirthday;
	
}
void Student::setAdmissionYear(int _admissionYear)
{
	Student::admissionYear = _admissionYear;
	
}
void Student::setFaculty(const char _faculty[32])
{
	int i = 0;
	while (_faculty[i] != '\0') {
		Student::faculty[i] = _faculty[i];
		i++;
	}
	
	faculty[i] = '\0';
	
}
void Student::setDepartment(const char _department[32])
{
	int i = 0;
	while (_department[i] != '\0') {
		Student::department[i] = _department[i];
		i++;
	}
	department[i] = '\0';
}
void Student::setGroup(const char _group[16])
{
	int i = 0;
	while (_group[i] != '\0') {
		Student::group[i] = _group[i];
		i++;
	}
	group[i] = '\0';
}
void Student::setRecordBookId(int _recordBookId)
{
	Student::recordBookId = _recordBookId;
	
}
void Student::setGender(const char _gender[3])
{

	int i = 0;
	while (_gender[i] != '\0') {
		Student::gender[i] = _gender[i];
		i++;
	}
	gender[i] = '\0';
}
void Student::setSession(resAllSession _session)
{
	Student::session = _session;
}


	
birthday Student::getStudentBirthday()
{
	return Student::studentBirthday;
}
int Student::getAdmissionYear()
{
	return Student::admissionYear;
}



int Student::getRecordBookId()
{
	return Student::recordBookId;
}
resAllSession Student::getSession()
{
	return Student::session;
}
