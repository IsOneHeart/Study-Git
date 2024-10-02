/*
已知一个数据文件a.txt中保存了若干个学生的计算机等级考试成绩，
包括学号、姓名和成绩。请编程读出显示文件内容并分类统计各等级人数，最后显示统计结果。
成绩等级规则：大于等于90-A，大于等于80-B，大于等于70-C，大于等于60-D，60以下-E。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct Student {
    long long num;
    char name[15];
    float mark;
    char grade;
} Student;

int main() {
    FILE* fp;
    Student* head = NULL;
    head = (Student*)malloc(sizeof(Student));
    if (head == NULL) {
        printf("内存块分配失败！");
        return 0;
    }
    if (fopen_s(&fp, "a.txt", "r") != 0) {
        printf("文件打开失败！");
        return 0;
    }

    char buffer[50];
    Student* p = head;
    int i = 0;
    int count[5] = { 0, 0, 0, 0, 0 };

    while (fgets(buffer, 50, fp) != NULL) {
        if (i > 0) {
            Student* new_head = (Student*)realloc(head, (i + 1) * sizeof(Student));
            if (new_head == NULL) {
                printf("内存块分配失败！");
                return 0;
            }
            head = new_head;
            p = head + i;
        }

        sscanf(buffer, "%lld %s %f %c", &(p->num), p->name, &(p->mark), &(p->grade));

        if (p->mark > 100)
            p->grade = '?';
        else if (p->mark >= 90) {
            p->grade = 'A';
            count[0]++;
        }
        else if (p->mark >= 80) {
            p->grade = 'B';
            count[1]++;
        }
        else if (p->mark >= 70) {
            p->grade = 'C';
            count[2]++;
        }
        else if (p->mark >= 60) {
            p->grade = 'D';
            count[3]++;
        }
        else {
            p->grade = 'E';
            count[4]++;
        }

        i++;
        p++;
    }

    fclose(fp);

    for (int j = 0; j < i; j++) {
        printf("%lld %s %.1f %c\n", head[j].num, head[j].name, head[j].mark, head[j].grade);
    }

    printf("A等级%d人，B等级%d人，C等级%d人，D等级%d人，E等级%d人\n", count[0], count[1], count[2], count[3], count[4]);

    free(head);

    return 0;
}