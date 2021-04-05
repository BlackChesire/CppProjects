#include <iostream>
#include <string>
#ifndef EX1_BOARD_H
#define EX1_BOARD_H
using namespace std;
class Board {
public:
    string name;
    int rows;
    int cols;
    char** data;
    Board(string board_name, int rows, int cols); // creating new board
    void plot(int x,int y,int color); // ploting the board
    void plot8(int cx,int cy,int x,int y,int color); // ploting the board 8 times using the plot function
    void line(int x1,int y1,int x2,int y2,int color); // draws a line on the board
    void circle(int cx,int cy,int radius,int color); // draws a circle on the board
    void stamp(int x,int y,Board* stamp_board_name); // stamping the board with another board
    void print(); // printing the board
    void fill(int x,int y,int color); // filling the board with specfic color
    int sign(int num); // sign function
    int check_sign(char c); // checking the color number by the index

};
#endif //EX1_BOARD_H
