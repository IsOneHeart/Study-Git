#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>

#define TABLE_SIZE 100
#define PRIME 19 // 20以内的素数

void getRandomNum10To1000(int array[], int n) {
    for (int i = 0; i < n; i++) {
        array[i] = rand() % 990 + 10;
    }
}

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* table[TABLE_SIZE];

// 初始化哈希表
void initHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        table[i] = NULL;
    }
}

// 哈希函数
int hashFunction(int key) {
    return key % PRIME;
}

// 插入元素到哈希表
void insert(int key) {
    int index = hashFunction(key);
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "内存分配失败!\n");
        exit(0);
    }
    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;
}

// 查找元素
int search(int key, int* count) {
    int index = hashFunction(key);
    Node* current = table[index];
    while (current != NULL) {
        (*count)++;
        if (current->key == key) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

// 删除元素
int removeKey(int key, int* count) {
    int index = hashFunction(key);
    Node** current = &table[index];
    while (*current != NULL) {
        (*count)++;
        if ((*current)->key == key) {
            Node* temp = *current;
            *current = (*current)->next;
            free(temp);
            return 1;
        }
        current = &((*current)->next);
    }
    return 0;
}

// 输出哈希表
void printHashTable() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("[%d]: ", i);
        Node* current = table[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

int main() {
    srand(time(NULL));
    int A[10];
    getRandomNum10To1000(A, 10);

    initHashTable();
    for (int i = 0; i < 10; i++) {
        insert(A[i]);
    }
    printHashTable();
    int keyToSearch;
    printf("输入key进行查询: ");
    scanf("%d", &keyToSearch);
    int count = 0;
    if (search(keyToSearch, &count)) {
        printf("Key已找到。\n", count);
    } else {
        printf("Key未找到。\n", count);
    }
    int keyToRemove;
    printf("输入key进行删除: ");
    scanf("%d", &keyToRemove);
    count = 0;
    if (removeKey(keyToRemove, &count)) {
        printf("Key已删除。\n", count);
    } else {
        printf("Key未删除。\n", count);
    }
    printHashTable();

    return 0;
}
