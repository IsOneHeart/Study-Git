/*��д����strmcpy(s,t,m)���ú������ַ���t�д�m���ַ���ʼ��ȫ���ַ����Ƶ��ַ���s��
���������������ַ���t�Ϳ�ʼλ��m������strmcpy(s,t,m)������Ȼ������ַ���s��
���磬�����ַ���liwangzhajinxiao�Ϳ�ʼλ��2�����wangzhajinxiao��*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 64
char* strmcpy(char s[MaxSize], char t[MaxSize], int m) {
	char* p = s;//ָ���ַ���s��ָ��
	int k = m;
	while (t[k] != '\0') {
		*p = t[k];
		p++;
		k++;
	}
	*p = '\0';//��ĩβ���\0��ʾ�ַ�������
	return s;
}
int main() {
	printf("�������ַ���t��");
	static char s[MaxSize];
	char t[MaxSize];
	int m, i = 0;
	while ((t[i] = getchar()) != '\n')
		i++;
	t[i] = '\0';
	printf("�����븴���ַ����Ŀ�ʼλ��m��");
	scanf("%d", &m);
	char* result = strmcpy(s, t, m);
	printf("���ƺ���ַ���sΪ��%s\n", result);
	return 0;
}