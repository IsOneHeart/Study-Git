/*ĳ�˴�1900��1��1����ʼ��������㣬����ɹ�����Ĺ��������ʴ���ĳ���ڵĹ���״̬�������ɹ������
Ҫ�������ڽṹ��Date(���ꡢ�¡���)�ͺ���FishNet���ú����ж�ĳ���ڵĹ���״̬����Ϊ���㣬�򷵻�1�����򷵻�0��
��������������ĳ�����ڣ�����FishNet�������ع���״̬������������������Ӧ�Ĺ���״̬��*/
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
	for (int y = 1900;y < d.year;y++) {//�ж�ƽ���꣬���ۼ�����(�����꣩
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
		++dSum;//��������꣬���Ƕ��º󣬼�һ��
	return dSum;
}

int FishNet(struct Date d) {
	int ForN = SumDay(d) % 5;
	if (ForN <= 3)
		return 1;
	return 0;
}

void main() {
	printf("���������ڣ�\n");
	printf("�꣺");
	scanf("%d", &date0.year);
	printf("�£�");
	scanf("%d", &date0.month);
	printf("�գ�");
	scanf("%d", &date0.day);
	int isFish = FishNet(date0);
	if (isFish)//�� if ( ifFish = 1 )
		printf("������ĳ���ڴ���");
	else
		printf("������ĳ����ɹ��");
}