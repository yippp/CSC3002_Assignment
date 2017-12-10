/*
 * File: main.cpp
 * --------------------------
 * This is the main function to run questions of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include "console.h"
#include "gwindow.h" // for GWindow
#include "simpio.h"  // for getLine
#include "vector.h"  // for Vector

#include "p1.cpp";
#include "p2.cpp";
#include "p3.cpp";
#include "p4.cpp";
#include "p5.cpp";

int main() {
    cout << "===== Question 1 =====" << endl;
    p1();

    cout << endl << "===== Question 2 =====" << endl;
    p2();

    cout << endl << "===== Question 3 =====" << endl;
    p3();

    cout << endl << "===== Question 4 =====" << endl;
    p4();

    cout << endl << "===== Question 5 =====" << endl;
    p5();

    return 0;
}
