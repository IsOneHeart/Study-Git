#include <iostream>  
using namespace std;

int main()
{
    int i = 20; // 开始字符是ASCII值为20的字符  
    int count = 0; // 计数器，用于跟踪已经打印的字符数量  

    // 循环直到ASCII值127的字符  
    while (i <= 127) {
        cout << (char)i << " ";
        count++; // 增加计数器  

        // 如果已经打印了10个字符，则换行并重置计数器  
        if (count == 10) {
            cout << endl;
            count = 0; // 重置计数器  
        }

        // 递增i的ASCII值  
        i++;
    }

    // 如果最后一行没有打印满10个字符，也换行（可选）  
    if (count > 0) {
        cout << endl;
    }

    return 0;
}