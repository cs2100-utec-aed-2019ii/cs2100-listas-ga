#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>
#include "ForwardListNode.h"

template <typename T>
class ForwardList : public List<T>{

    protected:

        ForwardListNode<T> *head;

        ForwardListNode<T> *tail;

    public:

        unsigned int size(void){
            ForwardListNode<T>* temp = head;
            unsigned int size = 0;

            while(temp){
                size++;
                temp = temp->next;
            }
            return size;
        };

        void push_back(const T& element){
            ForwardListNode<T> node = this->*head;
            while(node.next != nullptr){
                *node = node.next;
            }
            node.next = *element;
            element.next = nullptr;
        }



        std::ostream& operator<< (std::ostream& out){
            ForwardListNode<T> *temp = head;
            while(temp){
                out<< temp->value;
                temp = temp->next;
            }
            return out;
        };

};


#endif
