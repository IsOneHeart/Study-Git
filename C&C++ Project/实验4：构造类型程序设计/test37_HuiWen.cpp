#include <stdio.h>
#define MaxSize 64
void main() {
	int  i = 0;
	char words[MaxSize];
	printf("�������ַ�����");
	while ((words[i] = getchar()) != '\n' && i < MaxSize - 1)
		i++;
	words[i] = '\0';
	int isHY = 1, j = 0;
	while (j < i / 2) {
		if (words[j] != words[i - j - 1]) {
			isHY = 0;
			break;
		}
		j++;
	}
	(isHY == 1) ? printf("�ǻ���") : printf("���ǻ���");
}