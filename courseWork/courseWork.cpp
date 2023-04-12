#include <iostream>
#include "structures.h"
#include <fstream>
#include "Students.h"
#include "DataBase.h"
#include"Encryption.h"
#include "MyList.h"
using namespace std;



int main()
{
	setlocale(LC_ALL, "Russian");

	DataBase db1;
	string path= "C:\\Users\\mrzei\\source\\repos\\courseWork\\courseWork\\db.bin";
	db1.createDataBase(path);
	
	//res1 = { {1, {"phys", 1}}  };

	//name = "Алексей Русаков";
	//resAllSession res;
	Subject subj1 = { "matan", 2 };
	Subject subj2 = { "phys", 5 };
	Subject subj3 = { "math", 3 };
	Subject subj4 = { "rus", 4 };
	/*resSession res1 = {1,{}};
	res1.subj.push_back(subj1);
	res1.subj.push_back(subj2);
	resSession res2 = {2,{}};
	res2.subj.push_back(subj3);
	res2.subj.push_back(subj4);
	resSession res3 = { 3,{} };
	res3.subj.push_back(subj1);
	res3.subj.push_back(subj2);
	resSession res4 = { 4,{} };
	res4.subj.push_back(subj3);
	res4.subj.push_back(subj4);
	resSession res5 = { 5,{} };
	res5.subj.push_back(subj1);
	res5.subj.push_back(subj2);
	resSession res6 = { 6,{} };
	res6.subj.push_back(subj3);
	res6.subj.push_back(subj4);
	resSession res7 = { 7,{} };
	res7.subj.push_back(subj1);
	res7.subj.push_back(subj2);
	resSession res8 = { 8,{} };
	res8.subj.push_back(subj3);
	res8.subj.push_back(subj4);
	resSession res9 = { 9,{} };
	res9.subj.push_back(subj1);
	res9.subj.push_back(subj2);
	*/

	
	/*/resSession res1 = {1,{subj1, subj2}};
	resSession res2 = { 2,{subj3, subj4} };
	resSession res3 = { 1,{subj1, subj2} };
	resSession res4 = { 1,{subj3, subj4} };
	resSession res5 = { 1,{subj1, subj2} };
	resSession res6 = { 1,{subj3, subj4} };
	resSession res7 = { 1,{subj1, subj2} };
	resSession res8 = { 1,{subj3, subj4} };
	resSession res9 = { 1,{subj1, subj2} };
	*/
	//MyList<resSession> reaall = {{res1, res2, res3,res4,res5,res6,res7,res8,res9}};
	//MyList<resSession> re = { {res1, res2, res3,res4} };
	//Student s1("Алексей Русаков", { 2, 1, 1980 }, 2000, "ИИТ", "Кб-1", "ИТИП-01-00", "123456", "m", reaall);
	//Student s2("Андрей Андреевич Андреев", { 5, 1, 1980 }, 2006, "ИКБ", "Кб-2", "ИТТТ-01-06", "123564", "m", re);
	//Student s3("Алексей Алексеевич Алексеев", { 12, 12, 1991 }, 2008, "Иту", "Кб-1", "ИТТТ-01-08", "123554", "m", reaall);
	//db1.setPathToFile(path);
	vector<char*>res;
	//Encryption encr;
	//db1.addToData(s1.getDataForDB());
	//db1.addToData(s2.getDataForDB());
	//db1.addToData(s3.getDataForDB());
	//db1.getStudents();
	char name[] = "holera";

	//cout<<s1.getResAllSession()<<endl;
	//s1.setAllSession(s2.getResAllSession());
	//cout << s1.getResAllSession();

	/*MyList<Student> list;
	list.push_back(s1);
	list.push_back(s2);
	list.push_back(s3);
	list[1];

	MyList<Subject> lel;
	lel.push_back(subj1);
	lel.push_back(subj2);
	
	MyList<int> kek;
	kek.push_back(12);
	kek.push_back(13);
	kek.push_back(14);
	
	 list[0];
	 list[1];
	 list[2];
	 */
	return 0;
}
	
