#pragma once
#include <iostream>
#include <string>
using namespace std;

class Worker {
private:
	string name;
	string sex;
	int age;
	string family_position;
	float salary;
public:
	void setWorker();
	void showWorker();
};

void Worker::setWorker() {
	cout << "请输入工人信息：\n" << "姓名：" << endl;
	cin >> name;
	cout << "性别：" << endl;
	cin >> sex;
	cout << "年龄：" << endl;
	cin >> age;
	cout << "家庭住址：" << endl;
	cin >> family_position;
	cout << "工资：" << endl;
	cin >> salary;
}

void Worker::showWorker() {
	cout << "工人信息：\n" << "姓名：" << name << endl;
	cout << "性别：" << sex << endl;
	cout << "年龄：" << age << endl;
	cout << "家庭住址：" << family_position << endl;
	cout << "工资：" << salary<< endl;
}