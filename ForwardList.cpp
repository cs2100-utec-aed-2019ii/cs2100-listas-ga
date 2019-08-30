#include "ForwardList.h"

template <typename T>
T& ForwardList<T>::front(void){
  return head;
};

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

template <typename T>
void ForwardList<T>::push_front(const T& element){
  Node<T> *temp = new Node<T>(*element);
  temp->next = head;
  head = temp;
};

template <typename T>
Node<T>* ForwardList<T>::pop_back(void){
	Node<T> node = this->*head;
	while((node.next).next != nullptr){
		*node = node.next;
	}
	node.next = nullptr;
};

template <typename T>
Node<T>* ForwardList<T>::pop_front(void){
  Node<T>* temp = head;
  head = head->next;
  return temp;

};

template <typename T>
ForwardList& ForwardList<T>::sort(void){};

ForwardList& reverse(void){};
