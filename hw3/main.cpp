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
