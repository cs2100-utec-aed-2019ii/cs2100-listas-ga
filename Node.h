#ifndef NODE_H
#define NODE_H

template <typename T>
class Node {

    public:
        T value;
        Node(T _value){
            value = _value;
        }

        ~Node(void){

        }

};

#endif
