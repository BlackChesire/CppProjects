//
// Created by Asaf-PC on 14/03/2021.
//

#ifndef EX1_BOARDLIST_H
#define EX1_BOARDLIST_H
#include "Board.h"
class BoardList{
private:
    struct node{
        Board* board;
        node* next;
    };

    node* head;
    node* current;
    node* temp;
public:
    BoardList();
    void AddNode(Board* board); //adds board to the list
    void DeleteNode(Board* board_name); //deletes board from the list
    Board * find_board(string boardname); // finding the board by its name
};

#endif //EX1_BOARDLIST_H
