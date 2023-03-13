#pragma once
#include <vector>
#include <string>
using namespace std;
struct str
{
	vector<char> name;
};
struct birthday
{
	unsigned int day;
	unsigned int month;
	unsigned int year;
};
struct Subject
{
	string subj;
	int grade;
};
struct resSession
{
	int sessionNumber;
	vector<Subject> subj;
};
struct resAllSession
{
	vector<resSession> result;
};