/*
已知文件 a.txt 存储若干文本数据，编程统计 a.txt 文件的行数、
大写字母个数、小写字母个数、数字字符个数及其他字符的个数。要求如下：
① 定义 countFile()函数：统计文本文件的行数、大写字母个数、
小写字母个数、数字字符个数及其他字符的个数。
② 定义 main()函数：打开 a.txt 文件，调用 countFile()函数统计文本文件的行数、
大写字母个数、小写字母个数、数字字符个数及其他字符的个数，输出统计结果。
*/
#include <stdio.h>

void countFile(FILE* fp) {
	int f, count[5] = { 0,0,0,0,0 };
	while (!feof(fp)) {
		f = fgetc(fp);
		if (f == '\n')
			count[0]++;
		else if (f >= 'A' && f <= 'Z')
			count[1]++;
		else if (f >= 'a' && f <= 'z')
			count[2]++;
		else if (f >= '0' && f <= '9')
			count[3]++;
		else
			count[4]++;
	}
	count[0]++;//最后一行
	printf("文本文件的行数：%d\n大写字母个数：%d\n小写字母个数：%d\n数字字符个数：%d\n其他字符的个数：%d\n",
		count[0], count[1], count[2], count[3], count[4]);
}

int main() {
	FILE* fp;
	if (fopen_s(&fp, "a.txt", "r") != 0) {
		printf("打开文件失败！");
		return 0;
	}
	countFile(fp);
	fclose(fp);
	return 1;
}