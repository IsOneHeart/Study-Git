#include <stdio.h>

// ���������Ƶ�ö������
enum weekname {
    Sunday,
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday
};

// ����ĳ��ĳ��ĳ�������ڼ�
int calculateWeekday(int year, int month, int day) {
    if (month < 3) {
        month += 12;
        year--;
    }

    int century = year / 100;
    year %= 100;

    int weekday = (day + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400 + century / 4 - 2 * century) % 7;

    // ���������
    if (weekday < 0) {
        weekday += 7;
    }

    // ���ƫ������ƥ��ö��
    weekday = (weekday + 6) % 7;

    return weekday;
}

int main() {
    int year, month, day;

    printf("��ݣ�");
    scanf_s("%d", &year);

    printf("�·ݣ�");
    scanf_s("%d", &month);

    printf("���ڣ�");
    scanf_s("%d", &day);

    // ������������
    int weekday = calculateWeekday(year, month, day);

    // ��������Ӧ����������
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
        printf("��Ч������\n");
        break;
    }

    return 0;
}