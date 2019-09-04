#ifndef DOUBLECIRCULARLIST_H
#define DOUBLECIRCULARLIST_H
#include <iostream>

template <typename T>
class DoubleCircularList : public List<T>{

    protected:

        DoubleListNode<T> *head;

};

#endif
