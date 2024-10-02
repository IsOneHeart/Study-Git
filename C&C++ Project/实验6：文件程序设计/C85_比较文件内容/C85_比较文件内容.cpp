/*
编写一个程序，比较两个文本文件a1.txt和a2.txt的内容是否相同，
若相同则输出“YES”，否则输出“NO”，并输出两个文件内容首次不同的行号和字符位置。
*/
#include <stdio.h>

int main() {
    FILE* fp1, * fp2;
    if (fopen_s(&fp1, "a1.txt", "r") != 0) {
        printf("文件a1.txt打开失败！");
        return 0;
    }
    if (fopen_s(&fp2, "a2.txt", "r") != 0) {
        printf("文件a2.txt打开失败！");
        return 0;
    }

    int flag = 1;
    char c1, c2;
    int countI = 1, countJ = 0;
    while ((c1 = fgetc(fp1)) != EOF && (c2 = fgetc(fp2)) != EOF) {
        countJ++;
        if (c1 != c2) {
            printf("NO\n两个文件内容首次不同的行号为%d，字符位置为%d\n", countI, countJ);
            flag = 0;
            break;
        }
        if (c1 == '\n') {
            countI++;
            countJ = 0;
        }
    }

    if (flag) {
        if (fgetc(fp1) != EOF || fgetc(fp2) != EOF) {
            printf("NO\n两个文件内容长度不同\n");
        }
        else {
            printf("YES\n两个文件内容相同\n");
        }
    }

    fclose(fp1);
    fclose(fp2);
    return 0;
}