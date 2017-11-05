/*
 * File: q5.cpp
 * --------------------------
 * This is the answer to question 5 of assignmet 1 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include "stack.h"
#include "queue.h"
using namespace std;

string check(string s){
    // Check whether the bracketing operators (parentheses, brackets, and curly braces) in a string are properly matched.
    string brackets="";
    for (int i=0; i!=s.length(); i++){ // put all the brackets into the string b
        if (s[i] == '(' || s[i] == '[' || s[i] == '{' || s[i] == ')' || s[i] == ']' || s[i] == '}'){
            brackets += s[i];
        }
    }

    for (int i=0; i!=brackets.length(); i++){
        if (brackets[i] == ')' || brackets[i] == ']' || brackets[i] == '}'){
            bool match = false;
            for (int j=i; j!=-1; j -= 1){
                // search the left matched bracked from the current posistion of the right bracket to left top
                if ((brackets[i] == ')' && brackets[j] =='(') || (brackets[i] == ']' && brackets[j] =='[') || (brackets[i] == '}' && brackets[j] =='{')){
                    // earse the matched brackets pair
                    brackets.replace(i, 1, " ");
                    brackets.replace(j, 1, " ");
                    match = true;
                    break;
                }
            }
            // cannot find the matched bracket
            if (!match) return "It is not properly matched.";
        }
    }
    while (brackets.find(" ") != string::npos){
        brackets.erase(brackets.find(" "), 1);
    }

    if (brackets.length() != 0){
        // if there is remaining brackets
        return "It is not properly matched.";
    } else return "It is properly matched.";
}


int q5() {
    string test = "{ s = 2 * (a[2] + 3); x = (1 + (2)); }";
    cout << "The test result for string \"" << test << "\" is:" << endl;
    cout << check(test) << endl;
    return 0;
}
