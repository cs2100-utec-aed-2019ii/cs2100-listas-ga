#ifndef FORWARDLISTNODE_H
#define FORWARDLISTNODE_H
#include "Node.h"
#include <memory>

template <typename T>
class ForwardListNode : public Node<T> {

    public:
    	ForwardListNode<T>* next;

        ForwardListNode(T _value):Node<T>(_value){};
        
        ~ForwardListNode(void){
        };

};

#endif
