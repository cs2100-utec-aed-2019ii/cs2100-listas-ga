#ifndef DOUBLELIST_H
#define DOUBLELIST_H
#include <iostream>

template <typename T>
class DoubleList : public List<T>{

    protected:

        DoubleListNode<T> *head;

        DoubleListNode<T> *tail;
};

#endif