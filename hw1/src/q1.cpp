/*
 * File: q1.cpp
 * --------------------------
 * This is the answer to question 1 of assignmet 1 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include "gwindow.h" // for GWindow
using namespace std;

int q1() {
    //Simulates flipping a coin repeatedly and continues until three consecutive heads are tossed.
    int heads = 0;
    int count = 0;

    while (heads<3){
        count += 1;
         if (randomBool()){
             cout << "heads" << endl;
             heads += 1; // count the number of heads continuously
         } else {
             heads = 0; // reset the number of heads continuously
             cout << "tails" << endl;
         }
    }
    cout << "It tooks " << count << " flips to get 3 consecutive heads." << endl;
    return 0;
}
