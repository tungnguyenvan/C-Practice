#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Student
{
	int _id;
	string _name;
	float _score;
};

vector<Student> students;
bool wantExit = false;

void question();
void showStudents(vector<Student> *students);
void getInforStudent();
bool checkIdExit(int id, vector<Student> students);
bool insertStudent(Student student, vector<Student> *students);
bool saveStudentsToFile(vector<Student> students);
bool loadStudentsFromFile(vector<Student> *Students);

int main() {
	while (!wantExit)
	{
		question();
	}
	cout << "Thank for use ... " << endl;
	system("pause");
	return 0;
}

void question() {
	cout << "------------ WELLCOME -----------" << endl << endl;

	cout << "1. Input" << endl;
	cout << "2. Display" << endl;
	cout << "3. Save to file" << endl;
	cout << "4. Load from file" << endl;
	cout << "0. Exit" << endl;

	cout << "----------------------------------" << endl << endl;
	cout << "Choose: ";

	int select;
	cin >> select;

	switch (select)
	{
	case 1 :
		getInforStudent();
		break;
	case 2:
		//showStudents();
		break;
	case 3:
		//saveStudentsToFile();
		break;
	case 4:
		//loadStudentsFromFile();
		break;
	case 0:
		wantExit = true;
		break;
	default:
		break;
	}
}

void getInforStudent() {
	int id;
	string name;
	float score;

	cout << "ID: "; cin >> id;
	cout << "Name: "; getline(cin, name); fflush;
	cout << "score: "; cin >> score;

	if (checkIdExit(id, students)) {
		Student  student;
		student._id = id;
		student._name = name;
		student._score = score;

		if (insertStudent(student, &students))
			cout << "Insert Student success!" << endl;
		else cout << "Insert Student Failed!" << endl;
	}
}

bool checkIdExit(int id, vector<Student> students) {
	for (int i = 0; i < students.size(); i++) {
		if (students.at(i)._id == id)
			return false;
	}
	return true;
}

bool insertStudent(Student student, vector<Student> *students) {
	int oldSize = students->size();
	students->push_back(student);

	if (oldSize < students->size())
		return true;
	return false;
}