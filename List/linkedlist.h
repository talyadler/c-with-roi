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

	// returns the length of the list
	virtual int length() const ;

	// returns whether the list is devoid of elements or not
	virtual bool isEmpty() const ;

	// adds the element `n` at the index `index` of the list, if possible 
	virtual void addAt(int n, int index);

	// removes the element at the index `index` of the list, if possible 
	virtual void removeAt(int index);

private:
	class Link {
		public: 
			Link() = default;
			virtual ~Link() = default;
			int value;
			Link* next = nullptr;
	};

	Link* head = nullptr;

	Link* getLast();
};
