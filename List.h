#ifndef LIST_H
#define LIST_H
#include <iostream>

template <typename T>
class List{

    protected:

        Node<T> *head;

    public:

        List(void){

        }

        ~List(void){

        }

        T& front(void){
            return head;
        };

        virtual T& back(void);

        virtual void push_back(const T& element);

        virtual void push_front(const T& element);

        virtual Node<T>* pop_back(void);

        virtual Node<T>* pop_front(void);

        T& operator[] (const int& index){
            Node<T> *temp = head;
            for(unsigned int i = 0; i < index; i++){
                temp = temp->next;
            }
            return temp->value;
        };



        bool empty(void){
            return head;
        };

        virtual unsigned int size(void) = 0;

        void clear(void);

        virtual void erase(Node<T>* n); // Elimina un elemento de la lista en base a un puntero

        virtual void insert(Node<T>*, const T&); // Inserta un elemento en la lista en base a un puntero

        virtual void drop(const T&); // Elimina todos los elementos de la lista que tienen el valor igual al parametro

        virtual void sort(void);

        virtual void reverse(void);

        //std::ostream& operator<< (std::ostream& out, const List<T>& list);

        //ForwardList& operator<< (List<T>&, const T& ); // push_back de un elemento

        //ForwardList& operator>> (List<T>&, const T& ) = 0; // pop_back deun elemento

        

};

#endif