#include <stdio.h>
#include <stdlib.h>
typedef char stype;
#define TYPE "%c"
#include "Xstack.h"
#include <string.h>  
#include <ctype.h>  //isdigit()
#define MAX_SIZE 16

int isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) {
    if (c == '+' || c == '-') {
        return 1;
    }
    else if (c == '*' || c == '/') {
        return 2;
    }
    return 0;
}

void infixToPostfix(char* infix, char* postfix) {
    SNode* head = NULL;
    StackInitiate(&head);
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        char c = infix[i];
        if (isdigit(c)) {
            postfix[j++] = c; // ֱ�ӽ�����д���׺���ʽ
        }
        else if (isOperator(c)) {
            while (StackNotEmpty(head) && precedence(StackTop(head)) >= precedence(c)) {
                postfix[j++] = StackTop(head); // ��ջ��������д���׺���ʽ
                stype pop;
                StackPop(head, &pop);
            }
            StackPush(head, c);
        }
        else if (c == '(') {
            StackPush(head, c);
        }
        else if (c == ')') {
            while (StackTop(head) != '(') {
                postfix[j++] = StackTop(head);
                stype pop;
                StackPop(head, &pop);
            }
            stype pop;
            StackPop(head, &pop);
        }
        i++;
    }
    while (StackNotEmpty(head)) {
        postfix[j++] = StackTop(head);
        stype pop;
        StackPop(head, &pop);
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    SNode* head = NULL;
    StackInitiate(&head);
    int i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (isdigit(c)) {
            StackPush(head, c - '0'); // ���ַ���ʽ������ת��Ϊʵ�ʵ�����ֵ
        }
        else if (isOperator(c)) {
            int operand2 = StackTop(head);
            stype pop;
            StackPop(head, &pop);
            int operand1 = StackTop(head);
            StackPop(head, &pop);
            int result;
            switch (c) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            StackPush(head, result);
        }
        i++;
    }
    return StackTop(head);
}

int evaluatePostfix(char* postfix) {
    SNode* head = NULL;
    StackInitiate(&head);
    int i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (isdigit(c)) {
            StackPush(head, c - '0');
        }
        else if (isOperator(c)) {
            int operand2 = StackTop(head);
            stype pop;
            StackPop(head, &pop);
            int operand1 = StackTop(head);
            StackPop(head, &pop);
            int result;
            switch (c) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '*':
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            }
            StackPush(head, result);
        }
        i++;
    }
    return StackTop(head);
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("��������׺���ʽ�������������һλ����������Ϊ+,-,*,/��: ");
    scanf_s("%s", infix,(unsigned int)sizeof(infix));

    infixToPostfix(infix, postfix);
    printf("��׺���ʽ: %s\n", postfix);

    int result = evaluatePostfix(postfix);
    printf("������: %d\n", result);

    return 0;
}