#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
const string FILE_PATH = "Student_manager.txt";

enum LoadFile
{
	LOADFAIL,
	FILEEMPTY,
	LOADSUCCESS
};
struct Student
{
	int _id;
	string _name;
	float _score;
};

vector<Student> students;
bool wantExit = false;

void question();
void showStudents(vector<Student> students);
void getInforStudent();
void continueInsertStudent();
bool checkIdExit(int id, vector<Student> students);
bool insertStudent(Student student, vector<Student> *students);
bool saveStudentsToFile(vector<Student> students);
int loadStudentsFromFile(vector<Student> *students);

int main() {
	while (!wantExit)
	{
		question();
	}
	cout << "Thank for use ... " << endl;
	system("pause");
	return 0;
}

/**
* Show list question
*/
void question() {
	system("cls");
	cout << "\t------------ WELLCOME -----------" << endl << endl;

	cout << "\t*\t1. Input\t\t*" << endl;
	cout << "\t*\t2. Display\t\t*" << endl;
	cout << "\t*\t3. Save to file\t\t*" << endl;
	cout << "\t*\t4. Load from file\t*" << endl;
	cout << "\t*\t0. Exit\t\t\t*" << endl;

	cout << "\t----------------------------------" << endl << endl;
	cout << "Choose: ";

	int select;
	cin >> select;

	switch (select)
	{
	case 1:
		getInforStudent();
		break;
	case 2:
		showStudents(students);
		break;
	case 3:
		if (saveStudentsToFile(students)) cout << "Save file success!" << endl;
		else cout << "Save file Failed, Try it!" << endl;
		system("pause");
		break;
	case 4:
		switch (loadStudentsFromFile(&students))
		{
		case LOADFAIL: 
			cout << "Load file to List Failed. Try it!" << endl;
			break;
		case FILEEMPTY:
			cout << "File empty!" << endl;
			break;
		case LOADSUCCESS:
			cout << "Load file to List success!" << endl;
			break;
		default:
			break;
		}
		system("pause");
		break;
	case 0:
		wantExit = true;
		break;
	default:
		break;
	}
}

/**
* Get id, name, score of student in cosole,
* if id not exist then insert to list studen
*/
void getInforStudent() {
	system("cls");
	cout << "----- INSERT STUDENT -----" << endl;
	cout << "BIGGEST ID : " << students.size() << endl;
	int id;
	string name;
	float score;

	cout << "ID: "; cin >> id; cin.get();

	if (checkIdExit(id, students)) {
		if (id < 0) {
			cout << "You need input id > 0, try it!" << endl;
			system("pause");
			return;
			
		}
		cout << "Name: "; getline(cin, name);
		cout << "score: "; cin >> score;

		Student  student;
		student._id = id;
		student._name = name;
		student._score = score;

		if (insertStudent(student, &students)) {
			cout << "Insert Student success!" << endl;
			continueInsertStudent();
		}
		else cout << "Insert Student Failed!" << endl;
	}
	else {
		cout << "This ID is already Exist, Please try input." << endl;
		continueInsertStudent();
		return;
	}
}

/**
* Check id not exist
*/
bool checkIdExit(int id, vector<Student> students) {
	for (Student student : students) {
		if (student._id == id)
			return false;
	}
	return true;
}

/**
* Insert Studen to list student
*/
bool insertStudent(Student student, vector<Student> *students) {
	int oldSize = students->size();
	students->push_back(student);

	if (oldSize < students->size())
		return true;
	return false;
}

/**
* Question user do you want continue?
*/
void continueInsertStudent() {
	cout << "You want continue insert student? (y/n)";
	
	char select;
	cin >> select;
	if (select == 'y') getInforStudent();
}

/**
* Show list students to console
*/
void showStudents(vector<Student> students) {
	system("cls");
	cout << "ID\t\tFull Name\t\tScore" << endl;
	for (Student student : students) {
		cout << student._id << "\t\t";
		cout << student._name << "\t\t";
		cout << student._score << endl;
	}
	cout << endl << endl;
	system("pause");
}

/**
* Save list student to file
*/
bool saveStudentsToFile(vector<Student> students) {
	ofstream insertToFile(FILE_PATH, std::ios::out);
	for (Student student : students) {
		insertToFile << student._id << endl;
		insertToFile << student._name << endl;
		insertToFile << student._score << endl;
		if (insertToFile.fail())
			return false;
	}

	insertToFile.close();
	return true;
}

/**
* Load stdent from file to List
*/
int loadStudentsFromFile(vector<Student> *students) {
	int oldSize = students->size();
	ifstream fileToList(FILE_PATH);
	if (fileToList.fail()) return LOADFAIL;
	int numLine = 0;
	Student student;
	string line;
	int id;
	float score;
	while (getline(fileToList, line))
	{ 
		numLine++;
		switch (numLine)
		{
		case 1:
			id = stoi(line);
			student._id = id;
			break;
		case 2:
			student._name = line;
			break;
		case 3:
			score = stof(line);
			student._score = score;
			numLine = 0;
			students->push_back(student);
			break;
		default:
			break;
		}
	}

	fileToList.close();
	if (oldSize < students->size()) return LOADSUCCESS;
	else return FILEEMPTY;
}