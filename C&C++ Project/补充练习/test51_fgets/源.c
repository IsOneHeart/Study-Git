#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fp;
	char ch[2];

	if ((fp = fopen("filea.txt", "r")) == NULL) {
		printf("���ܴ��ļ���");
		exit(0);
	}

	while ((fgets(ch, 2, fp)) != NULL) {
		printf("%s", ch);
	}

	if (fclose(fp)) {
		printf("���������ر��ļ���");
		exit(0);
	}
	return 0;
}