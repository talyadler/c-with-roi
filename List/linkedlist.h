#pragma once
#include "list.h"

class LinkedList : public List {
public:
	LinkedList();
	virtual ~LinkedList();

	// adds an integer at the end of the list
	virtual void add(int i);

	// removes last element in the list
	virtual void remove();

	// returns the element at given index, if exists
	virtual int numAt(int index) const;
};
