#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// ����ѧ���ṹ�壬���ڴ洢ѧ����Ϣ
struct Student {
    char name[11];
    char department[10];
    char gender;
    float height;
    long long int birthdate;
    long long int admission_date;
};

// �����������ıȽϺ���
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

    // �������ļ�
    if ((inputFile = fopen("student.txt", "r")) == NULL) {
        printf("�޷��������ļ�student.txt\n");
        exit(0);
    }

    // ���ļ��ж�ȡѧ����Ϣ
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

    // �ر������ļ�
    if (fclose(inputFile)) {
        printf("�޷������ر������ļ�student.txt\n!");
        exit(0);
    }

    // ������߽�������ѧ��
    qsort(students, numStudents, sizeof(struct Student), compareHeight);

    // ������ļ�
    if ((outputFile = fopen("StudentHeight.txt", "wt")) == NULL) {
        printf("�޷�������ļ�StudentHeight.txt\n");
        exit(0);
    }

    // ��������ѧ����Ϣд������ļ�
    for (int i = 0; i < numStudents; i++) {
        fprintf(outputFile, "%s %s %c %.2f %lld %lld\n",
            students[i].name,
            students[i].department,
            students[i].gender,
            students[i].height,
            students[i].birthdate,
            students[i].admission_date);
    }

    // �ر�����ļ�
    if (fclose(outputFile)) {
        printf("�޷������ر�����ļ�!StudentHeight.txt\n");
        exit(0);
    }

    // ���㲢��ʾ��Ů����ƽ�����
    if (countMale > 0) {
        printf("����ƽ����ߣ�%.2f\n", sumHeightMale / countMale);
    }
    else {
        printf("����������\n");
    }

    if (countFemale > 0) {
        printf("Ů��ƽ����ߣ�%.2f\n", sumHeightFemale / countFemale);
    }
    else {
        printf("��Ů������\n");
    }

    return 0;
}