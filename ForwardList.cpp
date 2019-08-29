#include "ForwardList.h"


T& front(void){};

template <typename T>
T& ForwardList<T>::back(void){
	Node<T> node = this->*head;
	while(node.next != nullptr){
		*node = node.next;
	}
	return node;
};

template <typename T>
void ForwardList<T>::push_back(const T& element){
	Node<T> node = this->*head;
	while(node.next != nullptr){
		*node = node.next;
	}
	node.next = *element;
	element.next = nullptr;
};

void push_front(const T& element){};

template <typename T>
Node<T>* ForwardList<T>::pop_back(void){
	Node<T> node = this->*head;
	while((node.next).next != nullptr){
		*node = node.next;
	}
	node.next = nullptr;
};

Node<T>* pop_front(void){};

T& operator[] (const int&){};



bool empty(void){};

unsigned int size(void){};

void clear(void){};

ForwardList& sort(void){};

ForwardList& reverse(void){};

std::ostream& operator<< (const ForwardList&, std::ostream&){};
