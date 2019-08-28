#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {

    protected:

        T value;

        Node<T> * next;

    public:

        Node(void){

        }

        ~Node(void){

        }

};

#endif
