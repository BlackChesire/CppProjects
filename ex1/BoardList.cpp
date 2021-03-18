#include <cstdlib>
#include <iostream>
#include "BoardList.h"

using namespace std;

BoardList::BoardList() {
    head = NULL;
    current = NULL;
    temp = NULL;
}

void BoardList::AddNode(Board* board) {
    node*  n = new node;
    n->next = NULL;
    n->board = board;
    if (head != NULL){
        current = head;
        while (current->next != NULL){
            current = current->next;
        }
        current->next = n;
    }
    else{
        head = n;
    }
}
void BoardList::DeleteNode(Board* del_board_name) {
    node* delPtr = NULL;
    temp = head;
    current = head;
    while (current != NULL && current->board != del_board_name){
        temp = current;
        current = current->next;
    }
    if (current == NULL){
        cout<< del_board_name<<"was not in the list\n";
        delete delPtr;
    }
    else{
        delPtr = current;
        current = current->next;
        temp->next = current;
        delete delPtr;
        cout<<"the value "<<del_board_name<<"was deleted\n";

    }
}
Board * BoardList::find_board(string boardname) {
    {
        current = head;
        while (current)
        {
           if(current->board->name == boardname){
               return current->board;
           }
            current= current->next;
        }
        return NULL;

    }
}
