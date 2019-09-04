#ifndef FORWARDLISTNODE_H
#define FORWARDLISTNODE_H

template <typename T>
class ForwardListNode : public Node<T> {

    protected:

        Node<T> * next;
    public:
        ForwardListNode(void){
        }
        
        ~ForwardListNode(void){
        }

};

#endif
