#include "Forwardlist.h"

T& front(void){};

T& back(void){};



void push_back(const T& element){};

void push_front(const T& element){};

Node<T>* pop_back(void){};

Node<T>* pop_front(void){};

T& operator[] (const int&){};



bool empty(void){};

unsigned int size(void){};

void clear(void){};

ForwardList& sort(void){};

ForwardList& reverse(void){};

std::ostream& operator<< (const ForwardList&, std::ostream&){};
