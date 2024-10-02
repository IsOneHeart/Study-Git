#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cstdio>
#include <dir.h>
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
    struct Node *next;
} Node;

Node *table[TABLE_SIZE];

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
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;
}

// 查找元素
int search(int key, int *count) {
    int index = hashFunction(key);
    Node *current = table[index];
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
int removeKey(int key, int *count) {
    int index = hashFunction(key);
    Node **current = &table[index];
    while (*current != NULL) {
        (*count)++;
        if ((*current)->key == key) {
            Node *temp = *current;
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
        printf("Bucket %d: ", i);
        Node *current = table[i];
        while (current != NULL) {
            printf("%d -> ", current->key);
            current = current->next;
        }
        printf("NULL\n");
    }
}

// 主函数
int main() {
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        std::cout << "当前工作目录: " << cwd << std::endl;
    } else {
        perror("getcwd() error");
        return 1;
    }

    srand(time(NULL));
    int A[10];
    getRandomNum10To1000(A, 10);

    initHashTable();

    // 建立哈希表
    for (int i = 0; i < 10; i++) {
        insert(A[i]);
    }

    // 输出哈希表
    printHashTable();

    // 查找操作
    int keyToSearch;
    printf("Enter key to search: ");
    scanf("%d", &keyToSearch);
    int count = 0;
    if (search(keyToSearch, &count)) {
        printf("Key found in %d operations.\n", count);
    } else {
        printf("Key not found in %d operations.\n", count);
    }

    // 删除操作
    int keyToRemove;
    printf("Enter key to remove: ");
    scanf("%d", &keyToRemove);
    count = 0;
    if (removeKey(keyToRemove, &count)) {
        printf("Key removed in %d operations.\n", count);
    } else {
        printf("Key not found in %d operations.\n", count);
    }

    // 再次输出哈希表
    printHashTable();

    return 0;
}
