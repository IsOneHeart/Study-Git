#include <stdio.h>

int main() {
	enum weekday { 周一, 周二, 周三, 周四, 周五, 周六, 周日 }day;
	day = 周日;
	printf("今天是一周中的第%d天", day+1);
	return 0;
}