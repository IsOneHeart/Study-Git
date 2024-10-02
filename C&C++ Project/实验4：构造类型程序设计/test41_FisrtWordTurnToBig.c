/*输入一行字符串，要求将每个单词中的第一个字母改成大写字母（如果已经是大写则不变）。
例如，输入I am a student，输出I Am A Student。*/
#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 128
#include <stdio.h>
void main() {
	printf("输入一行字符串：");
	char strings[MaxSize];
	gets(strings);
	for (int i = 0;i < MaxSize;i++) {
		if (strings[i] == ' ' || strings[i] == ','|| strings[i] == '.'|| strings[i] == '?'|| strings[i] == '!') {
			if (strings[i + 1] >= 'a' && strings[i + 1] <= 'z') 
				strings[i + 1] -= 32;
		}
		if (strings[i] == '\n')
			break;
	}
	puts(strings);
}