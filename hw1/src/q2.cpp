/*
 * File: q2.cpp
 * --------------------------
 * This is the answer to question 2 of assignmet 1 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
using namespace std;

int findDNAMatch(string s1, string s2, int start=0){
   /* Returns the first position at which the DNA strand s1 can attach to the strand s2.
      As in thefind method for the string class,
      the optional start parameter indicates the index position at which the search should start.
      If there is no match, findDNAMatch will return –1.
    */

    string s3 = ""; // s3 is the DNA strand should matched in s2
    for (int i=0; i!=s1.length(); i++){
        if (s1.at(i) == 'A'){
            s3 += 'T';
        } else if(s1.at(i) == 'T'){
            s3 += 'A';
        } else if(s1.at(i) == 'C'){
            s3 += 'G';
        } else {
            s3 += 'C';
        }
    }
    if (s2.find(s3, start)==string::npos){
        return -1;
    } else {
        return s2.find(s3, start);
    }
}


int q2() {
    string s1_for_test="TGC";
    string s2_for_test="TAACGGTACGTC";
    cout << "The return of findDNAMatch(" << s1_for_test << ", " << s2_for_test << ") is:" << endl;
    cout << findDNAMatch(s1_for_test, s2_for_test) << endl;
    return 0;
}
