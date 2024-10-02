#include <iostream>  
#include <cmath>  
#include <stdexcept> // 引入标准异常库  
using namespace std;

// 自定义异常类  
class NoRealRootsException : public std::runtime_error {
public:
    NoRealRootsException(const std::string& what_arg)
        : std::runtime_error(what_arg) {}
};

int calculateRoots() {
    using namespace std;

    cout << "输入一元二次方程组Ax^2+Bx+C=0的各个系数：" << endl;
    double A, B, C, x1, x2;
    cin >> A >> B >> C;

    if (A == 0) {
        if (B == 0) {
            cout << "无解(Warning)! 因为A和B都为0" << endl;
            return 1; // 非正常退出，表示输入错误  
        }
        else {
            x1 = -C / B;
            cout << "x1=" << x1 << "（因为A为0，只有一个解）" << endl;
            return 0; // 正常退出  
        }
    }

    double discriminant = B * B - 4 * A * C;
    if (discriminant < 0) {
        // 抛出自定义异常  
        throw NoRealRootsException("没有实根(Warning)！因为判别式小于0");
    }
    else if (discriminant == 0) {
        x1 = x2 = -B / (2 * A);
        cout << "x1=" << x1 << "，x2=" << x2 << endl;
    }
    else {
        x1 = (-B + sqrt(discriminant)) / (2 * A);
        x2 = (-B - sqrt(discriminant)) / (2 * A);
        cout << "x1=" << x1 << "，x2=" << x2 << endl;
    }

    return 0;
}

int main() {
    try {
        return calculateRoots(); // 调用calculateRoots函数来计算根  
    }
    catch (const NoRealRootsException& e) {
        cerr << e.what() << endl; // 输出没有实根的异常信息  
        return 1; // 非正常退出，表示没有实根  
    }
    catch (const std::exception& e) {
        cerr << "捕获到未知异常: " << e.what() << endl;
        return 2; // 非正常退出，表示发生未知异常  
    }
}