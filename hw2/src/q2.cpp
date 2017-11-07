/*
 * File: q2.cpp
 * --------------------------
 * This is the answer to question 2 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
#include "grid.h"
#include "vector.h"
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
        return char('@' + x0) + char('0' + y0) + " -> " + char('@' + x1) + char('0' + y1);
    }


    int x0, y0, x1, y1; // storage the posotions jump from and jump to

};


class peg_solitaire {

public:

    peg_solitaire() { // initialize the board
        board.resize(10, 10); //the board need 4 more columns and rows for convient judgement
        remain_peg = 32;
        for (int x = 0; x < 10; x++) {
            for (int y = 0; y < 10; y++) {
                bool peg ;
                if (((abs(x - 4) < 2 && abs(y - 4) < 4) || (abs(y - 4) < 2 && abs(x - 4) < 4)) && (y != 4 || x != 4)){
                    peg = true; // if the location is on the board but not in the center, there should be a peg
                } else peg = false; // the center of the board and out of board shoube be empty
            board[x][y] = peg;
            }
        }
    }


    bool solve(Vector<Move> &steps) {
        if (remain_peg == 1 && board[4][4]) { // reach the goal
            return true;
        }
        //cout << "check point" << endl;
        for (int x = 1; x < 9; x++) {
            for (int y = 1; y < 9; y++) {
                if (! board[x][y]) { // find out the available jump to location
                    if (x < 8) {
                        //cout << remain_peg << ", 1:" << x << y << endl;
                        if (board[x + 2][y] && board[x + 1][y]) {
                            //cout << 1;
                            steps += Move(x + 2, y, x, y);
                            Move move(x + 2, y, x, y);
                            do_move(move); // try this moving
                            if (solve(steps)) return true;
                            revoke(move); // if it can not reach the goal, cancel the movement
                            steps.remove(steps.size() - 1);
                        }
                    }
                    if (x > 1) {
                        //cout << remain_peg << ", 2:" << x << y << endl;
                        if (board[x - 2][y] && board[x - 1][y]) {
                            //cout << 2;
                            steps += Move(x - 2, y, x, y);
                            Move move(x - 2, y, x, y);
                            do_move(move); // try this moving
                            if (solve(steps)) return true;
                            revoke(move); // if it can not reach the goal, cancel the movement
                            steps.remove(steps.size() - 1);
                        }
                    }
                    if (y > 1) {
                        //cout << remain_peg << ", 3:" << x << y << endl;
                        if (board[x][y - 2] && board[x][y - 1]) {
                            //cout << 3;
                            steps += Move(x, y - 2, x, y);
                            Move move(x, y - 2, x, y);
                            do_move(move); // try this moving
                            if (solve(steps)) return true;
                            revoke(move); // if it can not reach the goal, cancel the movement
                            steps.remove(steps.size() - 1);
                        }
                    }
                    if (y < 8) {
                        //cout << remain_peg << ", 4:" << x << y << endl;
                        if (board[x][y + 2] && board[x][y + 1]) {
                            //cout << 4;
                            steps += Move(x, y + 2, x, y);
                            Move move(x, y + 2, x, y);
                            do_move(move); // try this moving
                            if (solve(steps)) return true;
                            revoke(move); // if it can not reach the goal, cancel the movement
                            steps.remove(steps.size() - 1);
                        }
                    }
                }
            }
        }
        return false; // the current board has no chance to reach the goal
    }


    void do_move(Move & move) { // apply moving in board
        remain_peg--;
        board[move.x0][move.y0] = false;
        board[(move.x0 + move.x1) / 2][(move.y0 + move.y1) / 2] = false;
        board[move.x1][move.y1] = true;
        return;
    }


    void revoke(Move & move) { //revoke moving in board
        remain_peg++;
        board[move.x0][move.y0] = true;
        board[(move.x0 + move.x1) / 2][(move.y0 + move.y1) / 2] = true;
        board[move.x1][move.y1] = false;
        return;
    }


    void displayBoard() {
       for (int y = 0; y < 10; y++) {
          for (int x = 0; x < 10; x++) {
             cout << ' ';
             if (board[x][y]) {
                 cout << 'x';
             } else {
                 cout << 'o';
             }
          }
          cout << endl;
       }
    }


private:
    Grid<char> board; // storage the infomation of the board
    int remain_peg; // storage the number of pegs remained
};


int q2(){
    peg_solitaire puzzle;
    puzzle.displayBoard();
    Vector<Move> steps;
    if (puzzle.solve(steps)) {
        cout << "The steps of solution are:" << endl;
        for (int i = 0; i < steps.size(); i++) {
            cout << steps[i].to_string() << endl;
        }
    } else {
        cout << "There is no solution." << endl;
    }
    return 0;
}

