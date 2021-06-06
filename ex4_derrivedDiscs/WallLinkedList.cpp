#include "WallLinkedList.h"
#include <cstdlib>
#include <iostream>

WallLinkedList::WallLinkedList() : head(0), count(0) {}


void WallLinkedList::add_wall(const Wall &wall) {
    head = new node(wall, head);
    count++;
}

WallLinkedList::~WallLinkedList() {
    while (head) {
        node *toDelete = head;
        head = head->next;
        delete toDelete;
    }
}

Wall &WallLinkedList::operator[](int index) {
    if (index < 0 || index >= count) {
        exit(1);
    }
    node *temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->wall;
}

WallLinkedList::WallLinkedList(const WallLinkedList &other): head(NULL), count(0){
    for (int i=0; i<other.count;i++){
        this->add_wall(other[i]);
    }
}

WallLinkedList &WallLinkedList::operator=(const WallLinkedList &rhs) {
    if (this == &rhs){
        return *this;
    }
    this->clear();
    for (int i=0; i<rhs.count;i++){
        this->add_wall(rhs[i]);
    }
    return *this;
}

void WallLinkedList::clear(){
    while (head){
        node* temp = head;
        head = head->next;
        delete temp;
    }
    count = 0;
    head = NULL;
}

const Wall &WallLinkedList::operator[](int index) const {
    if (index < 0 || index >= count) {
        exit(-1);
    }
    node* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp->wall;
}

int WallLinkedList::getCount() const {
    return count;
}
