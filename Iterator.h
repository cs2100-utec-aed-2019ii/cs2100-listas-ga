#ifndef ITERATOR_H
#define ITERATOR_H

#include "Node.h"

template <typename Node, typename T>
class Iterator
{
	public:
		virtual void operator ++() const = 0;
		virtual bool operator <(const Iterator&) const = 0;
		virtual bool operator >(const Iterator&) const = 0;
		virtual bool operator >=(const Iterator&) const = 0;

};
