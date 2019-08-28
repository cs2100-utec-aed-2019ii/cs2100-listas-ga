#ifndef FORWARDLIST_H
#define FORWARDLIST_H
#include "Node.h"

template <typename T>
class ForwardList 
{
	protected:
		Node<T> *head;
	public:
		ForwardList(void)
		{

		}
		~ForwardList(void)
		{

		}
		
		const auto& front(void);
		const auto& back(void);
		
		void push_back(const T& element);
		void push_front(const T& element);
		Node<T>* pop_back(void);
		Node<T>* pop_front(void);
		const auto& operator[] (const int&);
		
		bool empty(void);
		unsigned int size(void);
		void clear(void);
		ForwardList& sort(void);
		ForwardList& reverse(void);
		std::ostream& operator << (const ForwardList&, std::ostream&);
};

#endif
