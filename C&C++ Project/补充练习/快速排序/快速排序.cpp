#include <stdio.h>

#define DataType int

void QuickSort(DataType a[], int low, int high) {
    if (low < high) {
        // 选择最左边的元素作为基准  
        DataType temp = a[low];
        int i = low; // 小于基准的元素的索引  
        int j = high; // 大于基准的元素的索引  
        // 进行分区  
        while (i < j) {
            // 在数组右端扫描  
            while (i < j && a[j] >= temp) {
                j--;
            }
            // 如果当前元素小于基准，交换到左边  
            if (i < j) {
                a[i] = a[j];
                i++;
            }
            // 在数组左端扫描  
            while (i < j && a[i] <= temp) {
                i++;
            }
            // 如果当前元素大于基准，交换到右边  
            if (i < j) {
                a[j] = a[i];
                j--;
            }
        }
        // 将基准元素放到正确的位置  
        a[i] = temp;
        // 分别对基准左右两边的子数组进行递归  
        QuickSort(a, low, i - 1);
        QuickSort(a, i + 1, high);
    }
}

int main() {
    DataType a[] = { 4, 2, 5, 11, 21, 18, 0, -1, 7 };
    int n = sizeof(a) / sizeof(a[0]);
    QuickSort(a, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}