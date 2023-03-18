#pragma once
#include <iostream>
#include <vector>

#include "Students.h"
using namespace std;
Student::Student(const char _studentName[64], birthday _studentBirthday, int _admissionYear, const char _faculty[64], const char _department[64], const char _group[64], int _recordBookId, const char _gender[64], resAllSession _session)
{
	int i = 0;
	while (_studentName[i] != '\0') {
		studentName[i] = _studentName[i];
		i++;
	}
	studentName[i] = '\0';
	Student::studentBirthday = _studentBirthday;
	Student::admissionYear = _admissionYear;
	i = 0;
	while (_faculty[i] != '\0') {
		Student::faculty[i] = _faculty[i];
		i++;
	}

	faculty[i] = '\0';
	i = 0;
	while (_department[i] != '\0') {
		Student::department[i] = _department[i];
		i++;
	}
	department[i] = '\0';
	i = 0;
	while (_group[i] != '\0') {
		Student::group[i] = _group[i];
		i++;
	}
	group[i] = '\0';
	Student::recordBookId = _recordBookId;
	i = 0;
	while (_gender[i] != '\0') {
		Student::gender[i] = _gender[i];
		i++;
	}
	gender[i] = '\0';
	Student::session = _session;
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
void Student::setFaculty(const char _faculty[64])
{
	int i = 0;
	while (_faculty[i] != '\0') {
		Student::faculty[i] = _faculty[i];
		i++;
	}
	
	faculty[i] = '\0';
	
}
void Student::setDepartment(const char _department[64])
{
	int i = 0;
	while (_department[i] != '\0') {
		Student::department[i] = _department[i];
		i++;
	}
	department[i] = '\0';
}
void Student::setGroup(const char _group[64])
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
void Student::setGender(const char _gender[64])
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

char* Student::getStudentName()
{
	char* res = new char[64];
	int i = 0;
	while (studentName[i] != '\0') {
		res[i] = studentName[i];
		i++;
	}
	res[i] = '\0';
	return res;
}
	
birthday Student::getStudentBirthday()
{
	return Student::studentBirthday;
}
int Student::getAdmissionYear()
{
	return Student::admissionYear;
}
char* Student::getFaculty()
{
	char* res = new char[64];
	int i = 0;
	while (faculty[i] != '\0') {
		res[i] = faculty[i];
		i++;
	}
	res[i] = '\0';
	return res;
}
char* Student::getDepartment()
{
	char* res = new char[64];
	int i = 0;
	while (department[i] != '\0') {
		res[i] = department[i];
		i++;
	}
	res[i] = '\0';
	return res;
}
char* Student::getGroup()
{
	char* res = new char[64];
	int i = 0;
	while (group[i] != '\0') {
		res[i] = group[i];
		i++;
	}
	res[i] = '\0';
	return res;
}
int Student::getRecordBookId()
{
	return Student::recordBookId;
}
char* Student::getGender()
{
	char* res = new char[64];
	int i = 0;
	while (gender[i] != '\0') {
		res[i] = gender[i];
		i++;
	}
	res[i] = '\0';
	return res;
}
resAllSession Student::getSession()
{
	return Student::session;
}
