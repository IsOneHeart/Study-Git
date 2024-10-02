#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Xstring.h"
#define InitiateMaxSize 25

int main() {
	Str String1,  String2,  String3;
	char s1[InitiateMaxSize], s2[InitiateMaxSize], s3[InitiateMaxSize];
	printf("String1：");
	scanf("%s", s1);
	printf("String2：");
	scanf("%s", s2);
	printf("String3：");
	scanf("%s", s3);
	StrInitiate(&String1, InitiateMaxSize, s1);
	StrInitiate(&String2, InitiateMaxSize, s2);
	StrInitiate(&String3, InitiateMaxSize, s3);
	StrInsertStr(&String1, String2, 5);
	printf("String1 result1：");
	printf("%s\n", String1.str);
	PatternMatching(&String1, String3, 5);
	printf("String1 result2：");
	printf("%s\n", String1.str);
	return 0;
}