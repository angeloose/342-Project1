// Tools used: Visual Studio Code, Discord, GitHub, C, Haskell, GeeksForGeeks.org, ChatGPT


#include "sorting.h"
#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {         // function that swaps values of a and b
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int *a, int left, int right) {     
    // helper function that places all elements smaller than the pivot
    // on the left of the pivot and all elements larger on the right of the pivot.
    // returns the index of the last element on the smaller side

    int pivot = a[left];                            // makes pivot the first element
    int i = left - 1;
    int j = right + 1;

    while (1) {
        do {
            i++;
        } while (a[i] < pivot);

        do {
            j--;
        } while (a[j] > pivot);

        if (i >= j)                                 // if the two pointers meet
            return j;
        
        swap(&a[i], &a[j]);                         // swap i and j
    }
}

void quick_sort(int *a, int left, int right) {
    if (left < right) {
        int pi = partition(a, left, right);    // pi = partioning index

        quick_sort(a, left, pi);               // array from index 0 - pi
        quick_sort(a, pi + 1, right);          // array from pi to last index
    }
}

void merge(int *a, int left, int mid, int right) {   // merges two subarrays
    int l, r, index;
    int templ_size = mid - left + 1;
    int tempr_size = right - mid;

    int *leftArray = (int*)malloc(templ_size * sizeof(int));    // temp arrays
    int *rightArray =(int*)malloc(tempr_size * sizeof(int));

    // if (leftArray == NULL || rightArray == NULL) {              // check if memory is dynamically allocated
    //    printf("Memory not allocated.\n"); 
    //} 
    //else { printf("Memory successfully allocated using ""malloc.\n"); }

    // fill temp arrays
    for (l = 0; l < templ_size; l++) 
        leftArray[l] = a[left + l];
    for (r = 0; r < tempr_size; r++)
        rightArray[r] = a[mid + 1 + r];

    // merge temp arrays
    l = 0;
    r = 0;
    index = left;
    
    while (l < templ_size && r < tempr_size) {
        if (leftArray[l] <= rightArray[r]) {        // add left array if left element bigger than right
            a[index] = leftArray[l];
            l++;
        }  
        else {                                      // add right array if right element bigger than left
            a[index] = rightArray[r];
            r++;
        }
        index++;
    }
    // add remaining elements
    while (l < templ_size) {
        a[index] = leftArray[l];
        l++;
        index++;
    }
    while (r < tempr_size) {
        a[index] = rightArray[r];
        r++;
        index++;
    }
}

    
void merge_sort(int *a, int left, int right) {
    if (left < right) {

        int mid = left + (right - left) / 2;    // calculate middle point

        // sort first and second halves
        merge_sort(a, left, mid);
        merge_sort(a, mid + 1, right);

        merge(a, left, mid, right);             // merges sorted halves together
    }

}


void printArray(int arr[], int size) {  // for testing and printing array test cases
    for (int i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    // test cases
    int arr[] = {10, 7, 8, 9, 1, 5};
    int arr2[] = {8, 3, 4, 1, 10, 5, 4};
    int arr3[] = {31, 20, 49, 11, 44, 99, 8};
    int arr4[] = {10, 7, 8, 9, 1, 5};
    int arr5[] = {4, 9, 8, 3, 11, 1, 2};
    int arr6[] = {22, 99, 7, 53, 67, 30, 2};
    int arr7[] = {NULL};

    // testing test cases. i couldt have done this in a more efficient and cleaner manner, but i did not
    // have enough time to learn how to do so

    // quick sort
    printf("Printing quick_sort test case: ");
    printArray(arr, sizeof(arr) / sizeof(arr[0]));
    quick_sort(arr, 0, (sizeof(arr) / sizeof(arr[0])) - 1);
    printArray(arr, sizeof(arr) / sizeof(arr[0]));

    printf("Printing quick_sort test case: ");
    printArray(arr2, sizeof(arr2) / sizeof(arr2[0]));
    quick_sort(arr2, 0, (sizeof(arr2) / sizeof(arr2[0])) - 1);
    printArray(arr2, sizeof(arr2) / sizeof(arr2[0]));

    printf("Printing quick_sort test case: ");
    printArray(arr3, sizeof(arr3) / sizeof(arr3[0]));
    quick_sort(arr3, 0, (sizeof(arr3) / sizeof(arr3[0])) - 1);
    printArray(arr3, sizeof(arr3) / sizeof(arr3[0]));

    printf("Printing quick_sort test case: ");     // null/empty test case
    printArray(arr7, sizeof(arr7) / sizeof(arr7[0]));
    quick_sort(arr7, 0, (sizeof(arr7) / sizeof(arr7[0])) - 1);
    printArray(arr7, sizeof(arr7) / sizeof(arr7[0]));
    
    // merge sort
    printf("Printing merge_sort test case: ");
    printArray(arr4, sizeof(arr4) / sizeof(arr4[0]));
    merge_sort(arr4, 0, (sizeof(arr4) / sizeof(arr4[0])) - 1);
    printArray(arr4, sizeof(arr4) / sizeof(arr4[0]));

    printf("Printing merge_sort test case: ");
    printArray(arr5, sizeof(arr5) / sizeof(arr5[0]));
    merge_sort(arr5, 0, (sizeof(arr5) / sizeof(arr5[0])) - 1);
    printArray(arr5, sizeof(arr5) / sizeof(arr5[0]));

    printf("Printing merge_sort test case: ");
    printArray(arr6, sizeof(arr6) / sizeof(arr6[0]));
    merge_sort(arr6, 0, (sizeof(arr6) / sizeof(arr6[0])) - 1);
    printArray(arr6, sizeof(arr6) / sizeof(arr6[0]));

    printf("Printing merge_sort test case: ");     // null/empty test case
    printArray(arr7, sizeof(arr7) / sizeof(arr7[0]));
    merge_sort(arr7, 0, (sizeof(arr7) / sizeof(arr7[0])) - 1);
    printArray(arr7, sizeof(arr7) / sizeof(arr7[0]));


    //quick_sort(arr, 0, n1-1);
    //printArray(arr, n1);
    //merge_sort(arr2, 0, n2-1);
    //printArray(arr2, n2);
}