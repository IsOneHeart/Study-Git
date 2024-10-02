#include <stdio.h>

// 定义周名称的枚举类型
enum weekname {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

// 计算某年某月某日是星期几
int calculateWeekday(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int century = year / 100;
    year %= 100;

    int weekday = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + century / 4 - 2 * century) % 7;

    // 处理负数情况
    if (weekday < 0) {
        weekday += 7;
    }

    // 添加偏移量以匹配枚举
    weekday = (weekday + 6) % 7;

    return weekday;
}

int main() {
    int year, month, day;

    printf("年份：");
    scanf_s("%d", &year);

    printf("月份：");
    scanf_s("%d", &month);

    printf("日期：");
    scanf_s("%d", &day);

    // 计算星期名称
    int weekday = calculateWeekday(year, month, day);

    // 输出当天对应的星期名称
    switch (weekday) {
    case Sunday:
        printf("Sunday\n");
        break;
    case Monday:
        printf("Monday\n");
        break;
    case Tuesday:
        printf("Tuesday\n");
        break;
    case Wednesday:
        printf("Wednesday\n");
        break;
    case Thursday:
        printf("Thursday\n");
        break;
    case Friday:
        printf("Friday\n");
        break;
    case Saturday:
        printf("Saturday\n");
        break;
    default:
        printf("无效的日期\n");
        break;
    }

    return 0;
}