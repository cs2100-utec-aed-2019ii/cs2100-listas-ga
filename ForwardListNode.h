#ifndef FORWARDLISTNODE_H
#define FORWARDLISTNODE_H
#include "Node.h"

template <typename T>
class ForwardListNode : public Node<T> {

    protected:

        ForwardListNode<T> * next;

    public:
        ForwardListNode(T _value){
            this->value = _value;
        };
        
        ~ForwardListNode(void){
        };

};

#endif
