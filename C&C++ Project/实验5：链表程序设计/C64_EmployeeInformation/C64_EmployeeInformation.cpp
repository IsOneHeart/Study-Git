#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "Xlink_Employee.h"

/*
void max_list(EINode* list) {
    if (list == NULL || list->next == NULL) {
        printf("链表为空或没有员工信息。\n");
        return;
    }

    EINode* p = list->next;
    int premax = 0;
    char maxname[50]; // 假设最大名字长度与EINode中的name相同  
    strcpy(maxname, ""); // 初始化maxname为空字符串  

    while (p != NULL) {
        if (p->salary > premax) {
            premax = p->salary;
            strcpy(maxname, p->name);
        }
        p = p->next;
    }

    // 如果maxname没有被修改过（仍然是空字符串），说明没有找到员工信息  
    if (maxname[0] == '\0') {
        printf("链表中没有员工信息。\n");
    }
    else {
        printf("最高工资员工信息：\n%s %d\n", maxname, premax);
    }
}
*/

/*
void count_list(EINode* list) {
    if (list == NULL || list->next == NULL) {
        printf("链表为空或没有员工信息。\n");
        return;
    }

    EINode* p = list->next;
    int sum = 0, i = 0;
    int count = 0;

    while (p != NULL) {
        sum += p->salary;
        i++;
        p = p->next;
    }
    p = list -> next;
    while (p != NULL) {
        if (p->salary > (float)sum / i) {
            count++;
        }
        p = p->next;
    }

    if (i == 0) {
        printf("链表中没有员工信息。\n");
        return;
    }

    float aver = (float)sum / i;
    printf("超过平均基本工资的人数：%d\n平均基本工资：%.2f\n", count, aver);
}
*/

void del_list(EINode* list) {
    printf("请输入你删除的员工的对应工资：");
    int dels = 0;
    scanf("%d", &dels);
    EIListDeleteMore(list, dels);
    printf("删除后的链表：");
    EIListPrint(list);
}

int main() {
	EINode* list;
	EIListInitiate(&list);
	printf("请输入员工信息：（基本工资为0标记结束）\n");
	int salary = 0;
	char name[15] = "";
	for (int i = 1;;i++) {
		printf("第%d个员工：\n基本工资：",i);
		scanf("%d", &salary);
		if (!salary)
			break;
		printf("姓名：");
		scanf("%s", name);
		EIListInsert(list, 0, name, salary);
	}
	//max_list(list);
    //count_list(list);
    del_list(list);
	EIListDestory(&list);
	return 0;
}