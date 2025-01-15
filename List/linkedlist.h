#pragma once
#include "list.h"

class LinkedList : public List {
public:
	LinkedList();
	virtual ~LinkedList();

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
	// O(n) --> O(1) (after including tail)
	virtual void addLast(int i);

	// adds an integer at the start of the list
	// O(n) --> O(1) (after including tail)
	virtual void addFirst(int i);

	// removes the element at the index `index` of the list, if possible 
	// O(n)
	virtual void removeAt(int index);

	// removes last element in the list
	// O(n) --> O(1) (bi-directional linkedlist)
	virtual void removeLast();

	// removes first element in the list
	// O(n) --> O(1) (bi-directional linkedlist)
	virtual void removeFirst();

	// returns the element at given index, if exists
	// O(n)
	virtual int numAt(int index) const;

	// returns the element at start of linkedlist, if exists
	// O(1)
	virtual int numFirst() const;

	// returns the element at end of linkedlist, if exists
	// O(1)
	virtual int numLast() const;

private:
	class Link {
		public: 
			Link() = default;
			Link(int n) : value(n) {}
			Link(int n, Link* next, Link* prev) : value(n), next(next), prev(prev) {}
			virtual ~Link() = default;
			int value;
			Link* next = nullptr;
			Link* prev = nullptr;
	};

	Link* head = nullptr;
	Link* tail = nullptr;
	unsigned int size = 0;

	class iterator {
	public:
		iterator(Link* curr) : curr(curr) {}
		iterator(const iterator& o) : curr(o.curr) {}


		Link operator*() {
			return curr->value;
		};

		bool operator!=(const iterator& o) const {
			return curr != o.curr;
		}

		iterator& operator++() {
			curr = curr->next;
			return *this;
		}

		iterator operator++(int) {
			iterator prevState(*this);
			curr = curr->next;
			return prevState;
		}


	private:
		Link* curr;
	};

	friend iterator begin() { return iterator(head); }
	friend iterator end() { return iterator(nullptr); }
};
