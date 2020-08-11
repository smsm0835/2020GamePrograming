#include<iostream>
#include<fstream>
#include<iomanip>//����� �� �Ų����� �ϱ� ����
#include<cstdlib>
using namespace std;

bool getStu(ifstream& stuFile, int& stuId, int& exam, int& exam2, int& finalExam) {
	stuFile >> stuId >> exam >> exam2 >> finalExam;
	if (!stuFile) {
		return false;
	}
	else {
		return true;
	}
}

void calcGrade(int exam1, int exam2, int finalExam, int& avrg, char& grade) {
	avrg = (exam1 + exam2 + finalExam) / 3;
	if (avrg >= 90) {
		grade = 'A';
	}
	else if (avrg >= 80) {
		grade = 'B';
	}
	else if (avrg >= 70) {
		grade = 'C';
	}
	else if (avrg >= 60) {
		grade = 'D';
	}
	else {
		grade = 'F';
	}
}
void writeStu(ofstream& gradesFile, int stuId, int avrg, char grade) {
	gradesFile.fill('0');
	gradesFile << setw(4) << stuId;
	gradesFile.fill(' ');
	gradesFile << setw(3) << avrg;
	gradesFile << ' ' << grade << endl;
}
int main() {
	ifstream stuFile;
	cout << "���α׷� ����" << endl;
	stuFile.open("ch7STUFL.DAT");
	if (!stuFile) {
		cerr << "���� ���� ����" << endl;
		exit(100);
	}
	ofstream gradesFile;
	gradesFile.open("ch7STUGR.DAT");
	if (!gradesFile){
		cerr<<"���� ���� ����"<<endl;
	}
	int stuId, exam1, exam2, finalExam, avrg;
	char grade;

	while (getStu(stuFile, stuId, exam1, exam2, finalExam)) {
		calcGrade(exam1, exam2, finalExam, avrg, grade);
		writeStu(gradesFile, stuId, avrg, grade);
	}

	stuFile.close();
	gradesFile.close();
	cout << "���α׷� ����" << endl;

	return 0;
}