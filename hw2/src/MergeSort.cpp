/*
 * File: MergeSort.cpp
 * --------------------------
 * This is the answer to question 4 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include "random.h"
#include "MergeSort.h"
using namespace std;

const unsigned int numberOfinteger=30;

int q4(){ // test the merge sort based on array
    int array[numberOfinteger];
    for (int i=0; i<numberOfinteger; i++) { // create a random array
        array[i] = randomInteger(-1000,1000);
    }
    printArray(array, numberOfinteger); // print the original array
    sort(array, numberOfinteger); // sort the array
    printArray(array, numberOfinteger); // print the sorted array
    return 0;
}


void sort(int array[], int n) {
    if (n <= 1) return; // if there is only 1 element, it do not need sort

    int array1Size = n / 2;
    int array2Size = n - array1Size;
    int array1[array1Size];
    int array2[array2Size];

    for (int i=0; i<array1Size; i++){ // divive it into 2 subarraies
        array1[i] = array[i];
    }
    for (int i=0; i<array2Size; i++){
        array2[i] = array[array1Size + i];
    }

    sort(array1, array1Size); // sort 2 subarries respectively
    sort(array2, array2Size);
    memset(array, 0x0, n * sizeof(int)); // clear the array
    merge(array, array1, array2, array1Size, array2Size); // merge 2 subarries
}


void merge(int array[], int v1[], int v2[], int n1, int n2) { // merge 2 subarries
    int p1 = 0;
    int p2 = 0;
    int index = 0;

    while (p1 < n1 && p2 < n2) {
        if (v1[p1] < v2[p2]) {
            array[index] = v1[p1++];
        } else {
            array[index] = v2[p2++];
        }
        index++;
    }

    while (p1 < n1) {
        array[index] = v1[p1++];
        index++;
    }
    while (p2 < n2) {
        array[index] = v2[p2++];
        index++;
    }
}

void printArray(int array[],int n) { // print the arry
    cout << "{";
    for (int i=0; i < n; i++) {
        if(i > 0) cout << ", ";
        cout<< array[i];
    }
    cout << "}" << endl;
}
