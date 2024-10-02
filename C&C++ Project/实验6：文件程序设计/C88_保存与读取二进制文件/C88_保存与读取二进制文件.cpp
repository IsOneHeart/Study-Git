/*
从键盘输入若干个学生数据（包括学号、姓名和成绩）保存到二进制文件 a.dat
（以负数成绩表示输入结束），然后再从该文件中读出并显示。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    long long num;
    char name[15];
    float mark;
    FILE* fp;
    if (fopen_s(&fp, "a.dat", "ab+") != 0) {
        printf("文件打开失败！");
        return 0;
    }
    printf("请输入学生数据：（以负数成绩表示输入结束）\n");
    int i = 1;
    while (1) {
        printf("第%d个学生：\n", i);
        i++;
        printf("成绩：");
        scanf("%f", &mark);
        if (mark < 0)
            break;
        printf("学号：");
        scanf("%lld", &num);
        printf("姓名：");
        scanf("%s", name);
        fprintf(fp, "%lld %s %.1f\n", num, name, mark);
        fflush(fp); // 刷新文件流，确保数据被写入文件
    }
    fclose(fp); // 关闭文件

    if (fopen_s(&fp, "a.dat", "rb") != 0) {
        printf("文件打开失败！");
        return 0;
    }

    printf("文件数据：\n");
    while (fscanf(fp, "%lld %s %f", &num, name, &mark) != EOF) {
        printf("%lld %s %.1f\n", num, name, mark);
    }

    fclose(fp);
    return 0;
}