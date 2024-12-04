#pragma once
#include "list.h"

// a subclass of List (List is the baseclass of ArrayList, ArrayList is a subclass of List)
class ArrayList : public List {
public:
	ArrayList();
	virtual ~ArrayList();

	// adds an integer at the end of the list
	virtual void add(int i);

	// removes last element in the list
	virtual void remove();

	// returns the element at given index, if exists
	virtual int numAt(int index) const;

	int getCapacity();

	void increaseCapacity(unsigned int addedCapacity);

private:
	int *data;
	int capacity;
	int size;

};

