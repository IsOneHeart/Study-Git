#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 自定义的String类型
typedef struct {
    char* data; // 指向存储字符串的字符数组
    size_t length; // 字符串的当前长度
    size_t capacity; // 字符串的最大容量
} String;

String createString(const char* src);
void destroyString(String* str);
void appendString(String* str, const char* src);
void printString(const String* str);

String createString(const char* src) {
    String str{};
    str.length = strlen(src);
    str.capacity = str.length + 1; // 加1是为了存储null终止符
    str.data = (char*)malloc(str.capacity * sizeof(char));
    if (str.data) {
        strcpy(str.data, src);
    }
    return str;
}

// 销毁String实例
void destroyString(String* str) {
    if (str && str->data) {
        free(str->data);
        str->data = NULL;
        str->length = 0;
        str->capacity = 0;
    }
}

// 向String追加字符串
void appendString(String* str, const char* src) {
    size_t srcLength = strlen(src);
    if (str->length + srcLength + 1 > str->capacity) { // 需要额外的空间来存储null终止符
        // 需要扩容
        size_t newCapacity = str->length + srcLength + 1;
        char* newData = (char*)realloc(str->data, newCapacity);
        if (!newData) {
            perror("内存分配失败！");
            exit(EXIT_FAILURE);
        }
        str->data = newData;
        str->capacity = newCapacity;
    }
    strcpy(str->data + str->length, src);
    str->length += srcLength;
}

// 打印String
void printString(const String* str) {
    printf("%s\t", str->data);
}

