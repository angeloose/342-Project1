#ifndef SORTING_H       // include guard, prevents multiple inclusions of header files in program
#define SORTING_H

int partition(int*, int left, int right);           // quick sort helper func

void quick_sort(int *a, int left, int right);       // quick sort an array a with n elements in C

void merge(int *a, int left, int mid, int right);   // merge sort helper func

void merge_sort(int *a, int left, int right);                     // merge sort an array a with n elements in C

#endif