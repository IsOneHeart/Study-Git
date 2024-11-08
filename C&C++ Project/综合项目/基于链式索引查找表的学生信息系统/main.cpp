#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <easyx.h>

#include "studentGUI.h"

int main() {
    //Student stu = { 111111111111, createString("张三"), createString("男"), createString("1111-11-11"),createString("测试"),createString("测试"),createString("测试"),createString("测试"),createString("测试"),createString("1111-11-11"),1,createString("测试"),createString("测试") };
    Node* dataTable = createIndexTableFromFile("students.txt");
    //splitNode(&dataTable, 11);
    //mergeNodes(&dataTable);
    //deleteData(&dataTable, 201600002162);
    //insertData(&dataTable, stu);
    // 打印整个数据表
    printDataTable(dataTable);
    drawStudentGUI(&dataTable);

    //printf("请输入要查找的学号：");
    //long long sno;
    //Student student;
    //scanf("%lld", &sno);
    //if (indexSearch(dataTable, sno, &student)!=-1) {
    //    printf("已找到");
    //    printStudentColumn(&student);
    //}
    destroyDataTable(&dataTable);

    return 0;
}
