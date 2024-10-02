#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "E:\StudyE\C&C++\自制头文件\YXlist.h"

void getRandomList0To1000(Node *head, int n) {
    for (int i = 0; i < n; i++) {
        int num = rand() % 1001;
        ListInsert(head, 0, num);
    }
}

void SelectSort(Node **head) {
    Node *p, *index;
    int first = (*head)->data, count = 0;
    if ((*head)->next == NULL) {
        printf("[直接选择排序]链表为空\n");
        return;
    } else {
        for (p = (*head)->next; p->next != NULL; p = p->next) {
            for (index = p->next; index != NULL; index = index->next) {
                if (p->data > index->data)
                    ListExchange(p, index);
            }
        }
    }
    p = (*head)->next;
    while (p != NULL) {
        if (p->data > first){
            ListInsert((*head), count, first);
            break;
        }
        count++;
        p = p->next;
    }
}

int main() {
    Node *head = NULL, *head2 = NULL, *head3 = NULL;
    ListInitiate(&head);
    srand(time(NULL));
    getRandomList0To1000(head, 10);
    ListCopy(head, &head2);
    ListCopy(head, &head3);
    printf("排序前：");
    ListPrint(head);
    ListAscend(&head); //实验10-27附加题
    printf("\n冒泡排序后：");
    ListPrint(head);
    SelectSort(&head2);
    printf("\n直接选择排序后："); //实验10-28附加题
    ListPrint(head2);
    return 0;
}
