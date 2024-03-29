#ifndef FORWARDLISTNODE_H
#define FORWARDLISTNODE_H
#include "Node.h"
#include <memory>

template <typename T>
class ForwardListNode : public Node<T> {

    public:
        typedef typename Node<T>::value_t value_t;
    	ForwardListNode<T>* next;

        ForwardListNode(T _value):Node<T>(_value){
            Node<T>::value = _value;
            next = nullptr;
        };
        
        ~ForwardListNode(void){
        };

};

#endif
