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
	cout << "�����빤����Ϣ��\n" << "������" << endl;
	cin >> name;
	cout << "�Ա�" << endl;
	cin >> sex;
	cout << "���䣺" << endl;
	cin >> age;
	cout << "��ͥסַ��" << endl;
	cin >> family_position;
	cout << "���ʣ�" << endl;
	cin >> salary;
}

void Worker::showWorker() {
	cout << "������Ϣ��\n" << "������" << name << endl;
	cout << "�Ա�" << sex << endl;
	cout << "���䣺" << age << endl;
	cout << "��ͥסַ��" << family_position << endl;
	cout << "���ʣ�" << salary<< endl;
}