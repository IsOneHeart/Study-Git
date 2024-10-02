#include <iostream>
#include <cmath>
using namespace std;

int main(){
    cout << "输入一元二次方程组Ax^2+Bx+C=0的各个系数：" << endl;
    double A, B, C, x1, x2;
    cout << "A=";
    cin >> A;
    cout << "B=";
    cin >> B;
    cout << "C=";
    cin >> C;
    if (A == 0) {
        try {
            if (B == 0)
                throw B;
            x1 = -C / B;
            x2 = -C / B;
            cout << "x1=" << x1 << "，x2=" << x2 << endl;
        }
        catch (double) {
            cout << "无解(Warning1)！" << endl;
        }
    }
    else {
        try {
            if (B * B - 4 * A * C < 0)
                throw B* B - 4 * A * C;
            x1 = (-B + sqrt(B * B - 4 * A * C)) / 2 * A;
            x2 = (-B - sqrt(B * B - 4 * A * C)) / 2 * A;
            cout << "x1=" << x1 << "，x2=" << x2 << endl;
        }
        catch (double) {
            cout << "无解(Warning2)！" << endl;
        }
    }
    return 0;
}