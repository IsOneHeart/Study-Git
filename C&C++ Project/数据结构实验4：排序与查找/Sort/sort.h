#ifndef elementType
#define elementType int
#endif

struct count {
    int compare;
    int move;
};

void createHeap(elementType array[], int n, int h, count count) {
    int i = h, j = 2 * i + 1, flag = 0;
    elementType temp = array[i];
    while (j < n && flag != 1) {
        if (j < n - 1 && array[j] > array[j + 1])
            j++;
        if (temp < array[j])
            flag = 1;
        else {
            array[i] = array[j];
            i = j;
            j = 2 * i + 1;
            count.move++; //移动次数增加
        }
        count.compare += 3; //比较次数增加(while*1+if*2)
    }
    array[i] = temp;
    count.move++; //移动次数增加
}

void initCreateHeap(elementType array[], int n, count count) {
    for (int i = (n - 2) / 2; i >= 0; i--) {
        createHeap(array, n, i, count);
        count.compare++; //比较次数增加
    }
}

count heapSort(elementType array[], int n) {
    count count = {0, 0};
    elementType temp;
    initCreateHeap(array, n, count);
    for (int i = n - 1; i > 0; i--) {
        temp = array[0];
        array[0] = array[i];
        array[i] = temp;
        count.move++; //移动次数增加
        createHeap(array, i, 0, count);
        count.compare++; //比较次数增加
    }
    return count;
}

count quickSort(elementType array[], int start, int end, count count) {
    if (start >= end) return count;
    count.compare++;
    int i = start, j = end;
    elementType temp = array[start];
    while (i < j) {
        while (i < j && array[j] <= temp) {
            j--;
            count.compare++;
        }
        if (i < j) {
            array[i++] = array[j];
            count.move++;
        }
        while (i < j && array[i] > temp) {
            i++;
            count.compare++;
        }
        if (i < j) {
            array[j--] = array[i];
            count.move++;
        }
        count.compare += 3;
    }
    array[i] = temp;
    count = quickSort(array, start, i - 1, count);
    count = quickSort(array, i + 1, end, count);
    return count;
}

count quickSort(elementType array[], int start, int end) {
    //函数重载
    count count = {0, 0};
    return quickSort(array, start, end, count);
}

count mergeArray(elementType array[], int start, int mid, int end, count count) {
    elementType temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid && j <= end) {
        if (array[i] < array[j])
            temp[k++] = array[i++];
        else
            temp[k++] = array[j++];
        count.compare++; //比较次数增加
        count.move++;
    }
    while (i <= mid) {
        temp[k++] = array[i++];
        count.compare++; //比较次数增加
        count.move++;
    }
    while (j <= end) {
        temp[k++] = array[j++];
        count.compare++; //比较次数增加
        count.move++;
    }
    for (i = start, k = 0; i <= end; i++, k++) {
        array[i] = temp[k];
        count.compare++; //比较次数增加
        count.move++;
    }
    return count;
}

count mergeSort(elementType array[], int start, int end, count count) {
    if (start < end) {
        int mid = (start + end) / 2;
        count = mergeSort(array, start, mid, count);
        count = mergeSort(array, mid + 1, end, count);
        count = mergeArray(array, start, mid, end, count);
    }
    return count;
}

count mergeSort(elementType array[], int start, int end) {
    //函数重载
    count count = {0, 0};
    return mergeSort(array, start, end, count);
}

