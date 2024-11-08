#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "YXstring.h"

#define MAXSIZE 20 // 每个节点最多存储的数据元素个数
int Pages = 0;

// 学生信息结构体
typedef struct {
    long long sno;        // 学号(关键字)
    String sname;         // 姓名
    String sex;           // 性别
    String birthday;      // 出生日期
    String nationality;   // 民族
    String native;        // 籍贯
    String political;     // 政治面貌
    String district;      // 校区
    String studentSource; // 学生来源
    String enterYear;     // 入学日期
    int schoolYear;       // 学年
    String inClass;       // 班级
    String  majorNo;      // 专业编号
} Student;

// 单链表节点结构体
typedef struct Node {
    Student data[MAXSIZE]; // 学生数据
    int count;             // 当前节点存储的数据个数
    struct Node* next;     // 指向下一个节点的指针
} Node;

Node* createIndexTableFromFile(const char* filename);
Node** initIndexTable();
int indexSearch(Node* dataTable, long long id, Student* student);
void insertData(Node** dataTable, Student student, int page, int index);
int deleteData(Node** dataTable, long long sno);
void splitNode(Node** dataTable, int size);
void mergeNodes(Node** dataTable);
void destroyDataTable(Node** head);

// 从文件中读取学生数据，创建数据表
Node* createIndexTableFromFile(const char* filename) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("打开文件失败！");
        return NULL;
    }
    // 跳过第一行（表头）
    char buffer[1024];
    fgets(buffer, sizeof(buffer), file);
    Node* head = NULL;
    Node* current = NULL;
    Node* newNode = NULL;
    Student student;
    char* token;
    while (fgets(buffer, sizeof(buffer), file)) {
        // 创建新的节点，如果当前节点已满
        if (current == NULL || current->count == MAXSIZE) {
            Pages++;
            newNode = (Node*)malloc(sizeof(Node));
            if (!newNode) {
                perror("内存分配失败！");
                fclose(file);
                return NULL; 
            }
            newNode->count = 0;
            newNode->next = NULL;
            // 将新节点添加到链表
            if (current) {
                current->next = newNode;
            }
            else {
                head = newNode;
            }
            current = newNode;
        }
        // 使用strtok分割字符串
        token = strtok(buffer, " \t\n");
        student.sno = atoll(token); // 学号
        token = strtok(NULL, " \t\n");
        student.sname = createString(token); // 姓名
        token = strtok(NULL, " \t\n");
        student.sex = createString(token); // 性别
        token = strtok(NULL, " \t\n");
        student.birthday = createString(token); // 出生日期
        token = strtok(NULL, " \t\n");
        student.nationality = createString(token); // 民族
        token = strtok(NULL, " \t\n");
        student.native = createString(token); // 户籍
        token = strtok(NULL, " \t\n");
        student.political = createString(token); // 政治面貌
        token = strtok(NULL, " \t\n");
        student.district = createString(token); // 校区
        token = strtok(NULL, " \t\n");
        student.studentSource = createString(token); // 学生来源
        token = strtok(NULL, " \t\n");
        student.enterYear = createString(token); // 入学年份
        token = strtok(NULL, " \t\n");
        student.schoolYear = atoi(token); // 学年
        token = strtok(NULL, " \t\n");
        student.inClass = createString(token); // 班级
        token = strtok(NULL, " \t\n");
        student.majorNo = createString(token); // 专业编号
        // 将学生数据添加到当前节点
        current->data[current->count++] = student;
    }
    fclose(file);
    return head;
}

// 将数据表保存到文件
void saveIndexTableToFile(Node* dataTable, const char* filename) {
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("打开文件失败！");
        return;
    }
    // 写入表头
    fprintf(file, "sno\t");
    fprintf(file, "sname\t");
    fprintf(file, "sex\t");
    fprintf(file, "birthday\t");
    fprintf(file, "nationality\t");
    fprintf(file, "native\t");
    fprintf(file, "political\t");
    fprintf(file, "district\t");
    fprintf(file, "studentSource\t");
    fprintf(file, "enterYear\t");
    fprintf(file, "schoolYear\t");
    fprintf(file, "inClass\t");
    fprintf(file, "majorNo\n");
    Node* current = dataTable;
    while (current != NULL) {
        for (int i = 0; i < current->count; ++i) {
            fprintf(file, "%lld\t", current->data[i].sno);
            fprintf(file, "%s\t", current->data[i].sname.data);
            fprintf(file, "%s\t", current->data[i].sex.data);
            fprintf(file, "%s\t", current->data[i].birthday.data);
            fprintf(file, "%s\t", current->data[i].nationality.data);
            fprintf(file, "%s\t", current->data[i].native.data);
            fprintf(file, "%s\t", current->data[i].political.data);
            fprintf(file, "%s\t", current->data[i].district.data);
            fprintf(file, "%s\t", current->data[i].studentSource.data);
            fprintf(file, "%s\t", current->data[i].enterYear.data);
            fprintf(file, "%d\t", current->data[i].schoolYear);
            fprintf(file, "%s\t", current->data[i].inClass.data);
            fprintf(file, "%s\n", current->data[i].majorNo.data);
        }
        current = current->next;
    }
    fclose(file);
}


// 创建空索引表
Node** initIndexTable() {
    Node* dataTable = (Node*)malloc(sizeof(Node));
    dataTable->count = 0;
    dataTable->next = NULL;
    if (!dataTable) {
        perror("内存分配失败！");
        return NULL;
    }
    return &dataTable;
}

// 索引查询
int indexSearch(Node* dataTable, long long id, Student* student) {
    Node* current = dataTable;
    int i, count = 0;
    while (current != NULL) {
        count++;
        for (i = 0; i < current->count; ++i) {
            if (current->data[i].sno == id) {
                *student = current->data[i];
                return count; 
            }
        }
        current = current->next;
    }
    return -1;
}

int changeData(Node** dataTable, Student student) {
    Node* current = *dataTable;
    int i, thisPage = 0;
    while (current != NULL) {
        thisPage++;
        for (i = 0; i < current->count; ++i) {
            if (current->data[i].sno == student.sno) {
                current->data[i] = student;
            }
        }
        current = current->next;
    }
    return thisPage;
}

// 分裂节点
void splitNode(Node** dataTable, int size) {
    if (size <= 0 || size >= MAXSIZE) {
        return;
    }
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("内存分配失败！");
        return;
    }
    newNode->count = 0;
    newNode->next = (*dataTable)->next;
    (*dataTable)->next = newNode;
    for (int i = size; i < (*dataTable)->count; i++) {
        newNode->data[newNode->count] = (*dataTable)->data[i];
        newNode->count++;
    }
    (*dataTable)->count = size;
}

// 合并相邻节点
void mergeNodes(Node** dataTable) {
    if ((*dataTable) == NULL || (*dataTable)->next == NULL) {
        return; // 当前节点为空或没有下一个节点则不进行合并
    }
    Node* nextNode = (*dataTable)->next;
    int spaceLeft = MAXSIZE - (*dataTable)->count; // 当前节点还可以容纳的数据数量
    if (spaceLeft <= 0 || nextNode->count == 0) { // 当前节点没有足够的空间或者下一个节点没有数据则不进行合并
        return;
    }
    int numToMove = (nextNode->count < spaceLeft) ? nextNode->count : spaceLeft; // 可以从下一个节点移动到当前节点的数据数量
    for (int i = 0; i < numToMove; i++) {
        (*dataTable)->data[(*dataTable)->count + i] = nextNode->data[i];
    }
    (*dataTable)->count += numToMove; // 更新当前节点的数据数量
    for (int i = 0; i < nextNode->count - numToMove; i++) {
        nextNode->data[i] = nextNode->data[i + numToMove];
    }
    nextNode->count -= numToMove; // 更新下一个节点的数据数量
    if (nextNode->count == 0) {
        (*dataTable)->next = nextNode->next;
        free(nextNode);
    }
}

void clearTable(Node** dataTable) {
    Node* current = *dataTable;
    while (current != NULL) {
        mergeNodes(&current);
    }
}

// 插入数据
void insertData(Node** dataTable, Student student, int page, int index) {
    if (page <= 0 || index < 0 || page > Pages || index > MAXSIZE) {
        printf("index或page参数错误！");
        return;
    }
    Node* current = *dataTable;
    int i, thisPage = 0;
    while (current != NULL) {
        thisPage++;
        if (thisPage == page) {
            if (current->count == MAXSIZE) {
                splitNode(&current, MAXSIZE - 1); // 分裂节点
            }
            if (current->count < MAXSIZE) {
                if (index >= current->count) {
                    current->data[current->count] = student;
                    current->count++;
                }
                else {
                    current->count++;
                    for (i = current->count - 1; i > index-1; i--) {
                        current->data[i] = current->data[i - 1];
                    }
                    current->data[index-1] = student;
                }
            }
        }
        current = current->next;
    }
}

// 删除数据
int deleteData(Node** dataTable, long long sno) {
    if (dataTable == NULL || *dataTable == NULL) {
        return 1;
    }
    Node* current = *dataTable;
    Node* prev = NULL; // 用于记录前一个节点，以便在需要时合并节点
    int thisPage = 0;
    while (current != NULL) {
        int i;
        thisPage++;
        for (i = 0; i < current->count; ++i) {
            if (current->data[i].sno == sno) {
                // 找到需要删除的数据，将其后面的数据前移
                for (int j = i; j < current->count - 1; ++j) {
                    current->data[j] = current->data[j + 1];
                }
                current->count--; // 更新当前节点存储的数据个数
                // 检查是否需要合并节点
                if (current->count < MAXSIZE / 2 && current->next != NULL) {
                    mergeNodes(&current);
                }
                // 检查是否需要分裂节点
                else if (current->count > MAXSIZE) {
                    splitNode(&current, current->count / 2);
                }
                return 1; // 删除操作完成，返回1表示成功
            }
        }
        prev = current;
        current = current->next;
    }
    return thisPage;
}

// 打印单个学生的信息
void printStudentColumn(const Student* student) {
    printf("学号：%lld\n姓名：", student->sno);
    printString(&student->sname); 
    printf("\n性别：");
    printString(&student->sex);
    printf("\n出生日期：");
    printString(&student->birthday);
    printf("\n民族：");
    printString(&student->nationality);
    printf("\n户籍：");
    printString(&student->native);
    printf("\n政治面貌：");
    printString(&student->political);
    printf("\n校区：");
    printString(&student->district);
    printf("\n学生来源：");
    printString(&student->studentSource);
    printf("\n入学日期：");
    printString(&student->enterYear);
    printf("\n学年：");
    printf("%d\n", student->schoolYear);
    printf("班级：");
    printString(&student->inClass);
    printf("\n专业号：");
    printString(&student->majorNo);
    printf("\n");
}

void printStudentRow(const Student* student) {
    printf("%lld\t", student->sno);
    printString(&student->sname);
    printString(&student->sex);
    printString(&student->birthday);
    printString(&student->nationality);
    printString(&student->native);
    printString(&student->political);
    printString(&student->district);
    printString(&student->studentSource);
    printString(&student->enterYear);
    printf("%d\t", student->schoolYear);
    printString(&student->inClass);
    printString(&student->majorNo);
    printf("\n");
}

// 打印整个学生数据表
void printDataTable(Node* head) {
    Node* current = head;
    int i;
    printf("学号\t姓名\t性别\t出生日期\t民族\t籍贯\t政治面貌\t校区\t学生来源\t入学年份\t学年\t班级\t专业编号\t\n");
    while (current != NULL) {
        for (i = 0; i < current->count; ++i) {
            printStudentRow(&current->data[i]);
        }
        current = current->next;
    }
}

// 释放学生数据表
void destroyDataTable(Node** head) {
    Node* current = *head;
    int i;
    while (current != NULL) {
        // 释放当前节点中存储的所有学生信息
        for (i = 0; i < current->count; ++i) {
            destroyString(&current->data[i].sname);
            destroyString(&current->data[i].sex);
            destroyString(&current->data[i].birthday);
            destroyString(&current->data[i].nationality);
            destroyString(&current->data[i].native);
            destroyString(&current->data[i].political);
            destroyString(&current->data[i].district);
            destroyString(&current->data[i].studentSource);
            destroyString(&current->data[i].enterYear);
            destroyString(&current->data[i].inClass);
        }
        Node* toDelete = current;
        current = current->next; 
        free(toDelete); // 释放当前节点
    }
    *head = NULL; // 更新头指针，避免悬挂指针
}
