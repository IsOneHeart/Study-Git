//使用函数模板实现不同数据类型的排序

#include <iostream>
using namespace std;

template <typename T>
void sort(T& x1, T& x2, T& x3) {
    T tempmax = x1 > x2 ? x1 : x2;
    T tempmin = x1 < x2 ? x1 : x2;

    if (x3 > tempmax) {
        cout << tempmin << " " << tempmax << " " << x3 << endl;
    }
    else if (x3 < tempmin) {
        cout << x3 << " " << tempmin << " " << tempmax << endl;
    }
    else {
        cout << tempmin << " " << x3 << " " << tempmax << endl;
    }
}

int main() {
    int a = 5, b = 3, c = 7;
    sort(a, b, c);

    return 0;
}