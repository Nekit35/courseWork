#include "Interface.h"
Interface::Interface()
{
	StartPage();
}

void Interface::StartPage()
{

	cout << "Выберите действие:" << endl
		<< "1. Создать базу данных" << endl
		<< "2. Использовать существующую базу данных" << endl;
	cin.clear();
	char choice;
	cin >> choice;
	if (choice == '1') {
		db.createDataBase();
		mainPage();
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
	cout << "Введите название существующей базы данных (Пример: db.enc):" << endl;
	cin >> nameOfDB;
	cin.clear();
	std::cin.ignore(32767, '\n');
	db.setPathToDB(nameOfDB);
	cout << "Введите пароль: ";
	char password[128];
	inputPassword(password);
	CryptoTools crypt(db.getPathToDB());
	crypt.decrypt(password);
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

	*ptr = 0; 
	return buffer;
}
void Interface::mainPage()
{
	system("cls");
	cout << "Выберите действие:" << endl
		<< "1. Вывести список всех студентов" << endl           //+
		<< "2. Добавить студента" << endl                       //+
		<< "3. Редактировать студента" << endl                  //+
		<< "4. Удалить студента" << endl                        //+
		<< "5. Индивидуальное задание" << endl                  //-
		<< "6. Сохранить и зашифровать базу данных" << endl;    //-
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
		doIndidualTask();
		break;
	case '6':
		saveAndCrypt();
		exit(0);
		break;
	default:
		mainPage();
		break;
	}
}

void Interface::saveAndCrypt()
{
	db.createDataBase();
	for (int i = 0; i < students.size(); i++) {
		db.addToData(students[i]->getDataForDB());
	}
	cout << "Введите пароль для шифрования базы: ";
	char password[128];
	inputPassword(password);
	CryptoTools crypt(db.getPathToDB());
	crypt.encrypt(password);
}

void Interface::addStudent()
{
	system("chcp 1251");
	system("cls");
	Student* newStudent = new Student;
	while (true) 
	{
		cout <<"Введите имя студента: ";
		char name[64];
		cin >> name;
		if (newStudent->setStudentName(name) == 1)
		{
			newStudent->setStudentName(name);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные";
	}
	system("cls");
	while (true)
	{
		cout <<"Введите фамилию студента: ";
		char surname[64];
		cin >> surname;
		if (newStudent->setStudentSurName(surname) == 1)
		{
			newStudent->setStudentSurName(surname);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные" << endl;
	}
	system("cls");
	while (true)
	{
		cout <<  "Введите отчество студента(если есть): ";
		char patronymic[64];
		cin >> patronymic;
		if (newStudent->setStudentPatronymic(patronymic) == 1)
		{
			newStudent->setStudentPatronymic(patronymic);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные" << endl;
	}
	system("cls");
	birthday birth;
	while (!birth.checkDate())
	{	
		cout << "Введите день рождения: ";
		int day;
		cin >> day;
		cin.clear();
		std::cin.ignore(32767, '\n');
		birth.day = day;
		cout << endl << "Введите месяц рождения: ";
		int month;
		cin >> month;
		cin.clear();
		std::cin.ignore(32767, '\n');
		birth.month = month;
		cout << endl << "Введите год рождения: ";
		int year;
		cin >> year;
		cin.clear();
		std::cin.ignore(32767, '\n');
		birth.year = year;
		if (birth.checkDate()) {
			newStudent->setStudentBirthday(birth);
			break;
		}
		else cout << endl <<"Произошла ошибка, введите корректные данные" << endl;
		cin.clear();
	}
	system("cls");
	while (true) {
		cout  << "Введите год поступления: ";
		int admissionYear;
		cin >> admissionYear;
		cin.clear();
		std::cin.ignore(32767, '\n');
		if ((admissionYear > 2019) && (admissionYear < 2023))
		{
			newStudent->setAdmissionYear(admissionYear);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные" << endl;
	}
	system("cls");
	while (true)
	{
		cout  << "Введите факультет студента: ";
		char faculty[64];
		cin >> faculty;
		if (newStudent->setFaculty(faculty))
		{
			newStudent->setFaculty(faculty);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные" << endl;
	}
	system("cls");
	while (true)
	{
		cout  << "Введите кафедру студента: ";
		char department[64];
		cin >> department;
		if (newStudent->setDepartment(department))
		{
			newStudent->setDepartment(department);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные" << endl;
	}
	system("cls");
	while (true)
	{
		cout  << "Введите группу студента: ";
		char group[64];
		cin >> group;
		if (newStudent->setGroup(group))
		{
			newStudent->setGroup(group);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные" << endl;
	}
	system("cls");
	while (true)
	{
		cout << "Введите номер зачетной книжки студента: ";
		char RecordBookId[64];
		cin >> RecordBookId;
		if (newStudent->setRecordBookId(RecordBookId))
		{
			newStudent->setRecordBookId(RecordBookId);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные" << endl;
	}
	system("cls");
	while (true)
	{
		cout  << "Введите пол студента студента(0 - мужчина, 1 - женщина): ";
		char gender[64];
		cin >> gender;
		if (newStudent->setGender(gender))
		{
			newStudent->setGender(gender);
			break;
		}
		else cout << "Произошла ошибка, введите корректные данные" << endl;
	}
	system("cls");
	MyList<resSession> resAllSession;
		for (int i = 1; i < 10; i++)
		{
			resSession session;
			session.sessionNumber = i;
			for (int j = 1; j < 11; j++) {
				Subject newSubject;
				cout << "Введите " << j << "й предмет " << i << "й сессии: ";
				char *subjectStr=new char[64];
				cin >> subjectStr;
				cin.clear();
				std::cin.ignore(32767, '\n');
				newSubject.subj = subjectStr;
				cout << "Введите оценку за " << newSubject.subj << "(если зачет, то 0 - незачет, 1 - зачет, -1 - неявка): ";
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
				cout << "Если хотите вернуться в меню сессий, введите 1, иначе, введите 0: ";
				char choice;
				cin >> choice;
				if (choice == '1') break;
				system("cls");
			}
			resAllSession.push_back(session);
			system("cls");
			cout << "Если у студента больше нет сессий, введите 1, иначе, введите 0: ";
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
		 << "|№ст.бил|     Имя      |      Фамилия       |      Отчество      |Пол|" << endl
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
	cout << "Введите номер студенчекого билета студента, которого хотите удалить: ";
	char* recordBookId = new char[8];
	cin >> recordBookId;
	int poppedIndex = studentParser(recordBookId);
	if (students.size() == 0 || poppedIndex == -1) {
		cout << "Студента с таким номером студенческого билета не существует!" << endl;
		mainPage();
		_getch();
	}
	students.popAt(poppedIndex);
	system("cls");
	mainPage();
}

void Interface::editStudent()
{
	system("chcp 1251");
	system("cls");
	printAllStudent();
	cout << "Введите номер студенчекого билета студента, которого хотите отредактировать или введите 0, если хотите вернуться: ";
	char* recordBookId = new char[8];
	cin >> recordBookId;
	if (recordBookId[0] == '0') { mainPage(); }
	system("cls");
	int resOfParsing = studentParser(recordBookId);
	if (resOfParsing == -1) {
		cout << "Студента с таким номером студенческого билета не существует!" << endl;
		_getch();
		editStudent();
	}
	editPage(resOfParsing);
}

void Interface::printLineForOneStudent()
{
	cout << "|-------|--------------|--------------------|-------------------|---|-------------|-------|---------|-------|----------|" << endl;
}

void Interface::printHeadForOneStudent()
{
	cout << "|-------|--------------|--------------------|-------------------|---|-------------|-------|---------|-------|----------|" << endl
		 << "|№ст.бил|     Имя      |      Фамилия       |      Отчество     |Пол|Дата Рождения|Год п/п|Факультет|Кафедра|  Группа  |" << endl
		 << "|-------|--------------|--------------------|-------------------|---|-------------|-------|---------|-------|----------|" << endl;
}

void Interface::editRecordBookId(int index)
{
	char* newRecordBookId = new char[8];
	cout << "Введите новый номер студенческого билета: ";
	cin >> newRecordBookId;
	int res = studentParser(newRecordBookId);
	if (res == -1) {
		delete students[index]->getRecordBookId();
		students[index]->setRecordBookId(newRecordBookId);
	}
	else {
		cout << "Студент с таким номером студенческого билета существует, используйте другой!" << endl;
		editRecordBookId(index);
	}
}

void Interface::editGender(int index)
{
	char sex[2];
	cout << "Введите новый пол студента (0 - мужчина, 1 - женщина): ";
	cin >> sex;
	if (sex[0] == '0' || sex[0] == '1') {
		students[index]->setGender(sex);
	}
	else {
		cout << "Вы ввели что-то не то, повторите попытку" << endl;
		editGender(index);
	}
}

void Interface::editBirthaday(int index)
{
	birthday birth;
	cout << "Введите новый день рождения: ";
	int day;
	cin >> day;
	cin.clear();
	std::cin.ignore(32767, '\n');
	birth.day = day;
	cout << endl << "Введите новый месяц рождения: ";
	int month;
	cin >> month;
	cin.clear();
	std::cin.ignore(32767, '\n');
	birth.month = month;
	cout << "Введите новый год рождения: ";
	int year;
	cin >> year;
	cin.clear();
	std::cin.ignore(32767, '\n');
	birth.year = year;
	if (birth.checkDate()) {
		students[index]->setStudentBirthday(birth);
	}
	else {
		cout << "Произошла ошибка, введите корректные данные" << endl;
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
		 << "| № | Название предмета |Оценка|" << endl
		 << "|---|-------------------|------|" << endl;

}
void Interface::printSubjectLine()
{
	cout << "|   |-------------------|------|" << endl;
}

bool Interface::sessionParser(int index, int parsIndex)
{
	for (int i = 0; i < students[index]->getSession().size(); i++) {
		if (students[index]->getSession()[i].sessionNumber == parsIndex) return 1;
		else return 0;
	}
}
int Interface::checkSession(int index, int sessionNum)
{
	MyList<resSession> ses = students[index]->getSession();
	for (int i = 0; i < ses.size(); i++) {
		if (ses[i].sessionNumber != sessionNum) return 1;
	}
	return 0;
}
void Interface::addSession(int index)
{
	MyList<resSession> ses = students[index]->getSession();
	if (ses.size() == 9) {
		cout << "Достигнуто максимальное количество сессий" << endl;
		_getch();
	}
	else {
		int sessionNum=100;
		int flag = 0;
		while (true) {
			while (sessionNum > 9) {
				cout << "Введите номер сессии, которую хотите добавить: ";
				cin >> sessionNum;
			}
			
			if (checkSession(index, sessionNum) == 1) {
				if (sessionNum == 1) {
					resSession res;
					res.sessionNumber = sessionNum;
					ses.insert(res, 0);
					flag = 1;
					break;
				}
				if (sessionNum == 9&& ses.size()==8) {
					resSession res;
					res.sessionNumber = sessionNum;
					ses.insert(res, 8);
					flag = 1;
					break;
				}
				for (int i = 0; i < ses.size() - 1; i++) {
					if (ses[i].sessionNumber< sessionNum && ses[i + 1].sessionNumber > sessionNum) {
						resSession res;
						res.sessionNumber = sessionNum;
						ses.insert(res, i+1);
						flag = 1;
						break;
					}
				}
			}
			if (flag == 1) break;
		}
	}
	students[index]->setSession(ses);
	return;
}


void Interface::addSubject(int index)
{
	MyList<resSession> ses = students[index]->getSession();
	int sessionNum = 100;
	int flag = 0;
	int sesIndex;
		while (sessionNum > 9) {
			cout << "Введите номер сессии, предмет в которой хотите добавить предмет: ";
			cin >> sessionNum;
			for (int i = 0; i<ses.size(); i++) {
				if (ses[i].sessionNumber == sessionNum) { 
					flag = 1; 
					sesIndex = i;
				}
			}
			if (ses[sesIndex].subj.size() == 10) {
				cout << "В этой сессии уже максимальное количество предметов!" << endl;
				_getch();
				return;
			}
			if (flag == 0) {
				cout << "Вы ввели номер сессии, которой не существует, попробуйте снова!" << endl;
				sessionNum = 100;
			}
		}
		char* newSubjectName = new char[64];
		int newGrade;
		cout << "Введите название предмета (если предмет состоит из 2 и более слов, то вводить так ААнглийский_язык): ";
		cin >> newSubjectName;
		cout << "Введите оценку за предмет(-1 - неявка, 0 - незачет, 1 - зачет): ";
		cin >> newGrade;
		Subject newSubject;
		newSubject.subj = newSubjectName;
		newSubject.grade = newGrade;
		ses[sesIndex].subj.push_back(newSubject);
		students[index]->setSession(ses);
}
void Interface::editSession(int index)
{
	system("cls");
	printSessionHead();
	for (int i = 0; i < students[index]->getSession().size(); i++) {
		if (students[index]->getSession()[i].subj.size() == 0) {
			cout << "|" << left << setw(3) << students[index]->getSession()[i].sessionNumber << "|-------------------|------|" << endl;
			printSessionLine();
		}
		else {
			cout << "|" << left << setw(3) << students[index]->getSession()[i].sessionNumber << "|" << left << setw(19) << students[index]->getSession()[i].subj[0].subj << "|" << left << setw(6) << students[index]->getSession()[i].subj[0].grade << "|" << endl;
			if (students[index]->getSession()[i].subj.size() == 1) printSessionLine();

			else {
				for (int j = 1; j < students[index]->getSession()[i].subj.size(); j++) {
					cout << "|   |" << left << setw(19) << students[index]->getSession()[i].subj[j].subj << "|" << left << setw(6) << students[index]->getSession()[i].subj[j].grade << "|" << endl;
					if (j != students[index]->getSession()[i].subj.size() - 1) printSubjectLine();
				}
				printSessionLine();
			}
		}
	}
	cout << "Выберите действие:" << endl
		 << "1. Редактировать существущие оценку/предмет" << endl
	 	 << "2. Добавить предмет/сессию" << endl
		 << "3. Удалить сессию/предмет" << endl
	     << "4. Назад" << endl;
	int choice;
	cin >> choice;
	cin.clear();
	std::cin.ignore(32767, '\n');
	if (choice == 1) 
	{
		editGradeSubject(index);
	}
	if (choice == 2)
	{
		cout << "Выберите действие:" << endl
			<< "1. Добавить сессию." << endl
			<< "2. Добавить предмет" << endl
		    << "3. Назад" << endl;
		int deleteChoise;
		cin >> deleteChoise;
		if (deleteChoise == 1) {
			addSession(index);
		}
		if (deleteChoise == 2) {
			addSubject(index);
		}
		if (deleteChoise == 3) {
			editSession(index);
		}
	}
	if (choice == 3)
	{
		cout << "Выберите действие:" << endl
			<< "1. Удалить сессию." << endl
			<< "2. Удалить предмет" << endl
			<< "3. Назад" << endl;
		int deleteChoise;
		cin >> deleteChoise;
		if (deleteChoise == 1) {
			deleteSession(index);
		}
		if (deleteChoise == 2) {
			deleteSubject(index);
		}
		if (deleteChoise == 3) {
			editSession(index);
		}

	}
	if (choice == 4)
	{
		editPage(index);
	}
	editPage(index);
}

void Interface::deleteSession(int index)
{
	int sessionForDelete = 100;
	while (sessionForDelete > 9) {
		cout << "Введите номер сессии, которую хотите удалить: ";
		cin >> sessionForDelete;
	}
	MyList<resSession> ses = students[index]->getSession();
	for (int i = 0; i < ses.size(); i++) {
		if (sessionForDelete == 1) {
			ses.pop_front();
			students[index]->setSession(ses);
			return;
		}
		if (ses[i].sessionNumber == sessionForDelete) {
			ses.popAt(i);
			students[index]->setSession(ses);
			return;
		}
	}
}

void Interface::deleteSubject(int index)
{
	int sessionForDelete = 100;
	while (sessionForDelete > 9) {
		cout << "Введите номер сессии, в которой необходимо удалить предмет: ";
		cin >> sessionForDelete;
	}

	MyList<resSession> ses = students[index]->getSession();
	for (int i = 0; i < ses.size(); i++) {
		if (ses[i].sessionNumber == sessionForDelete) {
			printSessionHead();
			int count = 1;
			for (int k = 0; k < ses[i].subj.size(); k++) {
				cout << "| " << count << " |" << left << setw(19) << ses[i].subj[k].subj << "|" << left << setw(6) << ses[i].subj[k].grade << "|" << endl;
				count++;
				printSessionLine();
			}
			int choiceNum = 100;
			while (choiceNum > count) {
				cout << "Выберите какой по номеру предмет вы хотите удалить: ";
				cin >> choiceNum;
			}
			ses[i].subj.popAt(choiceNum - 1);
		}
	}
	students[index]->setSession(ses);
	return;
}
void Interface::editGradeSubject(int index)
{
	int sessionNumber = 1000;
	while (sessionNumber > 9) {
		cout << "Введите номер сессии, оценку/предмет, в которой хотите отредактировать: ";
		cin >> sessionNumber;
	}
	printSessionHead();
	int count = 1;
	for (int k = 0; k < students[index]->getSession()[sessionNumber - 1].subj.size(); k++) {
		cout << "| " << count << " |" << left << setw(19) << students[index]->getSession()[sessionNumber - 1].subj[k].subj << "|" << left << setw(6) << students[index]->getSession()[sessionNumber - 1].subj[k].grade << "|" << endl;
		count++;
		printSessionLine();
	}
	int choiceNum = 100;
	while (choiceNum > count) {
		cout << "Выберите какой по номеру предмет вы хотите отредактировать: ";
		cin >> choiceNum;
	}
	cout << "Выберите действие:" << endl
		<< "1. Редактировать оценку" << endl
		<< "2. Редактировать предмет" << endl
		<< "3. Назад" << endl;
	int choiceChange = 100;
	while (choiceChange > 3) {
		cin >> choiceChange;
	}
	if (choiceChange == 1) {

		editGrade(index, sessionNumber, choiceNum);
	}
	if (choiceChange == 2) {
		editSubject(index, sessionNumber, choiceNum);
	}
	if (choiceChange == 3) {
		editSession(index);
	}
	editSession(index);
}
void Interface::editSubject(int index, int sessionNumber, int choiceNum)
{
	char* newSubject = new char[64];
	cout << "Введите новый предмет: ";
	cin >> newSubject;
	students[index]->getSession()[sessionNumber - 1].subj[choiceNum-1].subj = newSubject;
}
void Interface::editGrade(int index, int sessionNumber, int choiceNum)
{
	int newGrade = 100;
	while (newGrade > 6) {
		cout << "Введите новую оценку(-1 - неявка, 0 - незачет, 1 - зачет): ";
		cin >> newGrade;
	}
	students[index]->getSession()[sessionNumber - 1].subj[choiceNum-1].grade = newGrade;
}

void Interface::editPage(int index)
{
	system("cls");
	printHeadForOneStudent();
	cout << "|" << left << setw(7) << students[index]->getRecordBookId() << "|" << left << setw(14) << students[index]->getStudentName()
		 << "|" << left << setw(20) << students[index]->getStudentSurName() << "|" << left << setw(19) << students[index]->getStudentPatronymic()
		 << "|" << left << setw(3) << students[index]->getGender() << "|" << left << setw(13) << students[index]->getStudentBirthday().getDate()
		 << "|" << left << setw(7) << students[index]->getAdmissionYear() << "|" << left << setw(9) << students[index]->getFaculty()
		 << "|" << left << setw(7) << students[index]->getDepartment() << "|" << left << setw(10) << students[index]->getGroup() << "|";
	printLineForOneStudent();
	cout << "Выберите действие:" << endl
		<< "1. Изменить номер студенческого билета" << endl
		<< "2. Изменить имя студента" << endl
		<< "3. Изменить фамилию студента" << endl
		<< "4. Изменить отчество студента" << endl
		<< "5. Изменить пол студента" << endl
		<< "6. Изменить дату рождения студента" << endl
		<< "7. Изменить год поступления студента" << endl
		<< "8. Изменить факультет студента" << endl
		<< "9. Изменить кафедру студента" << endl
		<< "10. Изменить группу студента" << endl
		<< "11. Редактировать успеваемость" << endl
		<< "12. Назад" << endl;
	int choice;
	cin >> choice;
	cin.clear();
	std::cin.ignore(32767, '\n');
	if (choice == 1) {
		editRecordBookId(index);
	}
	if (choice == 2) {
		char* newStudentName = new char[64];
		cout << "Введите новый новое имя студента: ";
		cin >> newStudentName;
		delete students[index]->getStudentName();
		students[index]->setStudentName(newStudentName);

	}
	if (choice == 3) {
		char* newStudentSurName = new char[64];
		cout << "Введите новый новую фамилию студента: ";
		cin >> newStudentSurName;
		delete students[index]->getStudentSurName();
		students[index]->setStudentSurName(newStudentSurName);
	}
	if (choice == 4) {
		char* newStudentPatronymic = new char[64];
		cout << "Введите новый новое отчество студента: ";
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
		cout << "Введите новый новый год поступления студента: ";
		cin >> newAdmissionYear;
		students[index]->setAdmissionYear(newAdmissionYear);
	}
	if (choice == 8) {
		char* newFaculty = new char[64];
		cout << "Введите новый новый факультет студента: ";
		cin >> newFaculty;
		delete students[index]->getFaculty();
		students[index]->setFaculty(newFaculty);
	}
	if (choice == 9) {
		char* newDepartment = new char[64];
		cout << "Введите новый новый факультет студента: ";
		cin >> newDepartment;
		delete students[index]->getDepartment();
		students[index]->setDepartment(newDepartment);
	}
	if (choice == 10) {
		char* newGroup = new char[64];
		cout << "Введите новый новую кафедру студента: ";
		cin >> newGroup;
		delete students[index]->getGroup();
		students[index]->setGroup(newGroup);
	}
	if (choice == 11) {
		editSession(index);
	}
	if (choice == 12) {
		mainPage();
	}
	editPage(index);
}

void Interface::doIndidualTask()
{
	system("cls");
	cout << "Индивидуальное задание:" << endl
	 	 << "Распечатать всех студентов, у которых за все время обучения не более 25 % оценок " << endl
	 	 << "a) 3;" << endl
	 	 << "б) 3 и 4;" << endl
	 	 << "в) 5;" << endl
		 << "г) 3 и 5;" << endl
		 << "д) 4 и 5;" << endl
		 << "Выберите вариант выполнения задания, если хотите вернуться в главное меню, нажмите 0 >";
	char choice='f';
	Filter filter(students);
	while (true) {
		cin >> choice;
		if (choice == 'а' || choice == 'б' || choice == 'в' || choice == 'г' || choice == 'д' || choice == '0') {
			break;
		}
		cout << "Вы ввели что-то не то, попробуйте еще раз!" << endl;
	}
	switch (choice)
	{
	case 'а':
		printFilteredStudents(filter.filter3());
		break;
	case 'б':
		printFilteredStudents(filter.filter34());
		break;
	case 'в':
		printFilteredStudents(filter.filter5());
		break;
	case 'г':
		printFilteredStudents(filter.filter35());
		break;
	case 'д':
		printFilteredStudents(filter.filter45());
		break;
	case '0':
		mainPage();
		break;
	default:
		break;
	}
	doIndidualTask();
}

void Interface::printFilteredLine()
{
	cout << "|-------|--------------|--------------------|--------------------|" << endl;
}

void Interface::printFilteredStudents(MyList<Student*> filteredStudents)
{
	system("cls");
	
	int studentsCount = filteredStudents.size();
	if (studentsCount == 0) {
		cout << "Студента по заданному фильтру не найдены!";
		_getch();
		return;
	}
	cout << "|-------|--------------|--------------------|--------------------|" << endl
		 << "|№ст.бил|     Имя      |      Фамилия       |      Отчество      |" << endl
		 << "|-------|--------------|--------------------|--------------------|" << endl;
	for (int i = 0; i < studentsCount; i++) {
		cout << "|" << left << setw(7) << students[i]->getRecordBookId() << "|" << left << setw(14) << students[i]->getStudentName() << "|" << left << setw(20) << students[i]->getStudentSurName() << "|" << left << setw(20) << students[i]->getStudentPatronymic() << "|" << endl;
		printFilteredLine();
	}
	_getch();
	doIndidualTask();
}