#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Node.h"
#include <iostream>

template <typename T>

class ForwardList: public Node<T> {

    protected:

        Node<T> *head;

    public:

        ForwardList(void){

        }

        ~ForwardList(void){

        }

        T& front(void);

        T& back(void);



        void push_back(const T& element);

        void push_front(const T& element);

        Node<T>* pop_back(void);

        Node<T>* pop_front(void);

        T& operator[] (const int& index){
            Node<T> *temp = head;
            for(unisgned int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp->value;
        };



        bool empty(void);

        unsigned int size(void);

        void clear(void);

        ForwardList& sort(void);

        ForwardList& reverse(void);

        std::ostream& operator<< (std::ostream& out, const ForwardList& list){
            Node<T> *temp = head;
            while(temp){
                out<< temp->value;
                temp = temp->next;
            }
            return out;
        };

};



#endif
