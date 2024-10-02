#include <iostream>
using namespace std;

class Student {
public:
    virtual void Sports_Scoring_Standard() = 0;
    /*
    这段代码是一个虚函数的声明。在C++中，使用virtual关键字来声明一个虚函数。
    虚函数是一种特殊的成员函数，它可以在派生类中被重写。在这个声明中，
    函数名为Sports_Scoring_Standard，返回类型为void，没有参数。
    = 0表示这个虚函数是一个纯虚函数。纯虚函数是没有实现的虚函数，
    它只是作为接口存在，派生类必须实现它。在这个声明中，纯虚函数
    Sports_Scoring_Standard没有具体的实现，所以任何派生类都必须提供自己的实现。
    */
};

class Boy :public Student {
public:
    void Sports_Scoring_Standard() {
        cout << "1000米长跑时长不超过4分30秒，一分钟引体向上大于10个。" << endl;
    }
};

class Girl :public Student {
public:
    void Sports_Scoring_Standard() {
        cout << "800米长跑时长不超过4分30秒，一分钟仰卧起坐多于24个。" << endl;
    }
};

int main(){
    Boy b;
    Girl g;
    cout << "男生评分标准：" << endl;
    b.Sports_Scoring_Standard();
    cout << "女生评分标准：" << endl;
    g.Sports_Scoring_Standard();
}
