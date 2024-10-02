#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    cout << setiosflags(ios::left); // 设置左对齐
    cout.width(12); // 宽度为12
    cout << 18 << endl;// 宽度为12
    cout.unsetf(ios::left);// 取消左对齐
    int n;
    cout << "请输入整数：";
    cin >> n;
    cout << "八进制：" << oct << n << endl;
    cout << "十进制：" << dec << n << endl;
    cout << "十六进制：" << hex << n << endl;
    cout << "请输入浮点数：";
    float f;
    cin >> f;
    cout.precision(6); // 保留6位小数
    cout << "保留6位小数：" << f << endl;
    cout.setf(ios::fixed); // 指定用定点形式输出
    cout << "指定用定点形式输出：" << f << endl;
    cout.unsetf(ios::fixed);
    cout.setf(ios::scientific);
    cout << "科学计数法：" << f << endl;
    cout.unsetf(ios::scientific);
    return 0;
}