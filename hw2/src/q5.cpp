#include "mystring.h"
#include <iostream>
using namespace std;

int q5() {
    // using to test MyString
    MyString str1("string1");
    MyString str2("string2");
    MyString str3 = str1;
    MyString str4;
    MyString str5("string5");
    MyString str6("string6");

    str6 = str1.substr(3,7);
    str5 += str1;
    str4 = str2 + str1;


    cout << "str1: " << str1 << endl;
    cout << "str1.toString(): " << str1.toString() << endl;
    cout << "str2: " << str2 << endl;
    cout << "str3: " << str3 << endl;
    cout << "str4: " << str4 << endl;
    cout << "str5: " << str5 << endl;
    cout << "str6: " << str6 << endl;
    cout << "len of str 5: " << str5.length() << endl;

    cout << (str1 > str5 ? 1 : 0) << endl;
    cout << (str1 >= str5 ? 1 : 0) << endl;
    cout << (str1 < str5 ? 1 : 0) << endl;
    cout << (str1 <= str5 ? 1 : 0) << endl;
    cout << (str1 == str5 ? 1 : 0) << endl;
    cout << (str1 != str5 ? 1 : 0) << endl;

    return 0;
}
