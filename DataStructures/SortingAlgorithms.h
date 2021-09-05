#ifndef SORT_H
#define SORT_H


void insertionSort(int* arr, int length) {
    int i, j, tmp;
    for (i = 1; i < length; i++) {
        j = i;
        while (j > 0 && arr[j - 1] > arr[j]) {
            tmp = arr[j];
            arr[j] = arr[j - 1];
            arr[j - 1] = tmp;
            j--;
        }
    }
}


void swapAt(int* arr, int firstIndex, int lastIndex) {
    int temp = arr[firstIndex];
    arr[firstIndex] = arr[lastIndex];
    arr[lastIndex] = temp;
}


void bubbleSort(int* arr, int length) {
    bool sorted = false;
    while (!sorted) {
        sorted = true;
        for (int i = 0; i < length; i++) {
            if (arr[i] > arr[i + 1]) {
                swapAt(arr, i, i + 1);
                sorted = false;
            }
        }
    }
}

void selectionSort(int* arr, int length) {
    for (int p = 0; p < length - 1; p++) {
        int min = arr[p], m = p;
        for (int j = p + 1; j <= length - 1; j++) {
            if (arr[j] < min) {
                min = arr[j];
                m = j;
            }
        }
        swapAt(arr, p, m);
    }
}


void quickSort(int* arr, int length) {
    int min = 0, max = length, pivot = arr[(min + max) / 2], temp;
    while (min <= max) {
        while (arr[min] < pivot)
            min++;
        while (arr[max] > pivot)
            max--;
        if (min <= max) {
            swapAt(arr, min, max);
        }
    }
    if (max > 0)
        quickSort(arr, 0, max);
    if (min < length)
        quickSort(arr, min, length);

}


#endif // !SORT_H

