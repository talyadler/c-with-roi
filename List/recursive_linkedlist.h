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
	// done
	virtual void remove();

	// returns the length of the list
	// done
	virtual int length() const ;

	// returns the element at given index, if exists
	// done
	virtual int numAt(int index) const;

	// returns whether the list is devoid of elements or not
	// done
	virtual bool isEmpty() const {return head == nullptr;}

	// adds the element `n` at the index `index` of the list, if possible 
	// done
	virtual void addAt(int n, int index);

	// removes the element at the index `index` of the list, if possible 
	// done
	virtual void removeAt(int index);


private:
	class RecursiveLink {
		public: 
			RecursiveLink() = default;
			RecursiveLink(int value) : value(value) {}
			RecursiveLink(int value, RecursiveLink* next) : value(value), next(next) {}
			virtual ~RecursiveLink() = default;

			// adds a new link at the end with value `value`
			void add(int value);

			// removes the last node in the chain
			void remove();

			// gives chain length
			int length() const ;

			// gives value of link by index
			int numAt(int index) const ;

			//add new link at index
			void addAt(int n, int index);

			// remove link at index
			void removeAt(int index);
			

			// helper methods
			bool hasNext() const { return next != nullptr; }
			bool isLast() const { return !hasNext(); }

			int value;
			RecursiveLink* next = nullptr;
	};
	
	RecursiveLink* head = nullptr;

	// RecursiveLink* getLast();
};
