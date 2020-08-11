#include<iostream>
#include<fstream>
#include<iomanip>//출력할 때 매끄럽게 하기 위함
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
	cout << "프로그램 시작" << endl;
	stuFile.open("ch7STUFL.DAT");
	if (!stuFile) {
		cerr << "파일 오픈 에러" << endl;
		exit(100);
	}
	ofstream gradesFile;
	gradesFile.open("ch7STUGR.DAT");
	if (!gradesFile){
		cerr<<"파일 오픈 에러"<<endl;
	}
	int stuId, exam1, exam2, finalExam, avrg;
	char grade;

	while (getStu(stuFile, stuId, exam1, exam2, finalExam)) {
		calcGrade(exam1, exam2, finalExam, avrg, grade);
		writeStu(gradesFile, stuId, avrg, grade);
	}

	stuFile.close();
	gradesFile.close();
	cout << "프로그램 종료" << endl;

	return 0;
}