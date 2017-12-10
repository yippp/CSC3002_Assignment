/*
 * File: p1.cpp
 * --------------------------
 * This is the program used to run class EditoirBuffer in question 1 of assignmet 3 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <cctype>
#include <iostream>
#include "buffer.h"
#include "console.h"
#include "foreach.h"
#include "simpio.h"
using namespace std;

/* Function prototypes */

void executeCommand(EditorBuffer & buffer, string line);
void displayBuffer(EditorBuffer & buffer);
void printHelpText();

/*
* Function: q1
* Usage: q1();
* ------------------------
* Test the code for question 1.
*/

void p1() {
    EditorBuffer buffer;
    while (true) {
        string cmd = getLine("*");
        if (cmd == "Q" || cmd == "Q") break;
        if (cmd != "") executeCommand(buffer, cmd);
    }
}

/*
 * Function: executeCommand
 * Usage: executeCommand(buffer, line);
 * ------------------------------------
 * Executes the command specified by line on the editor buffer.
 */

void executeCommand(EditorBuffer & buffer, string line) {
    switch (toupper(line[0])) {
        case 'I':
        for (int i = 1; i < line.length(); i++) {
            buffer.insertCharacter(line[i]);
        }
        displayBuffer(buffer);
        break;

        case 'D': buffer.deleteCharacter(); displayBuffer(buffer); break;
        case 'F': buffer.moveCursorForward(); displayBuffer(buffer); break;
        case 'B': buffer.moveCursorBackward(); displayBuffer(buffer); break;
        case 'J': buffer.moveCursorToStart(); displayBuffer(buffer); break;
        case 'E': buffer.moveCursorToEnd(); displayBuffer(buffer); break;
        case 'H': printHelpText(); break;
        // comment the next line due to the programm is needed to run for remaining questions
        //case 'Q': exit(0);

        case 'C': {
            int count = 0;
            int i = 1;
            while (isdigit(line[i])) {
                   count = 10 * count + line[1] - '0';
                   i++;
            }
            buffer.copy(count);
            displayBuffer(buffer);
            break;
        }
//      // commtented due to better run with other questions code together
//        {
//            stringstream ss(line[1]);
//            int num;
//            ss >> num;
//            buffer.copy(num);
//            break;
//        }

        case 'P':
        buffer.paste();
        displayBuffer(buffer);
        break;

        default:  cout << "Illegal command" << endl; break;
   }
}

/*
 * Function: displayBuffer
 * Usage: displayBuffer(buffer);
 * -----------------------------
 * Displays the state of the buffer including the position of the cursor.
 */

void displayBuffer(EditorBuffer & buffer) {
   string str = buffer.getText();
   for (int i = 0; i < str.length(); i++) {
      cout << " " << str[i];
   }
   cout << endl;
   cout << string(2 * buffer.getCursor(), ' ') << "^" << endl;
}

/*
 * Function: printHelpText
 * Usage: printHelpText();
 * -----------------------
 * Displays a message showing the legal commands.
 */

void printHelpText() {
   cout << "Editor commands:" << endl;
   cout << "  Iabc  Inserts the characters abc at the cursor position" << endl;
   cout << "  F     Moves the cursor forward one character" << endl;
   cout << "  B     Moves the cursor backward one character" << endl;
   cout << "  D     Deletes the character after the cursor" << endl;
   cout << "  J     Jumps to the beginning of the buffer" << endl;
   cout << "  E     Jumps to the end of the buffer" << endl;
   cout << "  H     Prints this message" << endl;
   cout << "  Q     Exits from the editor program" << endl;
   cout << "  C2    Copy the next 2 characters" << endl;
   cout << "  P     Paste the last copied characters." << endl;
}
