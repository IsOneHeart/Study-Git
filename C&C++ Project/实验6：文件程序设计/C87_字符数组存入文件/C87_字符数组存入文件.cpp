//从键盘输入10个英文单词到二维字符数组a并保存到文本文件a.txt中（单词间以空格分隔），
// 然后再从该文件中读出所有单词并显示到屏幕。
#include <stdio.h>

int main() {
    char words[10][20]; // 假设每个单词最大长度为20
    printf("请输入10个英文单词，用空格分隔：\n");

    scanf_s("%s %s %s %s %s %s %s %s %s %s",
        words[0], sizeof(words[0]),
        words[1], sizeof(words[1]),
        words[2], sizeof(words[2]),
        words[3], sizeof(words[3]),
        words[4], sizeof(words[4]),
        words[5], sizeof(words[5]),
        words[6], sizeof(words[6]),
        words[7], sizeof(words[7]),
        words[8], sizeof(words[8]),
        words[9], sizeof(words[9]));

    FILE * fp;
    if (fopen_s(&fp, "a.txt", "w") != 0) {
        printf("文件打开失败！\n");
        return 0;
    }
    for (int i = 0; i < 10; i++) {
        fprintf(fp, "%s ", words[i]); // 写入单词并用空格分隔
    }
    fclose(fp);

    if (fopen_s(&fp, "a.txt", "r") != 0) {
        printf("文件打开失败！\n");
        return 0;
    }
    printf("文件内单词：\n");
    char buffer[10 * 20];
    while (fgets(buffer, 10 * 20, fp) != NULL) {
        printf("%s", buffer);
    }
    fclose(fp);
    return 0;
}