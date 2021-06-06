#ifndef INC_32_EX3_312391774_DISCLINKEDLIST_H
#define INC_32_EX3_312391774_DISCLINKEDLIST_H
#include "Disc.h"
class DiscLinkedList
{
public:
    struct node
    {
        Disc *disc;
        node *next;
        node(Disc* disc, node *next) : disc(disc), next(next) {}
    };
    DiscLinkedList();
    //rule of 3
    DiscLinkedList(const DiscLinkedList &other); // copy ctor
    DiscLinkedList &operator=(const DiscLinkedList &rhs);
    ~DiscLinkedList();				 //dtor
    void add_disc(Disc * disc); //adds disc to the list
    node *get_head() { return head; };
    Disc& operator[](int index);   // index operator
    const Disc &operator[](int index) const;
    void clear(); // clears the linked list
    int getCount() const; // returns the size of the list
private:
    node *head;
    int count;
};

#endif //INC_32_EX3_312391774_DISCLINKEDLIST_H