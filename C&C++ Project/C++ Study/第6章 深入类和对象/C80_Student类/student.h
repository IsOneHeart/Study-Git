#pragma once
#include <string>
using namespace std;

class Student {
private:
	string name;
	string sex;
	string family_location;
	float total_mark;
public:
	Student();
	Student(string n, string s, string fl, float tm);
	//Student(string n = "����", string s = "��", string fl = "XXʡXX��XX��XX", float tm = 0) :name(n), sex(s), family_location(fl), total_mark(tm) {};
	~Student();
	void show();
	void set();
};

Student::Student() {
	name = "����";
	sex = "��";
	family_location = "XXʡXX��XX��XX";
	total_mark = 0;
}

Student::Student(string n, string s, string fl, float tm) {
	name = n;
	sex = s;
	family_location = fl;
	total_mark = tm;
}

Student::~Student() {
	cout << "<<" << endl;
}

void Student::show() {
	cout << "������" << name << endl;
	cout << "�Ա�" << sex << endl;
	cout << "��ͥסַ��" << family_location << endl;
	cout << "�ܳɼ���" << total_mark << endl;
}

void Student::set() {
	cout << "������" << endl;
	cin >> name;
	cout << "�Ա�" << endl;
	cin >> sex;
	cout << "��ͥסַ��" << endl;
	cin >> family_location;
	cout << "�ܳɼ���" << endl;
	cin >> total_mark;
}