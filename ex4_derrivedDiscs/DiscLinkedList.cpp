#include "DiscLinkedList.h"
#include <cstdlib>
#include <iostream>
#include "Hockey_table.h"
#include "ShrinkingDisc.h"
#include "ExplodingDisc.h"
DiscLinkedList::DiscLinkedList() : head(0), count(0) {}

void DiscLinkedList::add_disc(const Disc&  disc)
{
    if (head == NULL)
    {
        head = new node(disc.clone(), NULL);
        count++;
        return;
    }
    node *temp = head;
    while (temp->next)
    {
        temp = temp->next;
    }
    temp->next = new node(disc.clone(), NULL);
    count++;
}

DiscLinkedList::~DiscLinkedList()
{
   clear();
}

Disc &DiscLinkedList::operator[](int index)
{
    if (index < 0 || index >= count)
    {
        exit(1);
    }
    node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return *(temp->disc);
}

DiscLinkedList::DiscLinkedList(const DiscLinkedList &other) : head(NULL), count(0)
{
    for (int i = 0; i < other.count; i++)
    {
        this->add_disc(other[i]);
    }
}

DiscLinkedList &DiscLinkedList::operator=(const DiscLinkedList &rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    this->clear();
    for (int i = 0; i < rhs.count; i++)
    {
        this->add_disc(rhs[i]);
    }
    return *this;
}

void DiscLinkedList::clear()
{

    while (head)
    {
        node *toDelete = head;
        head = head->next;
        delete toDelete->disc;
        delete toDelete;
    }
    count = 0;
    head = NULL;
}

const Disc &DiscLinkedList::operator[](int index) const
{
    if (index < 0 || index >= count)
    {
        exit(-1);
    }
    node *temp = head;
    for (int i = 0; i < index; i++)
    {
        temp = temp->next;
    }
    return *(temp->disc);
}

int DiscLinkedList::getCount() const
{
    return count;
}