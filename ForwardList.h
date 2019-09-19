#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Iterator.h"
#include <iostream>
#include <vector>
#include "ForwardListNode.h"
#include "List.h"

template <typename T>
class ForwardList : public List<T>{

	public:

		typedef ForwardListNode<T> _node_t;

		friend class ForwardIterator;
		class ForwardIterator: public Iterator<_node_t> {

			typedef typename Iterator<_node_t>::node_t node_t;
			typedef typename Iterator<_node_t>::value_t value_t;

			ForwardIterator(_node_t* pointer = nullptr):Iterator<_node_t>(pointer){}
			~ForwardIterator(){

			}

			ForwardIterator& operator++ (void){
				Iterator<_node_t>::pointer = Iterator<_node_t>::pointer->next; 
				return *this;
			}

			ForwardIterator& operator++(int){
				auto itr = *this;
				++*this;
				return itr;
			}


		};

		template<typename _T>
			inline friend std::ostream& operator<< (std::ostream& out, ForwardList<_T>& list){
				ForwardListNode<_T>* temp = list.head;
				while(temp){

					out<< temp->value;

					temp = temp->next;
				}
				return out;
			}

		template<typename _T>
			inline friend ForwardList<_T>& operator<< (const _T& element, ForwardList<_T>& list){
				list->push_back(element);
			}

		template<typename _T>
			inline friend ForwardList<_T>& operator>> (ForwardListNode<_T>& out, ForwardList<_T>& list){
				out = list->pop_back();
			}
	protected:
		ForwardListNode<T>* head;
		ForwardListNode<T>* tail;

	public:
		ForwardList():List<T>(){
			head = nullptr;
			tail = nullptr;
		};

		~ForwardList(){
			this->clear();
		}

		ForwardIterator begin(){
			return ForwardIterator(head);
		}

		ForwardIterator end(){
			return ForwardIterator(tail);
		}

		T& front(void){
			return head->value;
		}

		T& back(void){
			auto node = head;
			while(node->next != nullptr){
				node = node->next;
			}
			return node->value;
		}

		void push_front(const T& element){
			auto temp = new ForwardListNode<T>(element);
			temp->next = head;
			head = temp;
		}

		Node<T>* pop_front(void){
			auto temp = head;
			if(head){
				head = head->next;
			}
			return temp;


		}


		unsigned int size(void){
			auto temp = head;
			unsigned int size = 0;

			while(temp){
				size++;
				temp = temp->next;
			}
			return size;
		};

		void push_back(const T& element){
			ForwardListNode<T>* nodeElement = new ForwardListNode<T>(element);
			ForwardListNode<T>* node = this->head;
			if(!head){
				head = nodeElement;
				tail = nodeElement;
			}else{
				while(node->next){
					node = node->next;
				}
				node->next = nodeElement;
				tail = nodeElement;
			}
		}

		Node<T>* pop_back(void){
			auto node = this->head;
			auto temp = node;
			while((node->next)->next != nullptr){
				node = node->next;
			}
			temp = node->next;
			node->next = nullptr;
			tail = node;
			return(temp);
		}

		void erase(ForwardListNode<T>* del){
			auto temp = head;
			if(del == head){
				pop_front();
			}
			else if(del == tail){
				pop_back();
			}
			while(temp->next != del){
				temp = temp->next;
			}
			temp->next = (temp->next)->next;
		}

		void insert(ForwardListNode<T>* _node, const T& val){ // Inserta un elemento en la lista en base a un puntero
			auto temp = head;
			auto newNode = new ForwardListNode<T>(val);
			if(_node == head){
				newNode->next = _node;
				head = newNode;
			}
			else if(_node == tail){
				tail->next = _node;
				_node = tail;
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
			if(head->value == val){pop_front();}
			if(tail->value == val){pop_back();}

			ForwardListNode<T>* node = this->head;
			ForwardListNode<T>* temp = node->next;
			while(node->next != nullptr){
				if(node->value == val){
					delete node;
					node = temp;
					temp = temp->next;
				}

			}
		}

		void sort(void){
			auto temp = head;
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

		void reverse() {
			auto node = head;
			ForwardListNode<T>* prev = nullptr;
			ForwardListNode<T>* next = nullptr;

			while (node != nullptr) {
				next = node->next;
				node->next = prev;
				prev = node;
				node = next;
			}

			tail = head;
			head = prev;
		}	

		void clear(void){
			ForwardListNode<T>* temp = head;
			while(temp){
				temp = temp->next;
				delete head;
				head = temp;
			}
			tail = nullptr;
		}
};

#endif
