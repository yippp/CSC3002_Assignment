/*
 * File: labelgen.cpp
 * --------------------------
 * This is the answer to question 1 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include "labelgen.h"
#include <string>
using namespace std;

LabelGenerator::LabelGenerator() {
    //empty
}


LabelGenerator::LabelGenerator(string prefix, int initial) {
    _prefix = prefix;
    nextIndex = initial;
}


string LabelGenerator::nextLabel() {
    return _prefix + to_string(nextIndex++);
}
