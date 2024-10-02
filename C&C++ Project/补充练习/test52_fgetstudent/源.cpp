#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	FILE* fp;
	char ch[sizeof("学号 姓名 年龄 性别\n")];

	if ((fp = fopen("student.dat","r")) == NULL) {
		printf("文件打开失败！");
		exit(0);
	}

	for (int i = 0; (fgets(ch, sizeof("学号 姓名 年龄 性别\n"), fp)) != NULL; i++) {
		if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9) {
			printf("%s", ch);
		}
	}

	if (fclose(fp)) {
		printf("文件不能正常关闭！");
		exit(0);
	}
	return 0;
}