#include <iostream>
#include "structures.h"
#include <fstream>
#include "Students.h"
#include "DataBase.h"
#include "Interface.h"
#include "MyList.h"
#include "Filter.h"
#include "CryptoTools.h"
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");

	DataBase db1;
	string path= "db.bin";
	//db1.createDataBase();

	Subject subj1 = { "matan", 2 };
	Subject subj2 = { "phys", 5 };
	Subject subj3 = { "math", 3 };
	Subject subj4 = { "rus", 4 };
	resSession res1 = {1,{}};
	res1.subj.push_back(subj3);
	res1.subj.push_back(subj3);
	resSession res2 = {2,{}};
	res2.subj.push_back(subj3);
	res2.subj.push_back(subj3);
	resSession res3 = { 3,{} };
	res3.subj.push_back(subj2);
	res3.subj.push_back(subj2);
	resSession res4 = { 4,{} };
	res4.subj.push_back(subj2);
	res4.subj.push_back(subj2);
	resSession res5 = { 5,{} };
	res5.subj.push_back(subj2);
	res5.subj.push_back(subj2);
	resSession res6 = { 6,{} };
	res6.subj.push_back(subj2);
	res6.subj.push_back(subj2);
	resSession res7 = { 7,{} };
	res7.subj.push_back(subj2);
	res7.subj.push_back(subj2);
	resSession res8 = { 8,{} };
	res8.subj.push_back(subj2);
	res8.subj.push_back(subj2);
	resSession res9 = { 9,{} };
	res9.subj.push_back(subj2);
	res9.subj.push_back(subj2);
	MyList<resSession> reaall;
	reaall.push_back(res1);
	reaall.push_back(res2);
	reaall.push_back(res3);
	reaall.push_back(res4);
	reaall.push_back(res5);
	reaall.push_back(res6);
	reaall.push_back(res7);
	reaall.push_back(res8);
	reaall.push_back(res9);
	MyList<resSession> re;
	re.push_back(res1);
	re.push_back(res2);
	re.push_back(res3);
	re.push_back(res4);
	Student s1("Алексей","Русаков","Михайлович", { 2, 1, 1980 }, 2000, "ИИТ", "Кб-1", "ИТИП-01-00", "22Б0803", "0", reaall);
	Student s2("Андрей", "Андреевич", "Андреев", { 5, 1, 1980 }, 2006, "ИКБ", "Кб-2", "ИТТТ-01-06", "123564", "0", re);
	Student s3("Алексей", "Алексеевич", "Алексеев", { 12, 12, 1991 }, 2008, "Иту", "Кб-1", "ИТТТ-01-08", "123554", "0", reaall);

	//db1.addToData(s1.getDataForDB());
	//db1.addToData(s2.getDataForDB());
	//db1.addToData(s3.getDataForDB());
	//MyList<Student*> lst = db1.getStudents();
	//Filter filter(db1.getStudents());


	//char* m = db1.getStudents()[1]->getStudentName();
	//char* n = db1.getStudents()[0]->getStudentName();
	//char* r = db1.getStudents()[2]->getStudentName();
	//MyList<Student*> frr = filter.filter3();
	//cout<<s1.getResAllSession()<<endl;
	//s1.setAllSession(s2.getResAllSession());
	//cout << s1.getResAllSession();

	
	Interface interface;


	return 0;
}
	
