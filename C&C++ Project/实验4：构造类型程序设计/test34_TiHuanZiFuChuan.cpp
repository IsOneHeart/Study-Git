/*连续输入一批以回车结束的字符串（少于80个字符），将字符串中的大写字母用下面
列出的对应大写字母替换，其余字符不变，输出替换后的字符串。(A65,Z90)
原字母   对应字母			  原字母   对应字母
A ──→ Z 					  X ──→ C
B ──→ Y          ……	  Y ──→ B
C ──→ X 					  Z ──→ A
D ──→ W */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 80
int main() {
	int w = MaxSize, i = 0;
	char words[MaxSize];
	printf("请连续输入一批以回车结束的字符串（少于%d个字符）：", w);
	while ((words[i] = getchar()) != '\n')
		i++;
	words[i] = '\0';
	printf("替换后的字符串：");
	for (int j = 0;words[j] != '\0';j++) {
		if (words[j] >= 65 && words[j] <= 90)
			words[j] = -words[j] + 90 + 65;
		printf("%c", words[j]);
	}
	return 0;
}