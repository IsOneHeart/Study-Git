#pragma once
#include <stdlib.h>
#include <string.h>
typedef struct Str {
	char* str;
	int maxlen;
	int len;
}Str;

int StrInitiate(Str* S, int max, const char* string) {
	S->str = (char*)malloc(sizeof(char) * max);
	if (S->str == NULL) {
		printf("分配内存块失败！");
		return 0;
	}
	S->len = strlen(string);
	S->maxlen = max;
	for (int i = 0;i < S->len;i++)
		S->str[i] = string[i];
	return 1;
}

int StrInsert(Str* S, int pos, Str T) {
	int i;
	if (pos < 0) {
		printf("参数pos出错！");
		return 0;
	}
	if (S->len + T.len + 1 > S->maxlen) { // 加上额外的一个字符用于存储 null 结尾
		//若删除 (unsigned long long) ：在分配到更广的类型之前，子表达时可能溢出
		char* newStr = (char*)realloc(S->str, (unsigned long long)(S->len + T.len + 1) * sizeof(char));
		if (newStr == NULL) {
			printf("重新分配内存失败！");
			return 0;
		}
		S->str = newStr;
		S->maxlen = S->len + T.len + 1;
	}
	for (i = S->len - 1; i >= pos; i--) {
		S->str[i + T.len] = S->str[i];
	}
	for (i = 0; i < T.len; i++) {
		S->str[pos + i] = T.str[i];
	}
	S->len += T.len;
	S->str[S->len] = '\0'; // 标记串结束
	return 1;
}

int StrDelete(Str* S, int pos, int len) {
	int i;
	if (S->len <= 0) {
		printf("串已为空！");
		return 0;
	}
	else if (pos < 0 || len<0 || pos + len>S->len) {
		printf("参数pos或len不合法！");
		return 0;
	}
	else {
		for (i = pos + len;i <= S->len - 1;i++)
			S->str[i - len] = S->str[i];
		S->len = S->len - len;
		return 1;
	}
}

int StrSub(Str* S, int pos, int len, Str* T) {
	int i;
	if (pos < 0 || len < 0 || pos + len > S->len) {
		printf("参数pos或len不合法！");
		return 0;
	}
	if (len > T->maxlen) {
		char* newStr = (char*)malloc((unsigned long long)(len + 1) * sizeof(char)); // 加上额外的一个字符用于存储 null 结尾
		if (newStr == NULL) {
			printf("分配内存失败！");
			return 0;
		}
		T->maxlen = len + 1;
		T->str = newStr;
	}
	for (i = 0; i < len; i++) {
		T->str[i] = S->str[pos + i];
	}
	T->len = len;
	T->str[T->len] = '\0'; // 标记串结束
	return 1;
}

int StrDestory(Str* S) {
	free(S->str);
	S->str = NULL;
	S->maxlen = 0;
	S->len = 0;
	return 1;
}

int StrCompare(Str* S1, Str* S2) {
	int CompareLen = S1->len < S2->len ? S1->len : S2->len;
	for (int i = 0;i < CompareLen;i++) {
		if ((int)S1->str[i] > (int)S2->str[i])
			return 1;
	}
	if (S1->len > S2->len)
		return 1;
	if (S1->len = S2->len)
		return 0;
	return -1;
}

int BruteForce(Str S, int start, Str T) {
	int i = start, j = 0;
	while (i < S.len && j < T.len) {
		if (S.str[i] == T.str[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 1;
			j = 0;
		}
	}
	if (j == T.len)
		return i - T.len;
	return -1;
}

int KMP(Str S, int start, Str T, int next[]) {
	int i = start, j = 0, v;
	while (i < S.len && j < T.len) {
		if (S.str[i] == T.str[i]) {
			i++;
			j++;
		}
		else if (j == 0)
			i++;
		else j = next[j];
	}
	if (j == T.len)
		v = i - T.len;
	else
		v = -1;
	return v;
}

int StrInsertStr(Str* S1, Str S2, int n) {
	if (n<0 || n>S2.len) {
		printf("参数n不合法！");
		return 0;
	}
	for (int i = 0;i <= n;i++) {
		if (i > S1->len - 1) {
		    //若删除 (unsigned long long) ：在分配到更广的类型之前，子表达时可能溢出
			char* newStr = (char*)realloc(S1->str, (unsigned long long)(S1->len + n + 1 + 1) * sizeof(char));// 加上额外的一个字符用于存储'\n'
			if (newStr == NULL) {
				printf("重新分配内存失败！");
				return 0;
			}
			S1->str = newStr;
		}
		else {
			S1->str[S1->len] = S2.str[i];
			S1->len++;
		}
	}
	S1->maxlen = S1->len + n + 1 + 1;
	S1->str[S1->len] = '\0';
	return 1;
}

int PatternMatching(Str* S1, Str S3, int m) {
	int result = BruteForce(*S1, 0, S3);
	if (result >= 0)
		return result;
	if (m < 0 || m > S1->len ) {
		printf("参数m不合法！");
		return -1;
	}
	if (S1->maxlen - 1 < S1->len + S3.len) {
		S1->str = (char*)realloc(S1->str, (unsigned long long)(S1->len + S3.len + 1));
		if (S1->str == NULL) {
			printf("重新分配内存失败！");
			return -2;
		}
		S1->maxlen = S1->maxlen + S3.len + 1;
	}
	for (int i = S1->len - 1; i >= m; i--) {
		S1->str[i + S3.len] = S1->str[i];
	}
	for (int i = 0; i < S3.len; i++) {
		S1->str[m + i] = S3.str[i];
	}
	S1->len += S3.len;
	S1->str[S1->len] = '\0';
	return -3;
}