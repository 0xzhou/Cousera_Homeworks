#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

class Student {
private:
	char name[20];
	int age;
	char number[20];
	int grade1, grade2, grade3, grade4, a_grade;// four years grades and average grade
public:
	void Init(char name_[20], int age_,char number_[20],int grade_1,int grade_2,int grade_3,int grade_4) {//initialize function
		strcpy_s(name, name_);
		age = age_;
		strcpy_s(number, number_);
		grade1 = grade_1;
		grade2 = grade_2;
		grade3 = grade_3;
		grade4 = grade_4;
	}
	void shuchu() {
		cout << name << ',' << age << ',' << number << ',' << (grade1 + grade2 + grade3 + grade4) / 4 << endl;
	}
};

int main() {
		Student A;
		char Name[20], Number[20];
		int grade1, grade2, grade3, grade4;
		char s1, s2, s3, s4;
		int age;
		cin.getline(Name, 20, ',');
		cin >> age >> s1;
		cin.getline(Number, 20, ',');
		cin>>grade1 >> s2 >> grade2 >> s3 >> grade3 >> s4 >> grade4;
		A.Init(Name, age, Number, grade1, grade2, grade3, grade4);
		A.shuchu();
		return 0;
}






