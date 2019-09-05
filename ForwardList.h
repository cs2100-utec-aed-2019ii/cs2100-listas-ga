#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>
#include <vector>
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
						ForwardListNode<T> nodeR = node.next;	
            node.next = nullptr;
						return nodeR;
        }

        void erase(ForwardListNode<T>* del){
            ForwardListNode<T>* temp = head;
            while(temp->next != del){
                temp = temp->next;
            }
            temp->next = (temp->next)->next;
        }

        void insert(ForwardListNode<T>* _node, const T& val){ // Inserta un elemento en la lista en base a un puntero
            ForwardListNode<T>* temp = head;
            ForwardListNode<T>* newNode = new ForwardListNode<T>(val);
            if(_node == head){
                newNode->next = _node;
                head = newNode;
            }
            else{
                while(temp->next != _node){
                    temp = temp->next;
                }

                newNode->next = temp->next;

                temp->next = newNode;

            }
        }

        void drop(const T& val){ // Elimina todos los elementos de la lista que tienen el valor igual al parametro
          auto node = this->*head;
          auto* temp = &node;
					while(node.next != nullptr){
								if(node.value == val && node != head){
									temp.next = node.next;
									~node;
								}
									
								*temp = &node;
                &node = node.next;
								if(temp == head){
									~temp;
									temp = &node;
								}								
          }


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

        void reverse(void){
					ForwardListNode<T> node = this->*head;
					std::vector<T> pointers;
					while(node.next != nullptr){
						pointers.push_back(*node);
						*node = node.next;
          } 
					
					this->*head = pointers.back();
					node = this->*head;

					for(auto i=pointers.size()-1; i>=0; i--){
						node.next = pointers[i];
						&node = node.next;
					}

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
