#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void error(const char* msg) {
    printf("\033[31m[ERROR]");
    perror(msg);
    printf("\033[0m\n");
}

void info(const char* msg) {
    printf("\033[34m[INFO]");
    printf(msg);
    printf("\033[0m\n");
}

void log(const char* msg) {
    printf("[LOG]");
    printf(msg);
    printf("\n");
}