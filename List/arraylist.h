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

	// returns the length of the list
	virtual int length();

	// returns whether the list is devoid of elements or not
	virtual bool isEmpty();

	// inner function to find array capasity
	int getCapacity();

	// inner function to increase capacity
	void increaseCapacity(unsigned int addedCapacity);

/*
	// adds the element `n` at the index `index` of the list, if possible 
	virtual void addAt(int n, int index);
	
	// removes the element at the index `index` of the list, if possible 
	virtual void removeAt(int index);
*/
private:
	int *data;
	int capacity;
	int size;
};

