#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fp;
	char ch[sizeof("ѧ�� ���� ���� �Ա�\n")];

	if ((fp = fopen("student.dat","r")) == NULL) {
		printf("�ļ���ʧ�ܣ�");
		exit(0);
	}

	for (int i = 0; (fgets(ch, sizeof("ѧ�� ���� ���� �Ա�\n"), fp)) != NULL; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) {
			printf("%s", ch);
		}
	}

	if (fclose(fp)) {
		printf("�ļ����������رգ�");
		exit(0);
	}
	return 0;
}