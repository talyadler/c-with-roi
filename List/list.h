#pragma once

// abstract class - as it has at least 1 pure virtual method
// interface class - as all of its methods are pure virtual
// base class - as there will be other classes to inherit this class
class List {
public:
	// adds an integer at the end of the list
	virtual void add(int i) = 0;

	// removes last element in the list
	virtual void remove() = 0;

	// returns the element at given index, if exists
	virtual int numAt(int index) const = 0;

	// returns the length of the list
	virtual int length();

	// returns whether the list is devoid of elements or not
	virtual bool isEmpty();

	// adds the element `n` at the index `index` of the list, if possible 
	virtual void addAt(int n, int index);
	
	// removes the element at the index `index` of the list, if possible 
	virtual void removeAt(int index);
};
