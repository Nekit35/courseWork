#pragma once
#include "MyList.h";
#include "Students.h"
class Filter
{
	MyList<Student*> students;
public:
	Filter(MyList<Student*> _students) { students = _students;};
	MyList<Student*> filter3();
	MyList<Student*> filter34();
	MyList<Student*> filter5();
	MyList<Student*> filter35();
	MyList<Student*> filter45();


};

