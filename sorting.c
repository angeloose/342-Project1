#include "sorting.h"
#include <stdio.h>

void swap(int *a, int *b) {         // function that swaps values of a and b
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int left, int right) {     
    // helper function that places all elements smaller than the pivot
    // on the left of the pivot and all elements larger on the right of the pivot.
    // returns the index of the last element on the smaller side
    int pivot = a[left];            // makes pivot the first element
    int i = left - 1;
    int j = right + 1;

    while (1) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j)                        // if the two pointers meet
            return j;
        
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        //swap(&a[i], &a[j]);                         // swap i and j
    }
}

void quick_sort(int *a, int left, int right) {
    if (left < right) {
        int pi = partition(a, left, right);    // pi = partioning index

        quick_sort(a, left, pi);               // array from index 0 - pi
        quick_sort(a, pi + 1, right);          // array from pi to last index
    }
}

void merge_sort(int *a, int n) {
    return;

}


void printArray(int arr[], int size) {  // for testing and printing array test cases
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int arr[] = {10, 7, 8, 9, 1, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    quick_sort(arr, 0, n-1);
    printArray(arr, n);
}