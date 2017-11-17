/*
 * File: q2.cpp
 * --------------------------
 * This is the answer to question 2 of assignmet 2 of CSC 3002 at CUHKSZ
 * Done by Shuqian Ye, 115010269
 */

#include <iostream>
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
        //board.resize(9, 9); //the board need 4 more columns and rows for convient judgement
        remain_peg = 32;
        //g_cost = 0;
        for (int x = 0; x < 9; x++) {
            for (int y = 0; y < 9; y++) {
                if ((abs(x - 4) < 2 && abs(y - 4) < 4) || (abs(y - 4) < 2 && abs(x - 4) < 4)){
                    board[x][y] = 'x'; // if the location is on the board but not in the center, there should be a peg
                    //g_cost += abs(i - 4) + abs(j - 4); // calculate the initial cost by summing all the manhattan distance to the center
                } else {  // if the location is out of the board, let it be ' '
                    board[x][y] = ' ';
                }
            }
        }
        board[4][4] = 'o'; // the center of the board shoube be empty

//        board[3][4] = 'x';
//        board[2][4] = 'x';
//        remain_peg = 2;

//        board[2][4] = 'o'; // fixed the first step
//        board[3][4] = 'o';
//        board[4][4] = 'x';
//        remain_peg--;
//        board[3][2] = 'o';
//        board[3][3] = 'o';
//        board[3][4] = 'x';
//        remain_peg--;
//        board[1][3] = 'o';
//        board[2][3] = 'o';
//        board[3][3] = 'x';
//        remain_peg--;
//        board[1][5] = 'o';
//        board[1][4] = 'o';
//        board[1][3] = 'x';
//        remain_peg--;
//        board[3][4] = 'o';
//        board[3][2] = 'o';
//        board[3][3] = 'x';
//        remain_peg--;
//        board[3][1] = 'o';
//        board[3][2] = 'o';
//        board[3][3] = 'x';
//        remain_peg--;
//        board[3][5] = 'o';
//        board[2][5] = 'o';
//        board[1][5] = 'x';
//        remain_peg--;
//        board[3][7] = 'o';
//        board[3][6] = 'o';
//        board[3][5] = 'x';
//        remain_peg--;
//        board[4][3] = 'o';
//        board[3][3] = 'o';
//        board[2][3] = 'x';
//        remain_peg--;
//        board[1][3] = 'o';
//        board[2][3] = 'o';
//        board[3][3] = 'x';
//        remain_peg--;

        return;
    }


    bool solve(Vector<Move> &steps) {
        if (remain_peg == 1 && board[4][4] == 'x') { // reach the goal
            return true;
        }

        int priority = 4;
        while (priority >= 0) {
            for (int x = 1; x < 8; x++) {
                for (int y = 1; y < 8; y++) {
                    if ((abs(x - 4) + abs(y - 4)) == priority) {
                        if (board[x][y] == 'o') { // find out the available jump to location
                            if (y > 1) {
                                if (board[x][y - 2] == 'x' && board[x][y - 1] == 'x') {
                                    steps += Move(x, y - 2, x, y);
                                    Move move(x, y - 2, x, y);
                                    do_move(move); // try this moving
                                    if (solve(steps)) return true;
                                    revoke(move); // if it can not reach the goal, cancel the movement
                                    steps.remove(steps.size() - 1);
                                }
                            }

                            if (x > 1) {
                                if (board[x - 2][y] == 'x' && board[x - 1][y] == 'x') {
                                    steps += Move(x - 2, y, x, y);
                                    Move move(x - 2, y, x, y);
                                    do_move(move); // try this moving
                                    if (solve(steps)) return true;
                                    revoke(move); // if it can not reach the goal, cancel the movement
                                    steps.remove(steps.size() - 1);
                                }
                            }

                            if (x < 8) {
                                if (board[x + 2][y] == 'x' && board[x + 1][y] == 'x') {
                                    steps += Move(x + 2, y, x, y);
                                    Move move(x + 2, y, x, y);
                                    do_move(move); // try this moving
                                    if (solve(steps)) return true;
                                    revoke(move); // if it can not reach the goal, cancel the movement
                                    steps.remove(steps.size() - 1);
                                }
                            }

                            if (y < 8) {
                                if (board[x][y + 2] == 'x' && board[x][y + 1] == 'x') {
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
            }
            priority--;
        }
        //if (remain_peg < 2) displayBoard();
        return false; // the current board has no chance to reach the goal
    }


    void do_move(Move & move) { // apply moving in board
        remain_peg--;
        board[move.x0][move.y0] = 'o';
        board[(move.x0 + move.x1) / 2][(move.y0 + move.y1) / 2] = 'o';
        board[move.x1][move.y1] = 'x';
        return;
    }


    void revoke(Move & move) { //revoke moving in board
        remain_peg++;
        board[move.x0][move.y0] = 'x';
        board[(move.x0 + move.x1) / 2][(move.y0 + move.y1) / 2] = 'x';
        board[move.x1][move.y1] = 'o';
        return;
    }


    void display_board() {
       for (int y = 0; y < 8; y++) {
          for (int x = 0; x < 8; x++) {
             cout << board[x][y] << " ";
          }
          cout << endl;
       }
       return;
    }


private:
    char board[9][9]; // storage the infomation of the board
    int remain_peg; // storage the number of pegs remained
    //int g_cost;
    //int f_cost[4];
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
    return 0;
}
