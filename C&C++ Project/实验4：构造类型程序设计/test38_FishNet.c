/*某人从1900年1月1日起开始“三天打鱼，两天晒网”的工作，试问此人某日期的工作状态（打鱼或晒网）。
要求定义日期结构体Date(含年、月、日)和函数FishNet，该函数判断某日期的工作状态，若为打鱼，则返回1，否则返回0。
在主函数中输入某个日期，调用FishNet函数返回工作状态，最后输出该日期所对应的工作状态。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
struct Date {
	int year;
	int month;
	int day;
}date0;

int SumDay(struct Date d) {
	int dSum = 0;
	int mDays[] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	for (int y = 1900;y < d.year;y++) {//判断平闰年，并累加日数(除本年）
		if ((y % 4 == 0 && y % 100 != 0) || (y % 400 == 0))
			dSum += 366;
		else
			dSum += 365;
	}
	for (int m = 1;m < d.month;m++) {
		dSum += mDays[m];
	}
	dSum += d.day;
	if ((d.year % 4 == 0 && d.year % 100 != 0) || (d.year % 400 == 0) || d.month > 2)
		++dSum;//如果是闰年，且是二月后，加一天
	return dSum;
}

int FishNet(struct Date d) {
	int ForN = SumDay(d) % 5;
	if (ForN <= 3)
		return 1;
	return 0;
}

void main() {
	printf("请输入日期：\n");
	printf("年：");
	scanf("%d", &date0.year);
	printf("月：");
	scanf("%d", &date0.month);
	printf("日：");
	scanf("%d", &date0.day);
	int isFish = FishNet(date0);
	if (isFish)//即 if ( ifFish = 1 )
		printf("该日期某人在打鱼");
	else
		printf("该日期某人在晒网");
}