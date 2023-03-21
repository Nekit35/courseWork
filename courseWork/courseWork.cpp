#include <iostream>
#include "structures.h"
#include <fstream>
#include "Students.h"
#include "DataBase.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");

	DataBase db1;
	string path= "";
	db1.createDataBase("");
	
	//res1 = { {1, {"phys", 1}}  };

	//name = "Алексей Русаков";
	//resAllSession res;
	Subject subj1 = { "matan", 2 };
	Subject subj2 = { "phys", 5 };
	Subject subj3 = { "math", 3 };
	Subject subj4 = { "rus", 4 };
	resSession res1 = { 1,{subj1, subj2, subj3, subj4,subj1, subj2, subj3, subj4, subj1, subj2 } };
	resSession res2 = { 2,{subj3, subj4} };
	resSession res3 = { 1,{subj1, subj2} };
	resSession res4 = { 1,{subj3, subj4} };
	resSession res5 = { 1,{subj1, subj2} };
	resSession res6 = { 1,{subj3, subj4} };
	resSession res7 = { 1,{subj1, subj2} };
	resSession res8 = { 1,{subj3, subj4} };
	resSession res9 = { 1,{subj1, subj2} };
	vector<resSession> reaall = {{res1, res2, res3,res4,res5,res6,res7,res8,res9}};
	Student s1("Алексей Русаков", { 2, 1, 1980 }, 2000, "ИИТ", "Кб-1", "ИТИП-01-00", 123456, "m", reaall);
	Student s2("Андрей Андреевич Андреев", { 5, 1, 1980 }, 2006, "ИКБ", "Кб-2", "ИТТТ-01-06", 123564, "m", reaall);
	Student s3("Алексей Алексеевич Алексеев", { 12, 12, 1991 }, 2008, "Иту", "Кб-1", "ИТТТ-01-08", 123554, "m", reaall);
	//db1.setPathToFile(path);
	db1.addToData(s1.getDataForDB());
	db1.addToData(s2.getDataForDB());
	db1.addToData(s3.getDataForDB());
	cout << s1.getDataForDB();
	
	return 0;
}
	
