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
};

