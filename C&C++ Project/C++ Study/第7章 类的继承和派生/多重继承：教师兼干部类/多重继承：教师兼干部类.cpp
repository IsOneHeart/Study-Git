#include <iostream>
using namespace std;

class Teacher {
protected:
    string name;
    int age;
    string sex;
    string location;
    long long phone_num;
    string professional_title;
public:
    Teacher(string n, int a, string s, string l, long long pn, string pt) {
        name = n;
        age = a;
        sex = s;
        location = l;
        phone_num = pn;
        professional_title = pt;
    }
    virtual void display() {
        cout << "姓名：" << name << endl;
        cout << "年龄：" << age << endl;
        cout << "性别：" << sex << endl;
        cout << "地址：" << location << endl;
        cout << "电话：" << phone_num << endl;
        cout << "职称：" << professional_title << endl;
    }
};

class Cadre {
protected:
    string name;
    int age;
    string sex;
    string location;
    long long phone_num;
    string post;
public:
    Cadre(string n, int a, string s, string l, long long pn, string p) {
        name = n;
        age = a;
        sex = s;
        location = l;
        phone_num = pn;
        post = p;
    }
    virtual void display() {
        cout << "姓名：" << name << endl;
        cout << "年龄：" << age << endl;
        cout << "性别：" << sex << endl;
        cout << "地址：" << location << endl;
        cout << "电话：" << phone_num << endl;
        cout << "职务：" << post << endl;
    }
};

class TeacherAndCadre :protected Teacher, protected Cadre {
private:
    float slary;
public:
    TeacherAndCadre(string n, int a, string s, string l, long long pn, string pt, string p, float sl) :Teacher(n, a, s, l, pn, pt), Cadre(n, a, s, l, pn, p), slary(sl) {}
    void show() {
        Teacher::display();
        cout << "职务：" << post << endl;
        cout << "工资：" << slary << endl;
    }
};

int main()
{
    TeacherAndCadre tc("张三", 21, "男", "广东省XX市XX区XX街道XX", 13500000000, "C语言教授", "党支部书记", 20000);
    tc.show();
    return 0;
}
