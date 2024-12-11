#pragma once
#include "list.h"

class RecursiveLinkedList : public List {
public:
	RecursiveLinkedList() = default;
	virtual ~RecursiveLinkedList() = default;

	//with recursion we need to have a copy methos in private RecursiveLink class

	// adds an integer at the end of the list
	// done
	virtual void add(int i);

	// removes last element in the list
	//done
	virtual void remove();

	// returns the length of the list
	// to do
	virtual int length();

	// returns the element at given index, if exists
	// to do
	virtual int numAt(int index) const;

	// returns whether the list is devoid of elements or not
	// to do
	virtual bool isEmpty();

	// adds the element `n` at the index `index` of the list, if possible 
	// to do
	virtual void addAt(int n, int index);

	// removes the element at the index `index` of the list, if possible 
	// to do
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

			// gives chain length
			int length();

			// gives value of link by index
			int numAt(int index) const ;

			// check if empty chain
			bool isEmpty();

			// helper methods
			bool hasNext() { return next != nullptr; }
			bool isLast() { return !hasNext(); }

			int value;
			RecursiveLink* next = nullptr;
	};
	
	RecursiveLink* head = nullptr;

	// RecursiveLink* getLast();
};
