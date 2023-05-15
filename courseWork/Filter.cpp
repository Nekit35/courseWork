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
			for (int j = 0; j < studentsResSession[i].subj.size(); j++) {
				if (studentsResSession[i].subj[j].grade != -1 || studentsResSession[i].subj[j].grade != 0 || studentsResSession[i].subj[j].grade != 1) {
					countOfGrades++;
				}
			}
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if (studentsResSession[i].subj[j].grade == 3) countOfThree++;
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
			for (int j = 0; j < studentsResSession[i].subj.size(); j++) {
				if (studentsResSession[i].subj[j].grade != -1 || studentsResSession[i].subj[j].grade != 0 || studentsResSession[i].subj[j].grade != 1) {
					countOfGrades++;
				}
			}
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if (studentsResSession[i].subj[j].grade == 5) countOfFive++;
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
			for (int j = 0; j < studentsResSession[i].subj.size(); j++) {
				if (studentsResSession[i].subj[j].grade != -1 || studentsResSession[i].subj[j].grade != 0 || studentsResSession[i].subj[j].grade != 1) {
					countOfGrades++;
				}
			}
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if ((studentsResSession[i].subj[j].grade == 3) || (studentsResSession[i].subj[j].grade == 5)) countOfThreeAndFive++;
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
			for (int j = 0; j < studentsResSession[i].subj.size(); j++) {
				if (studentsResSession[i].subj[j].grade != -1 || studentsResSession[i].subj[j].grade != 0 || studentsResSession[i].subj[j].grade != 1) {
					countOfGrades++;
				}
			}
			int countOfSubject = studentsResSession[i].subj.size();
			for (int j = 0; j < countOfSubject; j++) {
				if ((studentsResSession[i].subj[j].grade == 4) || (studentsResSession[i].subj[j].grade == 5)) countOfFourAndFive++;
			}
		}
		if ((float)countOfFourAndFive / countOfGrades <= 0.25) res.push_back(students[k]);
	}
	return res;
	
}