#pragma once
#include <iostream>
#include "DataBase.h"
#include <cstdio>
#include <cstdlib>
#include <stdio.h>
#include <limits>
#include <conio.h>
#include <ctype.h>
#include<iomanip>
#include "MyList.h"
#include "Students.h"
#include "structures.h"
#include "Filter.h"

#define VK_BKSPC   0x08
#define VK_RETURN  0x0D
#define VK_SPACE   0x20

using namespace std;
class Interface
{
	MyList<Student*> students;
	DataBase db;
	char* inputPassword(char* buffer);
	void printLine();
	void printHead();
	int studentParser(char* recordBookId);
	void printHeadForOneStudent();
	void printLineForOneStudent();
	void printSessionLine();
	void printSessionHead();
	void printSubjectLine();
	bool sessionParser(int index, int parsIndex);
	void editGradeSubject(int index);
	void editGrade(int index, int sessionNumber, int choiceNum);
	void editSubject(int index, int sessionNumber, int choiceNum);
	void deleteSession(int index);
	void deleteSubject(int index);
	void addSession(int index);
	void addSubject(int index);
	int checkSession(int index, int sessionNum);
	void printFilteredStudents(MyList<Student*> filteredStudents);
	void printFilteredLine();
public:
	Interface();
	void StartPage();
	void interfaceChoiceUseDB();
	void mainPage();
	void addStudent();
	void editStudent();
	void printAllStudent();
	void deleteStudent();
	void editPage(int index);
	void editRecordBookId(int index);
	void editGender(int index);
	void editBirthaday(int index);
	void editSession(int index);
	void doIndidualTask();
	void saveAndCrypt();
};

