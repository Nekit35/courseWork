

#include <iostream>
#include <vector>
#include <string>
#include "structures.h"
#include "Student.cpp"
using namespace std;



int main()
{
	string kek = "string";
	const char* keks = kek.c_str();
	//res1 = { {1, {"phys", 1}}  };

	//name = "Алексей Русаков";
	//resAllSession res;
	Subject subj1 = { "matan", 2 };
	Subject subj2 = { "phys", 5 };
	Subject subj3 = { "math", 3 };
	Subject subj4 = { "rus", 4 };
	resSession res1 = { 1,{subj1, subj2} };
	resSession res2 = { 2,{subj3, subj4} };
	resAllSession reaall = {{res1, res2}};
	Student s1("Алексей Русаков", { 12, 12, 1980 }, 2000, "ИИТ", "Кб-1", "ИТИП-01-00", 1234, "m", reaall);
	s1.getName();
	return 0;
}
	
