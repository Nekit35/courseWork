#pragma once
#include <iostream>
#include <vector>

#include "Students.h"
using namespace std;

Student::Student()
{
}

Student::Student(const char _studentName[64], birthday _studentBirthday, int _admissionYear, const char _faculty[64], const char _department[64], const char _group[64], const char _recordBookId[64], const char _gender[64], vector<resSession> _session)
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
	group[i] = '\0'; i = 0;
	while (_recordBookId[i] != '\0') {
		Student::recordBookId[i] = _recordBookId[i];
		i++;
	}
	group[i] = '\0';

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
void Student::setRecordBookId(const char _recordBookId[64])
{
	int i = 0;
	while (_recordBookId[i] != '\0') {
		Student::recordBookId[i] = _recordBookId[i];
		i++;
	}
	recordBookId[i] = '\0';
	
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
void Student::setSession(vector<resSession> _session)
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
char* Student::getRecordBookId()
{
	char* res = new char[64];
	int i = 0;
	while (recordBookId[i] != '\0') {
		res[i] = recordBookId[i];
		i++;
	}
	res[i] = '\0';
	return res;
	return res;
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
vector<resSession> Student::getSession()
{
	return Student::session;
}


char* Student::getResSession(int _sessionNum)
{
	char* res = new char[1024];
	int i = 0;
	int sessionInVect = _sessionNum;
	resSession sess = session[sessionInVect];
	int c = session.size();
	int countSub = sess.subj.size();
	
	int count = sess.subj.size();
	char countSubj[16];
	if (count < 10) {
		sprintf_s(countSubj, "%d", count);
		res[i] = countSubj[0];
	}
	else {
		sprintf_s(countSubj, "%d", count);
		res[i] = countSubj[0];
		i++;
		res[i] = countSubj[1];
	}
	i++;
	res[i] = ':';
	i++;
	for (int j = 0; j < count; j++) {
		int k = 0;
		Subject sub = sess.subj[j];
		while (sub.subj[k] != '\0') {
			res[i] = sub.subj[k];
			k++;
			i++;
		}
		char grade[5];
		res[i] = ':';
		i++;
		sprintf_s(grade, "%d", sub.grade);
		res[i] = grade[0];
		i++;
		k = 0;
		res[i] = ':';
		i++;
		
	}
	res[i] = '\0';
	return res;
}

char* Student::getResAllSession()
{
	char* result = new char[2048];
	int k = 0;
	for (int i = 0; i < 9; i++) {
		char sesNum[3];
		sprintf_s(sesNum, "%d", i + 1);
		result[k] = sesNum[0];
		k++;
		result[k] = ':';
		k++;
		int j = 0;
		char* resSession = getResSession(i);
		while (resSession[j]!='\0') {
			result[k] = resSession[j];
			j++;
			k++;
		}
		
	}
	result[k] = '\0';
	return result;
}

char* Student::getDataForDB()
{
	char* res = new char[1024];
	res[0] = ';';
	int i = 1;
	int j = 0;
	while (studentName[j] != '\0') {
		res[i] = studentName[j];
		i++;
		j++;
	}
	j = 0;
	res[i] = ':';
	i++;
	char* date = new char[10];
	while (studentBirthday.getDate()[j] != '\0') {
		date[j] = studentBirthday.getDate()[j];
		j++;
	}
	date[j] = '\0';
	j = 0;
	while (date[j] != '\0') {
		res[i] = date[j];
		i++;
		j++;
	}
	j = 0;
	res[i] = ':';
	i++;
	char str[6];
	sprintf_s(str, "%d", admissionYear);
	for (; j < 4; j++, i++) {
		res[i] = str[j];
	}
	j = 0;
	res[i] = ':';
	i++;
	while (faculty[j] != '\0') {
		res[i] = faculty[j];
		i++;
		j++;
	}
	j = 0;
	res[i] = ':';
	i++;
	while (department[j] != '\0') {
		res[i] = department[j];
		i++;
		j++;
	}
	j = 0;
	res[i] = ':';
	i++;
	while (group[j] != '\0') {
		res[i] = group[j];
		i++;
		j++;
	}
	j = 0;
	res[i] = ':';
	i++;
	while (recordBookId[j] != '\0'){
		res[i] = recordBookId[j];
		j++;
		i++;
	}
	j = 0;
	res[i] = ':';
	i++;
	while (gender[j] != '\0') {
		res[i] = gender[j];
		i++;
		j++;
	}
	j = 0;
	res[i] = ':';
	i++;
	char* resSession = getResAllSession();
	while (resSession[j] != '\0') {
		res[i] = resSession[j];
		i++;
		j++;
	}
	j = 0;
	i--;
	res[i] = ';';
	i++;
	res[i] = '\0';
	return res;
}
