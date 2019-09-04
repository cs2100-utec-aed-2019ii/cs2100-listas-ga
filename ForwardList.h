#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>
#include "ForwardListNode.h"
#include "List.h"

template <typename T>
class ForwardList : public List<T>{

    protected:

        ForwardListNode<T> *head;

        ForwardListNode<T> *tail;

    public:

        ForwardList():head{nullptr},tail{nullptr}{};

        ~ForwardList(){
            this->clear();
        }

        T& back(void){
            ForwardListNode<T> node = this->*head;
            while(node.next){
                *node = node.next;
	        }
	        return node;
        };



        unsigned int size(void){
            ForwardListNode<T>* temp = head;
            unsigned int size = 0;

            while(temp){
                size++;
                temp = temp->next;
            }
            return size;
        };

        void push_back(const T& element){
            ForwardListNode<T> node = this->*head;
            while(node.next != nullptr){
                *node = node.next;
            }
            node.next = *element;
            element.next = nullptr;
        }

        ForwardListNode<T>* pop_back(void){
            ForwardListNode<T> node = this->*head;
            while((node.next).next != nullptr){
                *node = node.next;
            }
            node.next = nullptr;
        }

        void erase(ForwardListNode<T>* del){
            ForwardListNode<T>* temp = head;
            while(temp.next != del){
                temp = temp.next;
            }
            temp.next = temp.next.next;
        }

        void insert(ForwardListNode<T>*, const T&){ // Inserta un elemento en la lista en base a un puntero

        }

        void drop(const T&){ // Elimina todos los elementos de la lista que tienen el valor igual al parametro

        }

        void sort(void){
            ForwardListNode<T>* temp = head;
            T tempVal;
            unsigned int _size = this->size();
            for(unsigned int i = 0; i < _size - 1; i++){
                for(unsigned int j = 0; j < _size - 1 - i; j++){
                    if(temp->value > (temp->next)->value){
                        tempVal = temp->value;
                        temp->value = (temp->next)->value;
                        (temp->next)->value = tempVal;
                    }
                    temp = temp->next;
                }
            }

        }

        List<T>& reverse(void){

        }

        std::ostream& operator<< (std::ostream& out){
            ForwardListNode<T> *temp = head;
            while(temp){
                out<< temp->value;
                temp = temp->next;
            }
            return out;
        };

        //ForwardList& operator<< (List<T>& out, const T& element); // push_back de un elemento

        //ForwardList& operator>> (List<T>& out, const T& element) = 0; // pop_back deun elemento

};


#endif
