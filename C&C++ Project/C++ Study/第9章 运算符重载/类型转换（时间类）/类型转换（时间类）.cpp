#include <iostream>
using namespace std;

class Time {
private:
    int hour;
    int minute;
    int sec;
public:
    Time(int h, int m, int s) :hour(h), minute(m), sec(s){}
    void show() {
        cout << hour << ":" << minute << ":" << sec << endl;
    }
    friend Time operator+(int s, const Time& t) {
        Time result = t;
        result.sec += s;
        again:
        if (result.sec >= 60) {
            result.sec -= 60;
            ++result.minute;
            goto again;
        }
        if (result.minute >= 60) {
            result.minute -= 60;
            ++result.hour;
            goto again;
        }
        return result;
    }
    friend Time operator+(const Time& t, int s) {
        Time result = t;
        result.sec += s;
        again:
        if (result.sec >= 60) {
            result.sec -= 60;
            ++result.minute;
            goto again;
        }
        if (result.minute >= 60) {
            result.minute -= 60;
            ++result.hour;
            goto again;
        }
        return result;
    }
};

int main(){
    Time time(20, 41, 56);
    time = 5 + time;
    time.show();
    time = time + 120;
    time.show();
}