#include <stdio.h>
#include <stdlib.h>
typedef char stype;
#define TYPE "%c"
#include "Xstack.h"
#include <string.h>  
#include <ctype.h>  // 引入isdigit()函数，判断一个char字符是否是数字

#define MAX_SIZE 256

int isOperator(char c) {
    // 只要有一个为真，返回1，否则返回0
    return (c == '+' || c == '-' || c == '*' || c == '/');
}

int precedence(char c) { // 返回操作符优先级
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
    StackInitiate(&head); // 字符栈
    int i = 0, j = 0;
    while (infix[i] != '\0') { // 换行符循环结束
        char c = infix[i];
        if (isdigit(c)) { // 如果是数字
            while (isdigit(infix[i])) { // 复制infix[i]到postfix[j]直到infix[i]不是数字
                postfix[j++] = infix[i++];
            }
            postfix[j++] = ' '; // 添加空格以区分多位数
            i--; // 回退一个字符，因为在循环中已经多加了一次
        }
        else if (isOperator(c)) { // 如果是操作符
            // 如果栈非空，且栈顶操作符比新读取的操作符优先级更高
            while (StackNotEmpty(head) && precedence(StackTop(head)) >= precedence(c)) {
                postfix[j++] = StackTop(head); // 取栈顶元素
                stype pop;
                StackPop(head, &pop);  // 出栈 第二个形参不可为NULL，否则会导致C6011(?)
            }
            StackPush(head, c); // 优先级比较结束，新操作符入栈
        }
        else if (c == '(') {
            StackPush(head, c); // 左括号直接入栈
        }
        else if (c == ')') { // 读取到右括号
            while (StackTop(head) != '(') { // 如果栈顶非左括号
                postfix[j++] = StackTop(head); // 取栈顶元素
                stype pop;
                StackPop(head, &pop); // 出栈
            }
            stype pop;
            StackPop(head, &pop); // 左括号出栈
        }
        i++;
    }

    while (StackNotEmpty(head)) { // 如果栈内还有剩余操作符
        postfix[j++] = StackTop(head); // 取出
        stype pop;
        StackPop(head, &pop);
    }
    postfix[j] = '\0';
}

int evaluatePostfix(char* postfix) {
    SNode* head = NULL;
    StackInitiate(&head); //数字栈
    int i = 0;
    while (postfix[i] != '\0') {
        char c = postfix[i];
        if (isdigit(c)) { // 如果是数字
            int operand = 0;
            while (isdigit(postfix[i])) { // 连续读取单位数字字符直至非数字字符
                operand = operand * 10 + (postfix[i] - '0'); // 将字符转化为数字并合并为多位数字
                i++;
            }
            i--; // 回退一个字符，因为在循环中已经多加了一次
            StackPush(head, operand); // 将数字入栈
        }
        else if (isOperator(c)) { // 如果是操作符
            int operand2 = StackTop(head); // 取栈顶数字
            stype pop;
            StackPop(head, &pop);  //数字出栈
            int operand1 = StackTop(head); //再从栈中取数字
            StackPop(head, &pop);  //第二位数字出栈
            int result;
            switch (c) { // 根据操作符计算从栈中取出的两个数字
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
            StackPush(head, result); // 将计算结果重新入栈
        }
        i++;
    }
    return StackTop(head); // 最后栈中只剩下一个数字，即最终运算结果，返回
}

int main() {
    char infix[MAX_SIZE], postfix[MAX_SIZE];
    printf("请输入中缀表达式（操作数可以是多位数，操作符为+,-,*,/）: ");
    fgets(infix, MAX_SIZE, stdin);
    infixToPostfix(infix, postfix);
    printf("后缀表达式: %s\n", postfix);
    int result = evaluatePostfix(postfix);
    printf("计算结果: %d\n", result);
    return 0;
}