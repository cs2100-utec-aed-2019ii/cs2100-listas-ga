#ifndef FORWARDLISTNODE_H
#define FORWARDLISTNODE_H
#include "Node.h"
#include <memory>

template <typename T>
class ForwardListNode : public Node<T> {

    protected:
			std::unique_ptr<T> next;

    public:
        ForwardListNode(T _value){
            this->value = _value;
        };
        
        ~ForwardListNode(void){
        };

};

#endif
