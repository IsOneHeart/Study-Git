/*��������һ���Իس��������ַ���������80���ַ��������ַ����еĴ�д��ĸ������
�г��Ķ�Ӧ��д��ĸ�滻�������ַ����䣬����滻����ַ�����(A65,Z90)
ԭ��ĸ   ��Ӧ��ĸ			  ԭ��ĸ   ��Ӧ��ĸ
A ������ Z 					  X ������ C
B ������ Y          ����	  Y ������ B
C ������ X 					  Z ������ A
D ������ W */
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MaxSize 80
int main() {
	int w = MaxSize, i = 0;
	char words[MaxSize];
	printf("����������һ���Իس��������ַ���������%d���ַ�����", w);
	while ((words[i] = getchar()) != '\n')
		i++;
	words[i] = '\0';
	printf("�滻����ַ�����");
	for (int j = 0;words[j] != '\0';j++) {
		if (words[j] >= 65 && words[j] <= 90)
			words[j] = -words[j] + 90 + 65;
		printf("%c", words[j]);
	}
	return 0;
}