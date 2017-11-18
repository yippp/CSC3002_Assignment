/*
 * File: MyString.h
 * --------------------------
 * This is the answer to question 5 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 * The code is tested pass in macOS using Clang, but failed in Windows using Visual Studio.
 */
#ifndef __MYSTRING_H__
#define __MYSTRING_H__

#include <iostream>

using namespace std;
    class MyString {
    public:
        MyString() {
            // create an empty MyString class
            data = NULL;
            len = 0;
        }

        MyString(const char *str) {
            // create a MyString with initial content from char
            len = strlen(str);
            data = new char[len + 1];
            // create an empty MyString class with the same length of entry

            strcpy(data, str);
        }

        MyString(const MyString &str) { // copy constructor
            len = str.len;
            data = new char[len + 1];
            // create an empty MyString class with the same length of entry
            strcpy(data, str.data);
        }

        ~MyString(){ // destructor
            if (NULL != data) {
                delete []data;
                data = NULL;
            }
        }

        unsigned int length(){
            // returns the number of characters in the string
            return len;
        }

        /*运算符重载*/
        MyString &operator = (const MyString &str) {
             // assignment operator to copy

            if (this != &str) { // if they are not the same object
                delete []data; // clean the current data
                len = str.len;
                data = new char[len + 1];
                strcpy(data, str.data);
            }

            return *this;
        }

        MyString &operator += (const MyString &str) {
            // appends a character or a string to the end
            char *tempStr = data;
            len += str.len; // extent the length

            data = new char[len + 1];
            strcpy(data, tempStr);
            strcat(data, str.data);
            delete []tempStr;

            return *this;
        }

        char &operator[] (const size_t index) {
            // returns by reference the character at index position of this MyString
            return data[index];
        }

        string & toString() {
            // converts a MyString to a C++ string.
            string str = "";
            for (int i = 0; i < len; i++) str += data[i];
            return str;
        }

        MyString substr(unsigned int start, unsigned int n=1) {
            // returns a substring of the current string object from the index start woth length n
            if ((start + n) > (len - 1)) n = len - start; //

            char * tempChar;
            tempChar = new char[n];
            for (int i = 0; i < n; i++) { // add the char needed one by one
                tempChar[i] = data[i + start];
            }
            MyString sub(tempChar); // create an empty substring
            delete tempChar;
            return sub;
        }

        friend MyString operator+ (const MyString &, const MyString &); // concatenate 2 MyString objects
        friend bool operator== (const MyString &, const MyString &); // relational operators
        friend bool operator!= (const MyString &, const MyString &);
        friend bool operator< (const MyString &, const MyString &);
        friend bool operator<= (const MyString &, const MyString &);
        friend bool operator> (const MyString &, const MyString &);
        friend bool operator>= (const MyString &, const MyString &);
        friend ostream &operator<< (std::ostream &, const MyString &); // MyString objects can be written to output streams

        unsigned int len;
        char *data;
    };


    MyString operator + (const MyString &s1, const MyString &s2) {
        MyString temp;

        temp.len = s1.len + s2.len;
        temp.data = new char[temp.len + 1];
        strcpy(temp.data, s1.data);
        strcat(temp.data, s2.data);

        return temp;
    }

    bool operator == (const MyString &s1, const MyString &s2) {
        // concatenate 2 MyString objects
        return (strcmp(s1.data, s2.data) == 0);
    }

    bool operator != (const MyString &s1, const MyString &s2) {
        // relational operators !=
        return (strcmp(s1.data, s2.data) != 0);
    }

    bool operator < (const MyString &s1, const MyString &s2) {
        // relational operators <
        return (strcmp(s1.data, s2.data) < 0);
    }

    bool operator <= (const MyString &s1, const MyString &s2) {
        // relational operators <=
        return (strcmp(s1.data, s2.data) <= 0);
    }

    bool operator > (const MyString &s1, const MyString &s2) {
        // relational operators >
        return (strcmp(s1.data, s2.data) > 0);
    }

    bool operator >= (const MyString &s1, const MyString &s2) {
        // relational operators >=
        return (strcmp(s1.data, s2.data) >= 0);
    }

    ostream &operator << (ostream &os, const MyString &str) {
        // MyString objects can be written to output streams
        os << str.data;
        return os;
    }

#endif // MYSTRING_H
