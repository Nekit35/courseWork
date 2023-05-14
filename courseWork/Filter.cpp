#include "Filter.h"
MyList<Student*> Filter::filter3()
{
	MyList<Student*> res;
	for (int k = 0; k < students.size(); k++) {
		MyList<resSession> studentsResSession = students[k]->getSession();
		int countOfSessions = studentsResSession.size();
		int countOfThree = 0;
		int countOfGrades = 0;
		for (int i = 0; i < countOfSessions; i++) {
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if (studentsResSession[i].subj[j].grade == 3) countOfThree++;
				countOfGrades++;
			}
		}
		if ((float)countOfThree / countOfGrades <= 0.25) res.push_back(students[k]);
	}
	return res;
}
MyList<Student*> Filter::filter34()
{
	MyList<Student*> res;
	for (int k = 0; k < students.size(); k++) {
		MyList<resSession> studentsResSession = students[k]->getSession();
		int countOfSessions = studentsResSession.size();
		int countOfThreeAndFour = 0;
		int countOfGrades = 0;
		for (int i = 0; i < countOfSessions; i++) {
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if ((studentsResSession[i].subj[j].grade == 3)|| (studentsResSession[i].subj[j].grade == 4)) countOfThreeAndFour++;
				countOfGrades++;
			}
		}
		if ((float)countOfThreeAndFour / countOfGrades <= 0.25) res.push_back(students[k]);
	}
	return res;
}
MyList<Student*> Filter::filter5()
{
	MyList<Student*> res;
	for (int k = 0; k < students.size(); k++) {
		MyList<resSession> studentsResSession = students[k]->getSession();
		int countOfSessions = studentsResSession.size();
		int countOfFive = 0;
		int countOfGrades = 0;
		for (int i = 0; i < countOfSessions; i++) {
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if (studentsResSession[i].subj[j].grade == 4) countOfFive++;
				countOfGrades++;
			}
		}
		if ((float)countOfFive / countOfGrades <= 0.25) res.push_back(students[k]);
	}
	return res;
}
MyList<Student*> Filter::filter35()
{
	MyList<Student*> res;
	for (int k = 0; k < students.size(); k++) {
		MyList<resSession> studentsResSession = students[k]->getSession();
		int countOfSessions = studentsResSession.size();
		int countOfThreeAndFive = 0;
		int countOfGrades = 0;
		for (int i = 0; i < countOfSessions; i++) {
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if ((studentsResSession[i].subj[j].grade == 3) || (studentsResSession[i].subj[j].grade == 5)) countOfThreeAndFive++;
				countOfGrades++;
			}
		}
		if ((float)countOfThreeAndFive / countOfGrades <= 0.25) res.push_back(students[k]);
	}
	return res;
}
MyList<Student*> Filter::filter45()
{
	MyList<Student*> res;
	for (int k = 0; k < students.size(); k++) {
		MyList<resSession> studentsResSession = students[k]->getSession();
		int countOfSessions = studentsResSession.size();
		int countOfFourAndFive = 0;
		int countOfGrades = 0;
		for (int i = 0; i < countOfSessions; i++) {
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if ((studentsResSession[i].subj[j].grade == 4) || (studentsResSession[i].subj[j].grade == 5)) countOfFourAndFive++;
				countOfGrades++;
			}
		}
		if ((float)countOfFourAndFive / countOfGrades <= 0.25) res.push_back(students[k]);
	}
	return res;
	
}