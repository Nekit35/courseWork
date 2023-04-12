#pragma once
#include <iostream>
#include <vector>

#include "Students.h"
using namespace std;

Student::Student()
{
}

Student::Student(const char _studentName[64], birthday _studentBirthday, int _admissionYear, const char _faculty[64], const char _department[64], const char _group[64], const char _recordBookId[64], const char _gender[64], MyList<resSession> _session)
{
	int i = 0;
	while (_studentName[i] != '\0') {
		studentName[i] = _studentName[i];
		i++;
	}
	studentName[i] = '\0';
	if ((_studentBirthday.day < 32) && (_studentBirthday.day > 0) && (_studentBirthday.month > 0) && (_studentBirthday.month < 13) && (_studentBirthday.year > 1900) && (_studentBirthday.year < 2023))
		Student::studentBirthday = _studentBirthday;
	else Student::studentBirthday = { 1,1,2000 };
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
bool Student::setStudentName(const char _studentName[64])
{
	int i = 0;
	while (_studentName[i] != '\0') {
		studentName[i] = _studentName[i];
		i++;
	}
	studentName[i] = '\0';
	return 1;
}

bool Student::setStudentBirthday(birthday _studentBirthday)
{
	if ((_studentBirthday.day < 32) && (_studentBirthday.day > 0) && (_studentBirthday.month > 0) && (_studentBirthday.month < 13) && (_studentBirthday.year > 1900) && (_studentBirthday.year < 2023)) {
		Student::studentBirthday = _studentBirthday;
		return 1;
	}
	else return 0;
}
bool Student::setAdmissionYear(int _admissionYear)
{
	Student::admissionYear = _admissionYear;
	return 1;
}
bool Student::setFaculty(const char _faculty[64])
{
	int i = 0;
	while (_faculty[i] != '\0') {
		Student::faculty[i] = _faculty[i];
		i++;
	}
	
	faculty[i] = '\0';
	return 1;
}
bool Student::setDepartment(const char _department[64])
{
	int i = 0;
	while (_department[i] != '\0') {
		Student::department[i] = _department[i];
		i++;
	}
	department[i] = '\0';
	return 1;
}
bool Student::setGroup(const char _group[64])
{
	int i = 0;
	while (_group[i] != '\0') {
		Student::group[i] = _group[i];
		i++;
	}
	group[i] = '\0';
	return 1;
}
bool Student::setRecordBookId(const char _recordBookId[64])
{
	int i = 0;
	while (_recordBookId[i] != '\0') {
		Student::recordBookId[i] = _recordBookId[i];
		i++;
	}
	recordBookId[i] = '\0';
	return 1;
}
bool Student::setGender(const char _gender[64])
{
	int i = 0;
	while (_gender[i] != '\0') {
		Student::gender[i] = _gender[i];
		i++;
	}
	gender[i] = '\0';
	return 1;
}
bool Student::setSession(MyList<resSession> _session)
{
	Student::session = _session;
	return 1;
}
bool Student::setAllSession(const char* _session)
{
	MyList<resSession> res;
	int i = 0;
	while (_session[i] != '\0') {
		resSession session1;
		char sesNum[1];
		sesNum[0] = _session[i];
		session1.sessionNumber = atoi(sesNum);
		i += 2;
		char subCount[3];
		subCount[0] = _session[i];
		i++;
		if (_session[i] != ':') {
			subCount[1] = _session[i];
			i++;
		}
		int subjCount = atoi(subCount);
		
		i++;
		for (int j = 0; j < subjCount; j++) {
			Subject subject;
			int k = 0;
			char* sub = new char[64];
			while (_session[i] != ':') {
				sub[k] = _session[i];
				i++;
				k++;
			}
			sub[k] = '\0';
			i++;
			subject.subj = sub;
			char grade1[1];
			grade1[0] = _session[i];
			i += 2;
			int grade = atoi(grade1);
			subject.grade = grade;
			session1.subj.push_back(subject);
			k = 0;
		}
		res.push_back(session1);
		
	}
	session = res;
	return 1;
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
MyList<resSession> Student::getSession()
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
	for (int i = 0; i < session.size(); i++) {
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
