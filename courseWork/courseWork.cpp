

#include <iostream>
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
class Student
{
	string studentName;
	birthday studentBirthday;
	int admissionYear;
	string faculty;
	string department;
	string group;
	int recordBookId;
	string gender;
	resAllSession session;
public:
	Student(string _studentName, birthday _studentBirthday, int _admissionYear, string _faculty, string _department, string _group, int _recordBookId, string _gender, resAllSession _session)
	{
		studentName = _studentName;
		studentBirthday = _studentBirthday;
		admissionYear = _admissionYear;
		faculty = _faculty;
		department = _department;
		group = _group;
		recordBookId = _recordBookId;
		gender = _gender;
		session = _session;
	}
};
int main()
{
	str name;
	name = "Алексей Русаков";
	//resAllSession res;
	//Subject subj1 = { "matan", 2 };
	//Subject subj2 = { "phys", 5 };
	//resSession res1 = { 1, subj1, subj2 };
	//Student s1("Алексей Русаков", { 12, 12, 1980 }, 2000, "ИИТ", "Кб-1", "ИТИП-01-00", "1234", "m", );
}
	
