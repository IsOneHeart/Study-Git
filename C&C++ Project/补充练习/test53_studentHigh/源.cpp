#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 定义学生结构体，用于存储学生信息
struct Student {
    char name[11];
    char department[10];
    char gender;
    float height;
    long long int birthdate;
    long long int admission_date;
};

// 按照身高排序的比较函数
int compareHeight(const void* a, const void* b) {
    float heightA = ((struct Student*)a)->height;
    float heightB = ((struct Student*)b)->height;
    if (heightA < heightB) {
        return 1;
    }
    else if (heightA > heightB) {
        return -1;
    }
    else {
        return 0;
    }
}

int main() {
    FILE* inputFile, * outputFile;
    char buffer[100];
    struct Student students[60];
    int numStudents = 0;
    float sumHeightMale = 0, sumHeightFemale = 0;
    int countMale = 0, countFemale = 0;

    // 打开输入文件
    if ((inputFile = fopen("student.txt", "r")) == NULL) {
        printf("无法打开输入文件student.txt\n");
        exit(0);
    }

    // 从文件中读取学生信息
    while (fgets(buffer, sizeof(buffer), inputFile) != NULL) {
        sscanf(buffer, "%10s %9s %c %f %lld %lld",
            students[numStudents].name,
            students[numStudents].department,
            &students[numStudents].gender,
            &students[numStudents].height,
            &students[numStudents].birthdate,
            &students[numStudents].admission_date);

        if (students[numStudents].gender == 'M') {
            sumHeightMale += students[numStudents].height;
            countMale++;
        }
        else if (students[numStudents].gender == 'F') {
            sumHeightFemale += students[numStudents].height;
            countFemale++;
        }

        numStudents++;
    }

    // 关闭输入文件
    if (fclose(inputFile)) {
        printf("无法正常关闭输入文件student.txt\n!");
        exit(0);
    }

    // 按照身高降序排序学生
    qsort(students, numStudents, sizeof(struct Student), compareHeight);

    // 打开输出文件
    if ((outputFile = fopen("StudentHeight.txt", "wt")) == NULL) {
        printf("无法打开输出文件StudentHeight.txt\n");
        exit(0);
    }

    // 将排序后的学生信息写入输出文件
    for (int i = 0; i < numStudents; i++) {
        fprintf(outputFile, "%s %s %c %.2f %lld %lld\n",
            students[i].name,
            students[i].department,
            students[i].gender,
            students[i].height,
            students[i].birthdate,
            students[i].admission_date);
    }

    // 关闭输出文件
    if (fclose(outputFile)) {
        printf("无法正常关闭输出文件!StudentHeight.txt\n");
        exit(0);
    }

    // 计算并显示男女生的平均身高
    if (countMale > 0) {
        printf("男生平均身高：%.2f\n", sumHeightMale / countMale);
    }
    else {
        printf("无男生数据\n");
    }

    if (countFemale > 0) {
        printf("女生平均身高：%.2f\n", sumHeightFemale / countFemale);
    }
    else {
        printf("无女生数据\n");
    }

    return 0;
}