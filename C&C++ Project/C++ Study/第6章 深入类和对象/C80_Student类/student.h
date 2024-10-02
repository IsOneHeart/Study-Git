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
	//Student(string n = "张三", string s = "男", string fl = "XX省XX市XX区XX", float tm = 0) :name(n), sex(s), family_location(fl), total_mark(tm) {};
	~Student();
	void show();
	void set();
};

Student::Student() {
	name = "张三";
	sex = "男";
	family_location = "XX省XX市XX区XX";
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
	cout << "姓名：" << name << endl;
	cout << "性别：" << sex << endl;
	cout << "家庭住址：" << family_location << endl;
	cout << "总成绩：" << total_mark << endl;
}

void Student::set() {
	cout << "姓名：" << endl;
	cin >> name;
	cout << "性别：" << endl;
	cin >> sex;
	cout << "家庭住址：" << endl;
	cin >> family_location;
	cout << "总成绩：" << endl;
	cin >> total_mark;
}