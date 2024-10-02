#include <iostream>
using namespace std;

class Date {
private:
    int year;
    int month;
    int day;
    bool isleap;
public:
    Date(int y, int m, int d) : year(y), month(m), day(d) {
        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            isleap = true;
        }
        else {
            isleap = false;
        }
    }
    Date operator++();
    Date operator++(int);
    void show() {
        cout << year << "." << month << "." << day;
    }
};

Date Date::operator++() {
    if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
        isleap = true;
    }
    else {
        isleap = false;
    }
    day++;
    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
        if (day > 31) {
            day = 1;
            month++;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11) {
        if (day > 30) {
            day = 1;
            month++;
        }
    }
    else if (month == 2 && isleap) {
        if (day > 29) {
            day = 1;
            month++;
        }
    }
    else if (month == 2 && !isleap) {
        if (day > 28) {
            day = 1;
            month++;
        }
    }
    if (month > 12) {
        month = 1;
        year++;
    }
    return *this;
}

Date Date::operator++(int) {
    Date temp(*this);
    ++(*this);
    return temp;
}

int main() {
    Date date(2024, 1, 1);
    for (int i = 1; i <= 365; i++) {
        date++;
        date.show();
        cout << " ";
    }
    cout << "\n***************" << endl;
    for (int i = 1; i <= 365; i++) {
        ++date;
        date.show();
        cout << " ";
    }
    return 0;
}
