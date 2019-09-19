#ifndef DOUBLELISTNODE_H
#define DOUBLELISTNODE_H

template <typename T>
class DoubleListNode : public Node<T>{

    protected:

        Node<T> * next;

        Node<T> * prev;
    
    public:
        DoubleListNode(void){

        }
        
        ~DoubleListNode(void){

        }

};

#endif
