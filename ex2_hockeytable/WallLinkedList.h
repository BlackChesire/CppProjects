#ifndef INC_32_EX3_312391774_WALLLINKEDLIST_H
#define INC_32_EX3_312391774_WALLLINKEDLIST_H
#include "Wall.h"

class WallLinkedList {
public:
    struct node{
        Wall wall;
        node* next;
        node(const Wall& wall,node* next):wall(wall),next(next){}
    };
    WallLinkedList();
    WallLinkedList(const WallLinkedList& other); //copy ctor
    WallLinkedList& operator=(const WallLinkedList& rhs);
    ~WallLinkedList(); //dtor
    void add_wall (const Wall &wall); //adds wall to the list
    node* get_head() { return head;};
    Wall& operator[](int index); // index operator
    const Wall & operator[](int index) const; // index const operator
    void clear(); // clears the list

    int getCount() const; // returns the size

private:
    node* head;
    int count;
};


#endif //INC_32_EX3_312391774_WALLLINKEDLIST_H
