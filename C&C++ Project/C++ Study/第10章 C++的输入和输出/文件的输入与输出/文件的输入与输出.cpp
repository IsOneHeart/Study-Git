#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
using namespace std;

int main(){
    fstream file;
    //file.open("file.dat", ios::trunc|ios::out);
    string name;
    string sex;
    int age;
    string address;
    float score;
    /*
    for (int i = 1;i <= 2;i++) {
        cout << "请输入第" << i << "位学生的信息" << endl;
        cout << "姓名：";
        cin >> name;
        cout << "性别：";
        cin >> sex;
        cout << "年龄：";
        cin >> age;
        cout << "地址：";
        cin >> address;
        cout << "成绩：";
        cin >> score;
        file << name << " " << sex << " " << age << " " << address << " " << score << endl;
    }
    file.close();
    */
    file.open("file.dat", ios::in);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            // 使用stringstream分割字符串  
            stringstream ss(line);
            if (ss >> name >> sex >> age >> address >> score) {
                cout << name << " " << sex << " " << age << " " << address << " " << score << endl;
            }
            else {
                cout << "解析行时出错" << endl;
            }
        }
    }
    else {
        cout << "无法打开文件以进行读取" << endl;
    }
}