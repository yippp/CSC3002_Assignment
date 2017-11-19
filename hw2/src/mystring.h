/*
 * File: MyString.h
 * --------------------------
 * This is the answer to question 5 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 * The code is tested pass in macOS using Qt Creator with Clang, but failed in Windows using Visual Studio.
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

            for (int i = 0; i < len+1; i++) {
                        data[i] = str[i];
            }
        }


        MyString(const MyString &str) { // copy constructor
            len = str.len;
            data = new char[len + 1];
            // create an empty MyString class with the same length of entry
            for (int i = 0; i < len+1; i++) {
                        data[i] = str.data[i];
            }
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


        MyString &operator = (const MyString &str) {
             // assignment operator to copy

            if (this != &str) { // if they are not the same object
                delete []data; // clean the current data
                len = str.len;
                data = new char[len + 1];
                for (int i = 0; i < len + 1; i++) {
                            data[i] = str.data[i];
                }
            }

            return *this;
        }


        MyString &operator += (const MyString &str) {
            // appends a character or a string to the end
            char *tempStr = data;
            len += str.len; // extent the length

            data = new char[len + 1];
            for (int i = 0; i < len - str.len; i++) {
                        data[i] = tempStr[i];
            }
            for (int i = 0; i < str.len; i++) {
                        data[len - str.len + i] = str.data[i];
            }
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


    MyString operator+(const MyString & s1, const MyString & s2) {
        // concatenate 2 MyString objects
        MyString s = s1;
        s += s2;
        return s;
    }


    bool operator==(const MyString& s1, const MyString& s2) {
        // relational operators ==
        if (s1.len != s2.len) return false; //when the length are not equal, they are not equal
        for (int i = 0; i < s1.len; i++) {
            if (s1.data[i] != s2.data[i]) return false;
        }
        return true;
    }


    bool operator<(const MyString& s1, const MyString& s2) {
        // relational operators <
        int i = 0;

        while ((s1.data[i] == s2.data[i]) && (i <= s1.len) && (i <= s2.len))
            i++;

        if ((s1.data[i] - s2.data[i]) < 0) { // compare which char is smaller
            return true;
        } else { // if all char compared are same, compare the length
            if (s1.len < s2.len) return true;
            else return false;
        }
    }


    bool operator<=(const MyString& s1, const MyString& s2) {
        // relational operators <=
        if((s1 < s2) || (s1 == s2))
            return true;
        else
            return false;
    }


    bool operator>(const MyString& s1, const MyString& s2) {
        // relational operators >
        if(s1 <= s2) return false;
        else return true;
    }


    bool operator!=(const MyString& s1, const MyString& s2) {
        // relational operators !=
        if(s1 == s2) return false;
        else return true;
    }


    bool operator>=(const MyString& s1, const MyString& s2) {
        // relational operators >=
        if(s1 < s2) return false;
        else return true;
    }

    ostream &operator << (ostream &os, const MyString &str) {
        // MyString objects can be written to output streams
        os << str.data;
        return os;
    }

#endif // MYSTRING_H
