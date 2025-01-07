#pragma once
#include "list.h"

// a subclass of List (List is the baseclass of ArrayList, ArrayList is a subclass of List)
class ArrayList : public List {
public:
	ArrayList();
	virtual ~ArrayList();

	// returns the length of the list
	// O(1)
	virtual int length() const ;

	// returns whether the list is devoid of elements or not
	// O(1)
	virtual bool isEmpty() const ;

	// adds the element `n` at the index `index` of the list, if possible 
	// O(n)
	virtual void addAt(int n, int index);

	// adds an integer at the end of the list
	// O(n) --> Amortized O(1)
	virtual void addLast(int i);

	// adds an integer at the start of the list
	// O(n) --> Amortized O(1)
	virtual void addFirst(int i);

	// removes the element at the index `index` of the list, if possible 
	// O(n)
	virtual void removeAt(int index);

	// removes last element in the list
	// O(1)
	virtual void removeLast();

	// removes first element in the list
	// O(n)
	virtual void removeFirst();

	// returns the element at given index, if exists
	// O(1)
	virtual int numAt(int index) const;

	// returns the element at start of arraylist, if exists
	// 
	virtual int numFirst() const;

	// returns the element at end of arraylist, if exists
	// 
	virtual int numLast() const;

	// inner function to find array capasity
	// O(1)
	int getCapacity() const;

	// inner function to increase capacity
	// O(n)
	void increaseCapacity(unsigned int addedCapacity);

	class iterator {
	public:
		iterator(int* curr) : curr(curr) {}
		iterator(const iterator& o) : curr(o.curr) {}


		int operator*() {
			return *curr;
		};

		bool operator!=(const iterator& o) const {
			return curr != o.curr;
		}

		iterator operator++() {
			curr++;
			return *this;
		}

		iterator operator++(int) {
			iterator prevState(*this);
			curr++;
			return prevState;
		}


	private:
		int* curr;
	};

	iterator begin() { return iterator(data); }
	iterator end() { return iterator(data + size); }

	int& operator[](int index) {
		// input check on index
		return data[index];
	}

	const int& operator[](int index) const {
		return data[index];
	}


private:
	int *data;
	int capacity;
	int size;
};



