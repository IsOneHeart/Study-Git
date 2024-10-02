#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
    int n;
    double sum = 0.0, num = 1.0, deno = 1.0;

    printf("请输入n的值：");
    scanf("%d", &n);

    if (n <= 0) {
        printf("输入的数应为正整数。\n");
    }
    else {
        for (int i = 1; i <= n; i++) {
            double term = num / deno;
            if (i % 2 == 0) {
                term = -term; // 奇数项为正，偶数项为负
            }
            sum += term;
            double temp = num;//temp为临时变量
            num = deno;
            deno = deno + temp;
        }
    }

    printf("前%d项的和约为%.2lf\n", n, sum);
    return 0;
}
/*
在这个问题中，我们需要计算一个序列的和，其中每一项的分子是前一项的分母，分母是前一项的分子和分母之和。在每一步迭代中，我们需要保存前一项的分子和分母，然后计算下一项，最后再更新分子和分母。
如果不使用临时变量 temp，在更新分子和分母的时候可能会出现问题。因为在更新 num 和 deno 之前，我们需要用到它们的原始值。如果直接更新了其中一个，那么在计算另一个时就会使用到更新后的值，而不是原始值，导致计算错误。
通过使用 temp，我们可以保存 num 的原始值，然后再更新 num 和 deno，确保在计算下一项时使用的是更新前的原始值，保持了计算的正确性。这是一种为了避免数学表达式中的竞态条件而采用的常见做法。
在我的最后一个修复中，我采用了一种更简洁的方式，通过在计算下一项时使用 num 和 deno 的数学表达式来实现交换，避免了引入额外的临时变量。
*/