#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template <typename T>
class Iterator
{
	public:
  typedef T node_t;
  typedef typename node_t::value_t value_t;


  node_t* pointer;

  	Iterator(node_t* _pointer = nullptr):pointer(_pointer){
	}

	~Iterator(void){
	}

	virtual bool operator!= (Iterator& it){
		return pointer != it.pointer;
	}

	virtual value_t& operator* (void) {
		return **pointer;
	}

	virtual bool operator == (const Iterator& it){
		return pointer == it.pointer;
	}

	virtual Iterator& operator++(int);
/*
	virtual Iterator& operator++(void) const = 0;
	virtual Iterator& operator--(void) const = 0;
	virtual Iterator& operator--(int) const = 0;
	
	virtual bool operator != (const Iterator&) const = 0;
	virtual bool operator <= (const Iterator&) const = 0;
	virtual bool operator >= (const Iterator&) const = 0;
	virtual bool operator < (const Iterator&) const = 0;
	virtual bool operator > (const Iterator&) const = 0;
	
	virtual void operator=(const Iterator&) = 0;
*/

};

#endif

