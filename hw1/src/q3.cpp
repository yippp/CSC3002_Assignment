/*
 * File: q3.cpp
 * --------------------------
 * This is the answer to question 3 of assignmet 1 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include <fstream>
#include "console.h"
#include "gwindow.h" // for GWindow
using namespace std;

int q3() {
    // Replece the tab by using space in q3file.txt and output to file q3output.txt.
    ifstream infile;
    infile.open("q3file.txt");
    ofstream fout;
    fout.open("q3output.txt");

    string line="";
    int pos=0;
    while (getline(infile, line)){
        int start=0;
        pos = line.find("\t", 0); //find out the position of the tab
        while (pos!=string::npos){
                string space(8-pos+start,' '); // the space to replace the tab
                line.replace(pos, 1, space);
                start = pos + space.length(); // the start position of every 8 columns
                pos = line.find("\t", 0);
        }
        fout << line << endl;
    }

    infile.close();
    fout.close();
    return 0;
}
