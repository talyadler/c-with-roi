#pragma once
#include "list.h"

// a subclass of List (List is the baseclass of ArrayList, ArrayList is a subclass of List)
class ArrayList : public List {
public:
	ArrayList();
	virtual ~ArrayList();

	// adds an integer at the end of the list
	// O(n) --> Amortized O(1)
	virtual void add(int i);

	// removes last element in the list
	// O(1)
	virtual void remove();

	// returns the element at given index, if exists
	// O(1)
	virtual int numAt(int index) const;

	// returns the length of the list
	// O(1)
	virtual int length() const ;

	// returns whether the list is devoid of elements or not
	// O(1)
	virtual bool isEmpty() const ;

	// inner function to find array capasity
	// O(1)
	int getCapacity() const;

	// inner function to increase capacity
	// O(n)
	void increaseCapacity(unsigned int addedCapacity);

	// adds the element `n` at the index `index` of the list, if possible 
	// O(n)
	virtual void addAt(int n, int index);

	// removes the element at the index `index` of the list, if possible 
	// O(n)
	virtual void removeAt(int index);


private:
	int *data;
	int capacity;
	int size;
};

