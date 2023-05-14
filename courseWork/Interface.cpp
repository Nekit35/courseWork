#include "Interface.h"
Interface::Interface()
{
	StartPage();
}

void Interface::StartPage()
{

	cout << "�������� ��������:" << endl
		<< "1. ������� ���� ������" << endl
		<< "2. ������������ ������������ ���� ������" << endl;
	cin.clear();
	char choice;
	cin >> choice;
	if (choice == '1') {
		db.createDataBase();
	}
	if (choice == '2') {
		cin.clear();
		interfaceChoiceUseDB();
	}
	else StartPage();
	mainPage();
}

void Interface::interfaceChoiceUseDB()
{
	string nameOfDB;
	cout << "������� �������� ������������ ���� ������ (������: db.enc):" << endl;
	cin >> nameOfDB;
	cin.clear();
	std::cin.ignore(32767, '\n');
	db.setPathToDB(nameOfDB);
	cout << "������� ������: ";
	char password[128];
	/*inputPassword(password);
	CryptoTools crypt(db.getPathToDB());
	crypt.decrypt(password);*/
	db.setPathToDB("db.bin");
	students = db.getStudents();
}

char* Interface::inputPassword(char* buffer)
{
	char* ptr = buffer;
	unsigned char symbol;

	do
	{
		symbol = (unsigned char)_getch();

		if (symbol == 0x08 && ptr > buffer)
		{
			*--ptr = 0;
			_putch(VK_BKSPC);
			_putch(VK_SPACE);
			_putch(VK_BKSPC);
			continue;
		}

		if (!symbol)
		{
			_getch();
			continue;
		}

		if (symbol > VK_SPACE - 1)
		{
			*ptr++ = symbol;
			_putch('*');
		}
	} while (symbol != VK_RETURN);

	*ptr = 0; // ����� ������
	return buffer;
}
void Interface::mainPage()
{
	cout << "�������� ��������:" << endl
		<< "1. ������� ������ ���� ���������" << endl           //+
		<< "2. �������� ��������" << endl                       //+
		<< "3. ������������� ��������" << endl                  //-
		<< "4. ������� ��������" << endl                        //+
		<< "5. �������������� �������" << endl                  //-
		<< "6. ��������� � ����������� ���� ������" << endl;    //-
	char choice;
	cin >> choice;
	cin.clear();
	std::cin.ignore(32767, '\n');
	switch (choice)
	{
	case '1':
		printAllStudent();
		_getch();
		system("cls");
		mainPage();
		break;
	case '2':
		addStudent();
		break;
	case '3':
		editStudent();
		break;
	case '4':
		deleteStudent();
		break;
	case '5':
		break;
	case '6':
		break;
	default:
		mainPage();
		break;
	}
}

void Interface::addStudent()
{
	system("chcp 1251");
	system("cls");
	Student* newStudent = new Student;
	while (true) 
	{
		cout <<"������� ��� ��������: ";
		char name[64];
		cin >> name;
		if (newStudent->setStudentName(name) == 1)
		{
			newStudent->setStudentName(name);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������";
	}
	system("cls");
	while (true)
	{
		cout <<"������� ������� ��������: ";
		char surname[64];
		cin >> surname;
		if (newStudent->setStudentSurName(surname) == 1)
		{
			newStudent->setStudentSurName(surname);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������" << endl;
	}
	system("cls");
	while (true)
	{
		cout <<  "������� �������� ��������(���� ����): ";
		char patronymic[64];
		cin >> patronymic;
		if (newStudent->setStudentPatronymic(patronymic) == 1)
		{
			newStudent->setStudentPatronymic(patronymic);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������" << endl;
	}
	system("cls");
	birthday birth;
	while (!birth.checkDate())
	{	
		cout << "������� ���� ��������: ";
		int day;
		cin >> day;
		cin.clear();
		std::cin.ignore(32767, '\n');
		birth.day = day;
		cout << endl << "������� ����� ��������: ";
		int month;
		cin >> month;
		cin.clear();
		std::cin.ignore(32767, '\n');
		birth.month = month;
		cout << endl << "������� ��� ��������: ";
		int year;
		cin >> year;
		cin.clear();
		std::cin.ignore(32767, '\n');
		birth.year = year;
		if (birth.checkDate()) {
			newStudent->setStudentBirthday(birth);
			break;
		}
		else cout << endl <<"��������� ������, ������� ���������� ������" << endl;
		cin.clear();
	}
	system("cls");
	while (true) {
		cout  << "������� ��� �����������: ";
		int admissionYear;
		cin >> admissionYear;
		cin.clear();
		std::cin.ignore(32767, '\n');
		if ((admissionYear > 2019) && (admissionYear < 2023))
		{
			newStudent->setAdmissionYear(admissionYear);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������" << endl;
	}
	system("cls");
	while (true)
	{
		cout  << "������� ��������� ��������: ";
		char faculty[64];
		cin >> faculty;
		if (newStudent->setFaculty(faculty))
		{
			newStudent->setFaculty(faculty);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������" << endl;
	}
	system("cls");
	while (true)
	{
		cout  << "������� ������� ��������: ";
		char department[64];
		cin >> department;
		if (newStudent->setDepartment(department))
		{
			newStudent->setDepartment(department);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������" << endl;
	}
	system("cls");
	while (true)
	{
		cout  << "������� ������ ��������: ";
		char group[64];
		cin >> group;
		if (newStudent->setGroup(group))
		{
			newStudent->setGroup(group);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������" << endl;
	}
	system("cls");
	while (true)
	{
		cout << "������� ����� �������� ������ ��������: ";
		char RecordBookId[64];
		cin >> RecordBookId;
		if (newStudent->setRecordBookId(RecordBookId))
		{
			newStudent->setRecordBookId(RecordBookId);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������" << endl;
	}
	system("cls");
	while (true)
	{
		cout  << "������� ��� �������� ��������(0 - �������, 1 - �������): ";
		char gender[64];
		cin >> gender;
		if (newStudent->setGender(gender))
		{
			newStudent->setGender(gender);
			break;
		}
		else cout << "��������� ������, ������� ���������� ������" << endl;
	}
	system("cls");
	MyList<resSession> resAllSession;
		for (int i = 1; i < 10; i++)
		{
			resSession session;
			session.sessionNumber = i;
			for (int j = 1; j < 11; j++) {
				Subject newSubject;
				cout << "������� " << j << "� ������� " << i << "� ������: ";
				char *subjectStr=new char[64];
				cin >> subjectStr;
				cin.clear();
				std::cin.ignore(32767, '\n');
				newSubject.subj = subjectStr;
				cout << "������� ������ �� " << newSubject.subj << "(���� �����, �� 0 - �������, 1 - �����, -1 - ������): ";
				int grade;
				do {
					cin >> grade;
					cin.clear();
					std::cin.ignore(32767, '\n');
				} while ((grade > 5) || (grade < -2));
				newSubject.grade = grade;
				session.sessionNumber = i;
				session.subj.push_back(newSubject);
				system("cls");
				cout << "���� ������ ��������� � ���� ������, ������� 1, �����, ������� 0: ";
				char choice;
				cin >> choice;
				if (choice == '1') break;
				system("cls");
			}
			resAllSession.push_back(session);
			system("cls");
			cout << "���� � �������� ������ ��� ������, ������� 1, �����, ������� 0: ";
			char choice;
			cin >> choice;
			if (choice == '1') break;
		}
	newStudent->setSession(resAllSession);
	students.push_back(newStudent);
	system("cls");
	mainPage();
}
void Interface::printLine()
{
	cout << "|-------|--------------|--------------------|--------------------|---|" << endl;
}

void Interface::printHead()
{
	cout << "|-------|--------------|--------------------|--------------------|---|" << endl
		 << "|���.���|     ���      |      �������       |      ��������      |���|" << endl
		 << "|-------|--------------|--------------------|--------------------|---|" << endl;
}

void Interface::printAllStudent()
{
	system("cls");
	printHead();
	for (int i = 0; i < students.size(); i++) 
	{
		cout << "|" << left << setw(7) << students[i]->getRecordBookId() << "|" << left << setw(14) << students[i]->getStudentName() << "|" << left << setw(20) << students[i]->getStudentSurName() << "|" << left << setw(20) << students[i]->getStudentPatronymic() << "|" << left << setw(3) << students[i]->getGender() << "|" << endl;
		printLine();
	}
	
	
}

int Interface::studentParser(char* recordBookId)
{
	for (int i = 0; i < students.size(); i++) {
		if (!strcmp(recordBookId, students[i]->getRecordBookId())) {
			return i;
		}
	}
	return (-1);
}

void Interface::deleteStudent()
{
	system("chcp 1251");
	system("cls");
	printAllStudent();
	cout << "������� ����� ������������ ������ ��������, �������� ������ �������: ";
	char* recordBookId = new char[8];
	cin >> recordBookId;
	int poppedIndex = studentParser(recordBookId);
	students.popAt(poppedIndex);
	system("cls");
	mainPage();
}

void Interface::editStudent()
{
	system("chcp 1251");
	system("cls");
	printAllStudent();
	cout << "������� ����� ������������ ������ ��������, �������� ������ ���������������: ";
	char* recordBookId = new char[8];
	cin >> recordBookId;
	system("cls");
	editPage(studentParser(recordBookId));
}

void Interface::printLineForOneStudent()
{
	cout << "|-------|--------------|--------------------|-------------------|---|-------------|-------|---------|-------|----------|" << endl;
}

void Interface::printHeadForOneStudent()
{
	cout << "|-------|--------------|--------------------|-------------------|---|-------------|-------|---------|-------|----------|" << endl
		 << "|���.���|     ���      |      �������       |      ��������     |���|���� ��������|��� �/�|���������|�������|  ������  |" << endl
		 << "|-------|--------------|--------------------|-------------------|---|-------------|-------|---------|-------|----------|" << endl;
}

void Interface::editRecordBookId(int index)
{
	char* newRecordBookId = new char[8];
	cout << "������� ����� ����� ������������� ������: ";
	cin >> newRecordBookId;
	int res = studentParser(newRecordBookId);
	if (res == -1) {
		delete students[index]->getRecordBookId();
		students[index]->setRecordBookId(newRecordBookId);
	}
	else {
		cout << "������� � ����� ������� ������������� ������ ����������, ����������� ������!" << endl;
		editRecordBookId(index);
	}
}

void Interface::editGender(int index)
{
	char sex[2];
	cout << "������� ����� ��� �������� (0 - �������, 1 - �������): ";
	cin >> sex;
	if (sex[0] == '0' || sex[0] == '1') {
		students[index]->setGender(sex);
	}
	else {
		cout << "�� ����� ���-�� �� ��, ��������� �������" << endl;
		editGender(index);
	}
}

void Interface::editBirthaday(int index)
{
	birthday birth;
	cout << "������� ����� ���� ��������: ";
	int day;
	cin >> day;
	cin.clear();
	std::cin.ignore(32767, '\n');
	birth.day = day;
	cout << endl << "������� ����� ����� ��������: ";
	int month;
	cin >> month;
	cin.clear();
	std::cin.ignore(32767, '\n');
	birth.month = month;
	cout << "������� ����� ��� ��������: ";
	int year;
	cin >> year;
	cin.clear();
	std::cin.ignore(32767, '\n');
	birth.year = year;
	if (birth.checkDate()) {
		students[index]->setStudentBirthday(birth);
	}
	else {
		cout << "��������� ������, ������� ���������� ������" << endl;
		editBirthaday(index);
	}

}
void Interface::printSessionLine()
{
	cout << "|---|-------------------|------|" << endl;
}

void Interface::printSessionHead()
{
	cout << "|---|-------------------|------|" << endl
		 << "| � | �������� �������� |������|" << endl
		 << "|---|-------------------|------|" << endl;

}
void Interface::printSubjectLine()
{
	cout << "|   |-------------------|------|" << endl;
}
void Interface::editSession(int index)
{
	printSessionHead();
	for (int i = 0; i < students[index]->getSession().size(); i++) {
		cout << "|" << left << setw(3) << students[index]->getSession()[i].sessionNumber << "|" << left << setw(19) << students[index]->getSession()[i].subj[0].subj << "|" << left << setw(6) << students[index]->getSession()[i].subj[0].grade << "|" << endl;
		printSubjectLine();
		for (int j = 1; j < students[index]->getSession()[i].subj.size(); j++) {
			cout << "|   |" << left << setw(19) << students[index]->getSession()[i].subj[j].subj << "|" << left << setw(6) << students[index]->getSession()[i].subj[j].grade << "|" << endl;
			if (j != students[index]->getSession()[i].subj.size() - 1) printSubjectLine();
		}
		printSessionLine();
	}
	cout << "�������� ��������:" << endl
		<< "1. ������������� ����������� ������/�������" << endl
}

void Interface::editPage(int index)
{
	printHeadForOneStudent();
	cout << "|" << left << setw(7) << students[index]->getRecordBookId() << "|" << left << setw(14) << students[index]->getStudentName()
		 << "|" << left << setw(20) << students[index]->getStudentSurName() << "|" << left << setw(19) << students[index]->getStudentPatronymic()
		 << "|" << left << setw(3) << students[index]->getGender() << "|" << left << setw(13) << students[index]->getStudentBirthday().getDate()
		 << "|" << left << setw(7) << students[index]->getAdmissionYear() << "|" << left << setw(9) << students[index]->getFaculty()
		 << "|" << left << setw(7) << students[index]->getDepartment() << "|" << left << setw(10) << students[index]->getGroup() << "|";
	printLineForOneStudent();
	cout << "�������� ��������:" << endl
		 << "1. �������� ����� ������������� ������" << endl
		 << "2. �������� ��� ��������" << endl
		 << "3. �������� ������� ��������" << endl
		 << "4. �������� �������� ��������" << endl
		 << "5. �������� ��� ��������" << endl
		 << "6. �������� ���� �������� ��������" << endl
		 << "7. �������� ��� ����������� ��������" << endl
		 << "8. �������� ��������� ��������" << endl
		 << "9. �������� ������� ��������" << endl
		 << "10. �������� ������ ��������" << endl
		 << "11. ������������� ������" << endl;
	int choice;
	cin >> choice;
	cin.clear();
	std::cin.ignore(32767, '\n');
	if (choice == 1) {
		editRecordBookId(index);
	}
	if (choice == 2) {
		char* newStudentName = new char[64];
		cout << "������� ����� ����� ��� ��������: ";
		cin >> newStudentName;
		delete students[index]->getStudentName();
		students[index]->setStudentName(newStudentName);

	}
	if (choice == 3) {
		char* newStudentSurName = new char[64];
		cout << "������� ����� ����� ������� ��������: ";
		cin >> newStudentSurName;
		delete students[index]->getStudentSurName();
		students[index]->setStudentSurName(newStudentSurName);
	}
	if (choice == 4) {
		char* newStudentPatronymic = new char[64];
		cout << "������� ����� ����� �������� ��������: ";
		cin >> newStudentPatronymic;
		delete students[index]->getStudentPatronymic();
		students[index]->setStudentPatronymic(newStudentPatronymic);
	}
	if (choice == 5) {
		editGender(index);

	}
	if (choice == 6) {
		editBirthaday(index);
	}
	if (choice == 7) {
		int newAdmissionYear;
		cout << "������� ����� ����� ��� ����������� ��������: ";
		cin >> newAdmissionYear;
		students[index]->setAdmissionYear(newAdmissionYear);
	}
	if (choice == 8) {
		char* newFaculty = new char[64];
		cout << "������� ����� ����� ��������� ��������: ";
		cin >> newFaculty;
		delete students[index]->getFaculty();
		students[index]->setFaculty(newFaculty);
	}
	if (choice == 9) {
		char* newDepartment = new char[64];
		cout << "������� ����� ����� ��������� ��������: ";
		cin >> newDepartment;
		delete students[index]->getDepartment();
		students[index]->setDepartment(newDepartment);
	}
	if (choice == 10) {
		char* newGroup = new char[64];
		cout << "������� ����� ����� ������� ��������: ";
		cin >> newGroup;
		delete students[index]->getGroup();
		students[index]->setGroup(newGroup);
	}
	if (choice == 11) {
		editSession(index);
	}
	editPage(index);
}