#include <stdio.h>
#include <stdbool.h>

bool knapsack(int w[], int n, int sumW, int s) {
	if (sumW == s)  // 背包已装满
		return true;
	if (sumW > s || n < 0) // 背包超重或没有物品可选
		return false;
	return knapsack(w, n - 1, sumW, s) ||(sumW + w[n] <= s && knapsack(w, n - 1, sumW + w[n], s));
}

int main() {
    int weights[] = { 3, 3, 3 }; // 物品重量数组  
    int s = 9; // 背包容量  
    int n = sizeof(weights) / sizeof(weights[0]); // 物品数量  
    int result = knapsack(weights, n, 0, s);
    if (result) {
        printf("背包问题有解！\n");
    }
    else {
        printf("背包问题无解！\n");
    }
}