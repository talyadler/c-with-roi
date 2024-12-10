#pragma once
#include "list.h"

class RecursiveLinkedList : public List {
public:
	RecursiveLinkedList() = default;
	virtual ~RecursiveLinkedList();

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

	// adds the element `n` at the index `index` of the list, if possible 
	virtual void addAt(int n, int index);

	// removes the element at the index `index` of the list, if possible 
	virtual void removeAt(int index);

private:
	class RecursiveLink {
		public: 
			RecursiveLink() = default;
			RecursiveLink(int value) : value(value) {}
			virtual ~RecursiveLink() = default;

			// adds a new link at the end with value `value`
			void add(int value);

			// removes the last node in the chain
			void remove();

			bool hasNext() { return next != nullptr; }
			bool isLast() { return !hasNext(); }

			int value;
			RecursiveLink* next = nullptr;
	};

	RecursiveLink* head = nullptr;

	RecursiveLink* getLast();
};
