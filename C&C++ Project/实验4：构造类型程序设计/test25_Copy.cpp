/*编写函数strmcpy(s,t,m)，该函数将字符串t中从m个字符开始的全部字符复制到字符串s。
在主程序中输入字符串t和开始位置m，调用strmcpy(s,t,m)函数，然后输出字符串s。
例如，输入字符串liwangzhajinxiao和开始位置2，输出wangzhajinxiao。*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 64
char* strmcpy(char s[MaxSize], char t[MaxSize], int m) {
	char* p = s;//指向字符串s的指针
	int k = m;
	while (t[k] != '\0') {
		*p = t[k];
		p++;
		k++;
	}
	*p = '\0';//在末尾添加\0表示字符串结束
	return s;
}
int main() {
	printf("请输入字符串t：");
	static char s[MaxSize];
	char t[MaxSize];
	int m, i = 0;
	while ((t[i] = getchar()) != '\n')
		i++;
	t[i] = '\0';
	printf("请输入复制字符串的开始位置m：");
	scanf("%d", &m);
	char* result = strmcpy(s, t, m);
	printf("复制后的字符串s为：%s\n", result);
	return 0;
}