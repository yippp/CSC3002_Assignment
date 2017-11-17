/*
 * File: SearchComparison.cpp
 * --------------------------
 * This is the answer to question 3 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include <iomanip>
#include "random.h"
#include "vector.h"
using namespace std;


int binarySearch(int key, Vector<int> &vec, int p1, int p2, int &comparisons) {
   // Searches for the specified key in the Vector<int> vec, looking only at indices between p1 and p2, inclusive.
   // The function returns the index of a matchingelement or -1 if no match is found.
   if (p1 > p2) return -1; // return -1 if no match is found.
   int mid = (p1 + p2) / 2;

   comparisons++; // the number of comparisons increse one
   if (key == vec[mid]) return mid;  // if the element is in the mid of the vector, directly return it
   if (key < vec[mid]) { // if the element is smaller than the mid of the vector, search it in the left part of vector
      return binarySearch(key, vec, p1, mid - 1, comparisons);
   } else { // if the element is larger than the mid of the vector, search it in the right part of vector
      return binarySearch(key, vec, mid + 1, p2, comparisons);
   }
}


int findInSortedVector(int key, Vector<int> &vec, int &comparisons) {
    // find out the key element in the whole vector by calling binarySearch
    return binarySearch(key, vec, 0, vec.size() - 1, comparisons);
}


int linearSearch(int key, Vector<int> vec, int &comparisons) {
    // Searches for the specified key in the Vector<int> vec one by one.
    // The function returns the index of a matchingelement or -1 if no match is found.
   int n = vec.size();

   for (int i = 0; i < n; i++) {
      comparisons++; // the number of comparisons increse one
      if (key == vec[i]) return i;
   }
   return -1; // return -1 if cannot find a matched element
}


void test(int n, int trails) {
    // find a random interger in a vetor with length n in several trails.
    // Output the average comparasions both in linear and binary search.
    Vector<int> vec;
    int totalLinear = 0; // store the number of total comparison times in all trails
    int totalBinary = 0;

    for (int i = 0; i < n; i++) {
        vec.add(i); // create a sorted vector
    }

    for (int i = 0; i < trails; i++) {
        int key;
        key = randomInteger(0, n); // select an interger that needed to search
        linearSearch(key, vec, totalLinear);
        findInSortedVector(key, vec, totalBinary);
    }

    // calculate the average comparations
    double avgLinear = (double)totalLinear / trails;
    double avgBinary = (double)totalBinary / trails;

    cout << setw(7) << n << "  | " << // print the result
            setw(7) << setiosflags(ios_base::fixed) << setprecision(1) << avgLinear << "  | " <<
            setw(6) << setiosflags(ios_base::fixed) << setprecision(1) << avgBinary << "  | " <<
            endl;
}


int q3() {
    // print the header of the table
    cout << "    N    |  Linear  |  Binary  " << endl;
    cout << "---------+----------+----------" << endl;

    int trails = 20; // the number of trails
    test(10, trails);
    test(50, trails);
    test(100, trails);
    test(500, trails);
    test(1000, trails);
    test(5000, trails);
    test(10000, trails);
    test(50000, trails);
    test(100000, trails);
    return 0;
}

