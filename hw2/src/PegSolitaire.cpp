/*
 * File: q2.cpp
 * --------------------------
 * This is the answer to question 2 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 *
 * Running time: about 30 seconds using Intel Core i5 5257U with 2.7 GHz main frequency.
 */

#include <iostream>
#include "vector.h"
#include "grid.h"
#include <cmath>

using namespace std;

class Move { // move in peg solitaire

public:

    Move() {
        //empty
    }


    Move(int x_start, int y_start, int x_end, int y_end){
        // x_start and y_start mean the position jump from
        // x_end and y_end mean the position jump to
        x0 = x_start;
        y0 = y_start;
        x1 = x_end;
        y1 = y_end;
    }


    string to_string() { // output the steps to string
        string str = "";
        str += char(64 + x0);
        str += char(48 + y0);
        str += "->";
        str += char(64 + x1);
        str += char(48 + y1);
        return str;
    }

    int x0, y0, x1, y1; // storage the posotions jump from and jump to

};


class peg_solitaire {

public:

    peg_solitaire() { // initialize the board
        board.resize(9, 9); //the board need 4 more columns and rows for convient judgement
        remain_peg = 32;
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if ((abs(x - 4) < 2 && abs(y - 4) < 4) || (abs(y - 4) < 2 && abs(x - 4) < 4)){
                    board[x][y] = 'x'; // if the location is on the board but not in the center, there should be a peg
                } else {  // if the location is out of the board, let it be ' '
                    board[x][y] = ' ';
                }
            }
        }
        board[4][4] = 'o'; // the center of the board shoube be empty
        return;
    }


    bool solve(Vector<Move> &steps) {
        if (remain_peg == 1 && board[4][4] == 'x') { // reach the goal
            return true;
        }

        Vector<Move> possable_move;
        find_possable_move(possable_move);

        for (int i = 0; i < possable_move.size(); i++){
            // try all the possable move one by one
            Move move = possable_move[i];
            do_move(move); // tring the move
            steps += move;
            if (solve(steps)) {
                // if solved return true
                return true;
            } else {
                //if failed, undo the move
                steps.remove(steps.size() - 1);
                undo_move(move);
            }
        }
        return false;
    }

    void find_possable_move(Vector<Move> & possable_move) {
        //possable_move.clear();
        // find all possable move in the board
        for (int x = 1; x < 8; x++) {
            for (int y = 1; y < 8; y++) {
               if (board[x][y] == 'x') {
                  if (board[x - 1][y] == 'x' && board[x - 2][y] == 'o') {
                      possable_move += Move(x, y, x - 2, y);
                  }
                  if (board[x + 1][y] == 'x' && board[x + 2][y] == 'o') {
                      possable_move += Move(x, y, x + 2, y);
                  }
                  if (board[x][y - 1] == 'x' && board[x][y - 2] == 'o') {
                      possable_move += Move(x, y, x, y - 2);
                  }
                  if (board[x][y + 1] == 'x' && board[x][y + 2] == 'o') {
                      possable_move += Move(x, y, x, y + 2);
                  }
               }
            }
        }
    }


    void do_move(Move & move) { // apply moving in board
        remain_peg--;
        board[move.x0][move.y0] = 'o';
        board[(move.x0 + move.x1) / 2][(move.y0 + move.y1) / 2] = 'o';
        board[move.x1][move.y1] = 'x';
        return;
    }


    void undo_move(Move & move) { //undo moving in board
        remain_peg++;
        board[move.x0][move.y0] = 'x';
        board[(move.x0 + move.x1) / 2][(move.y0 + move.y1) / 2] = 'x';
        board[move.x1][move.y1] = 'o';
        return;
    }


    void display_board() {
        // print the board
       for (int y = 0; y < 8; y++) {
          for (int x = 0; x < 8; x++) {
             cout << board[x][y] << " ";
          }
          cout << endl;
       }
       return;
    }


private:
    Grid<char> board; // storage the infomation of the board
    int remain_peg; // storage the number of pegs remained
};


int q2(){
    peg_solitaire puzzle;
    puzzle.display_board();
    Vector<Move> steps;
    if (puzzle.solve(steps)) {
        cout << "The steps of solution are:" << endl;
        for (int i = 0; i < steps.size(); i++) {
            cout << steps[i].to_string() << endl;
        }
    } else {
        cout << "There is no solution." << endl;
    }
    puzzle.display_board();
    return 0;
}
