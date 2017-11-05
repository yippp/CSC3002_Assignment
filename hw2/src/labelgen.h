/*
 * File: labelgen.h
 * --------------------------
 * This is the answer to question 1 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#ifndef LABELGEN_H
#define LABELGEN_H

#include <string>

class LabelGenerator { // a class used to generate a sequence of label

public:

    // creat a new LabelGenerator obeject that can return strings includs the input prefix plus a number
    // which the initial value is input as interger
    LabelGenerator();
    LabelGenerator(std::string prefix, int initial);

    // return the next label with an incresing number
    std::string nextLabel();

private:

    int nextIndex; // the index of the next label
    std::string _prefix; // the prefix

};

#endif
