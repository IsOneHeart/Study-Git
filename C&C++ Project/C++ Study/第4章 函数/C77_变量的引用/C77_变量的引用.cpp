//使用变量的引用排序两个数

#include <iostream>
using namespace std;

void sort(int& a, int& b) {
    if (a > b) {
        int temp = a;
        a = b;
        b = temp;
    }
}

int main()
{
    int a = 21, b = 18;
    sort(a, b);
    cout << a << ' ' << b << endl;
    return 0;
}

