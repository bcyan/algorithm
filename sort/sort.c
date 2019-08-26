#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "sort.h"

int swap(int *a ,int *b) {
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

int quick_sort(int *arr, int len) {
    quick_sort_recursive(arr, 0, len - 1);
}

int quick_sort_recursive(int *arr, int start, int end) {
    int pivot;
    if (start >= end) {
        return;
    }
    pivot = partition(arr, start, end);
    quick_sort_recursive(arr, start, pivot-1);
    quick_sort_recursive(arr, pivot+1, end);
}

int partition(int *arr, int start, int end) {
    int i, j;
    i = start;
    for (j = start; j < end; j++) {
        if (arr[j] < arr[end]) {
            if (i != j)
                swap(&arr[i], &arr[j]);
            i++;
        }
    }
    swap(&arr[i], &arr[end]);
    return i;
}

int merge(int *arr, int start, int mid,  int end) {
    int *tmp;
    int i, j, k;
    tmp = (int *)malloc((end - start + 1) * sizeof(int));
    if (!tmp) {
        printf("require memory of tmp[] failed!\n");
        return -1;
    }
    for (i = start, j = mid + 1, k = 0; (i <= mid) && (j <= end);){
        if (arr[i] > arr[j]){
            tmp[k++] = arr[j++];
        }
        else{
            tmp[k++] = arr[i++];
        }
    }
    if (i == (mid + 1)){
        while(j <= end){
            tmp[k++] = arr[j++];
        }
    }
    else{
        while(i <= mid){
            tmp[k++] = arr[i++];
        }
    }
    memcpy(arr + start, tmp, (end - start + 1) * sizeof(int));
    free(tmp);
}

int merge_sort_recursion(int *arr, int start, int end) {
    int mid;
    if (start >= end)
        return;
    mid = (start + end) / 2;
    printf("start=%d, mid=%d, end=%d\n", start, mid, end);
    merge_sort_recursion(arr, start, mid);
    merge_sort_recursion(arr, mid + 1, end);
    merge(arr, start, mid, end);

}

int merge_sort(int *arr, int len) {
    merge_sort_recursion(arr, 0, len - 1);
}

int insertion_sort(int arr[], int len) {
    int i, j;
    for (i = 1; i < len; i++) {
        int value = arr[i];
        j = i - 1;
        while ((j >= 0) && (value < arr[j])) {
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = value;
    }
}

int selection_sort(int arr[], int len) {
    int i, j, min;
    for (i = 0; i < len - 1; i++) {
        min = i;
        for (j = i + 1; j < len; j++) {
            if (arr[j] < arr[min]) {
                min = j;
            }
        }
        swap(&arr[min], &arr[i]);
    }
}

int bubble_sort(int arr[], int len) {
    int temp, i, j;
    for (i = 0; i < len; i++) {
        for (j = i+1; j < len; j++) {
            if (arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    int arr[] = {0, 22, 34, 3, 32, 82, 55, 89, 50, 37, 5, 64, 35, 9, 70};
    int len = sizeof(arr)/sizeof(*arr);
    int i;
    printf("the original array:\n");
    for (i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    //bubble_sort(arr, len);
    //selection_sort(arr, len);
    //insertion_sort(arr, len);
    //merge_sort(arr, len);
    quick_sort(arr, len);
    printf("\nthe sorted array:\n");
    for (i = 0; i < len; i++) {
        printf("%d\t", arr[i]);
    }
    printf("\n");
    return 0;
}
