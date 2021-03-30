#include <iostream>
#include "Board.h"
#include <cstdlib>
using namespace std;
const char colors[] = {' ', '.', '+', '*', '/', '\\', '|', '-'}; //defining colors map
Board::Board(string board_name, int rows, int cols) {
    this->name = board_name;
    this->rows = rows;
    this->cols = cols;
    this->data = new char *[rows];
    for (int i = 0; i < rows; ++i) {
        this->data[i] = new char[cols];
    }
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; ++j) {
            this->data[i][j] = colors[0];
        }
    }

}

void Board::print() {
    for (int i = 0; i < this->rows; i++) {
        for (int j = 0; j < this->cols; ++j) {
            cout << this->data[i][j];
        }
        cout << endl;
    }
}

void Board::plot(int x, int y, int color) {
    if (x >= 0 && x< this->cols  && y >= 0 &&y <  this->rows ) {
        this->data[y][x] = colors[color];
    }
}

void Board::line(int x1, int y1, int x2, int y2, int color) {
    bool  plotyx = false;
    if (abs(x2-x1) < abs(y2-y1)){
        swap(x1,y1);
        swap(x2,y2);
        plotyx = true;
    }
    if (x2<x1){
        swap(x1,x2);
        swap(y1,y2);
    }
    int dx = x2 - x1;
    int dy = abs(y2 - y1);
    int sy = sign(y2-y1);
    int e = -dx;
    int x=x1,y=y1;
    while (x<= x2){
        if (plotyx) {
            plot(y, x, color);
        }
        else
        {
            plot(x,y,color);
        }
        x++;
        e += 2*dy;
        if (e > 0){
            y += sy;
            e -= 2*dx;
        }
    }
}

void Board::circle(int cx, int cy, int r,int color) {
    int x=0, y=r;
    int d = 3 - 2*r;
    //plot8 by berserham algo
	plot8(cx,cy,x,y,color);
    while (y>=x){
        x++;
        if(d>0){
            y--;
            d += 4*(x-y)+10;
        }
        else{
            d += 4*x+6;
        }
        //plot8 by berserham algo
	plot8(cx,cy,x,y,color);
    }
}

void Board::stamp(int x, int y, Board* stamp_board_name)  {
    for (int i = 0; i < stamp_board_name->rows; ++i) {
        for (int j = 0; j < stamp_board_name->cols; ++j) {
            plot(i+x,j+y,check_sign(stamp_board_name->data[j][i]));
        }
    }
}

int Board::sign(int num) {
    if(num > 0){
        return 1;
    }
    else if (num < 0){
        return -1;
    }
    else if(num == 0){
        return 0;
    }


    return 0;
}

void Board::fill(int x, int y, int color) {
    if(x<0 || y<0 || x>=cols || y>=rows ||  data[y][x] != colors[0]){
        return;
    }
    plot(x,y,color);
    fill(x+1,y,color);
    fill(x-1,y,color);
    fill(x,y+1,color);
    fill(x,y-1,color);
}

void Board::plot8(int cx,int cy,int x,int y,int color){
	plot(cx+y,cy+x,color);
    plot(cx-y,cy-x,color);
    plot(cx+y,cy-x,color);
    plot(cx-y,cy+x,color);
    plot(cx+x,cy+y,color);
    plot(cx-x,cy-y,color);
    plot(cx+x,cy-y,color);
    plot(cx-x,cy+y,color);
}

int Board::check_sign(char c) {
    for (int i = 0; i < 7; ++i) {
        if(colors[i] == c)
            return i;
    }
    return 0;

}

