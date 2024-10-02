#include <iostream>
#include <chrono>
#include <ctime>
using namespace std;

#include <iostream>
#include <chrono>
#include <ctime>

int main() {
    // 获取当前时间点
    auto now = chrono::system_clock::now();

    // 将当前时间点转换为时间戳
    time_t now_c = chrono::system_clock::to_time_t(now);

    // 创建一个存储本地时间的结构
    struct tm timeinfo;
    localtime_s(&timeinfo, &now_c);

    // 使用asctime_s函数将时间结构转换为本地时间的字符串表示
    char buffer[26];
    asctime_s(buffer, sizeof(buffer), &timeinfo);

    cout << "当前时间: " << buffer;

    return 0;
}
