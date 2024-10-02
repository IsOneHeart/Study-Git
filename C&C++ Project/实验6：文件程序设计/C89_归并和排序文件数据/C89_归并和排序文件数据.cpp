/*
两个非空二进制文件 a1.dat 和 a2.dat，分别保存若干学生数据（包括学号、姓名和成绩），且按成绩升序排列。
编写程序，把 a1.dat 和 a2.dat 两个文件归并到 a3.dat 文件，使得 a3.dat 文件中的学生数据也按成绩升序排列。
学生结构体定义与功能要求如下：
struct Student{		
long num;		
char name[20];	
int score;			
};
① 定义 mergeFile()函数：将两个二进制文件归并成一个按成绩升序排列的新文件。
② 定义 main()函数：先打开二进制文件 a1.dat、a2.dat、a3.dat，再调用 mergeFile()函数将 a1.dat、a2.dat 
两个文件归并到按成绩升序排列的 a3.dat 文件，最后输出 a3.dat 文件内容。
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  

typedef struct Student {
    long num;
    char name[20];
    int score;
} Student;

// 比较函数，用于qsort  
int compare(const void* a, const void* b) {
    Student* studentA = (Student*)a;
    Student* studentB = (Student*)b;
    return studentA->score - studentB->score;
}

int mergeFile(FILE* fp1, FILE* fp2, FILE* fp3) {
    Student* students = NULL;
    size_t count = 0;
    size_t capacity = 0;
    char buffer[50];

    // 读取第一个文件  
    while (fgets(buffer, sizeof(buffer), fp1)) {
        if (count == capacity) {
            capacity = (capacity == 0) ? 1 : capacity * 2;
            students = (Student*)realloc(students, capacity * sizeof(Student));
            if (!students) {
                perror("内存分配失败");
                return 0;
            }
        }
        sscanf(buffer, "%ld %19s %d", &students[count].num, students[count].name, &students[count].score);
        count++;
    }

    // 读取第二个文件  
    while (fgets(buffer, sizeof(buffer), fp2)) {
        if (count == capacity) {
            capacity = capacity * 2;
            students = (Student*)realloc(students, capacity * sizeof(Student));
            if (!students) {
                perror("内存分配失败");
                return 0;
            }
        }
        sscanf(buffer, "%ld %19s %d", &students[count].num, students[count].name, &students[count].score);
        count++;
    }

    // 对学生数据进行排序
    // void qsort(void *base, size_t nmemb, size_t size, int (*compar)(const void *, const void *));
    qsort(students, count, sizeof(Student), compare);

    // 写入到第三个文件  
    for (size_t i = 0; i < count; i++) {
        fprintf(fp3, "%ld %s %d\n", students[i].num, students[i].name, students[i].score);
    }

    // 释放整个内存块  
    free(students);
    return 1;
}

int main() {
    FILE* fp1, * fp2, * fp3;
    if (fopen_s(&fp1, "a1.dat", "r") != 0) {
        printf("文件 a1.dat 打开失败！");
        return 0;
    }
    if (fopen_s(&fp2, "a2.dat", "r") != 0) {
        printf("文件 a2.dat 打开失败！");
        return 0;
    }
    if (fopen_s(&fp3, "a3.dat", "w") != 0) {
        printf("文件 a3.dat 打开失败！");
        return 0;
    }
    if (mergeFile(fp1, fp2, fp3))
        printf("归并、排序文件成功！\n");
    else {
        printf("归并、排序文件失败！\n");
        return 0;
    }
    fclose(fp1);
    fclose(fp2);
    fclose(fp3);
    if (fopen_s(&fp3, "a3.dat", "r") != 0) {
        printf("文件 a3.dat 打开失败！");
        return 0;
    }
    char buffer[50];
    printf("a3.dat内容：\n");
    while (fgets(buffer, 50, fp3)) {
        printf("%s", buffer);
    }
    fclose(fp3);
    return 1;
}