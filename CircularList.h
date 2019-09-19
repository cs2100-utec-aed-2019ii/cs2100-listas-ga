#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H
#include <iostream>

template <typename T>
class CircularList : public List<T>{

    protected:

        ForwardListNode<T> *head;

};

#endif
