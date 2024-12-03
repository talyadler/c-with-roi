#pragma once

class List {
public:
	// adds an integer at the end of the list
	virtual void add(int i) = 0;

	// removes last element in the list
	virtual void remove() = 0;

	// returns the element at given index, if exists
	virtual int numAt(int index) const = 0;
};
