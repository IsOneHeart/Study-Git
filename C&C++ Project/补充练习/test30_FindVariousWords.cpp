#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main() {
	char word[80];
	int i = 0;
	static int count[5];
	printf("请输入字符串：");
	while ((word[i] = getchar())!= '\n') 
		i++;
	word[i] = '\0';
	for (i = 0;word[i] != '\0';i++) {
		if (word[i] > '0' && word[i] < '9')
			count[3]++;
		else if (word[i] > 'A' && word[i] < 'Z')
			count[1]++;
		else if (word[i] > 'a' && word[i] < 'z')
			count[2]++;
		else if (word[i] == ' ')
			count[4]++;
		else count[0]++;
	}
	printf("英文大写字母个数：%d\n", count[1]);
	printf("英文小写字母个数：%d\n", count[2]);
	printf("数字个数：%d\n", count[3]);
	printf("空格个数：%d\n", count[4]);
	printf("其他字符个数：%d\n", count[0]);
	return 0;
}