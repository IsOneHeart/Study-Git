/*����һ���ַ�����Ҫ��ÿ�������еĵ�һ����ĸ�ĳɴ�д��ĸ������Ѿ��Ǵ�д�򲻱䣩��
���磬����I am a student�����I Am A Student��*/
#define _CRT_SECURE_NO_WARNINGS
#define MaxSize 128
#include <stdio.h>
void main() {
	printf("����һ���ַ�����");
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