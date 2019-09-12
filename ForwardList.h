#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include <iostream>
#include <vector>
#include "ForwardListNode.h"
#include "List.h"

template <typename T>
class ForwardList : public List<T>{

	template<typename _T>
		inline friend std::ostream& operator<< (std::ostream& out, ForwardList<_T>& list){
			ForwardListNode<_T> *temp = list.head;
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
	ForwardList():head{nullptr},tail{nullptr}{};

	~ForwardList(){
		this->clear();
	}

	T& back(void){
		auto node = this->head;
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
		head = head->next;
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
		auto nodeElement = new ForwardListNode<T>(element);
		auto node = this->head;
		while(node->next != nullptr){
			node = node->next;
		}
		node->next = nodeElement;
		nodeElement->next = nullptr;
	}

	Node<T>* pop_back(void){
		auto node = this->head;
		auto temp = node;
		while((node->next)->next != nullptr){
			node = node->next;
		}
		temp = node->next;
		node->next = nullptr;
		return(temp);
	}

	void erase(ForwardListNode<T>* del){
		auto temp = head;
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
		else{
			while(temp->next != _node){
				temp = temp->next;
			}

			newNode->next = temp->next;

			temp->next = newNode;

		}
	}

	void drop(const T& val){ // Elimina todos los elementos de la lista que tienen el valor igual al parametro
		auto node = this->head;
		auto temp = node->next;
		while(node->next != nullptr){
			delete node;
			node = temp;
			temp = temp->next;
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

	void reverse(void){
		auto node = this->head;
		std::vector<ForwardListNode<T>*> pointers;
		while(node->next != nullptr){
			pointers.push_back(node);
			node = node->next;
		} 

		this->head = pointers.back();
		node = this->head;

		for(auto i=pointers.size()-1; i>=0; i--){
			node.next = pointers[i];
			node = node->next;
		}

	}

	void clear(void){
		ForwardListNode<T>* temp = head;
		while(temp){
			temp = temp->next;
			delete head;
			head = temp;
		}
	}
};

#endif
