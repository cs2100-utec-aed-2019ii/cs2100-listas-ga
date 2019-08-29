#include "ForwardList.h"

template <typename T>
T& ForwardList<T>::front(void){
  return head;
};

T& back(void){};



void push_back(const T& element){};

template <typename T>
void ForwardList<T>::push_front(const T& element){

  Node<T> *temp = new Node<T>(*element);
  temp->next = head;
  head = temp;

};

Node<T>* pop_back(void){};

template <typename T>
Node<T>* ForwardList<T>::pop_front(void){
  Node<T>* temp = head;
  head = head->next;
  return temp;

};

T& operator[] (const int&){};



bool empty(void){};

unsigned int size(void){};

void clear(void){};

template <typename T>
ForwardList& ForwardList<T>::sort(void){};

ForwardList& reverse(void){};
