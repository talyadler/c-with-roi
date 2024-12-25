#include "linkedlist.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

LinkedList::LinkedList() : List() {}

/*
* DESTRUTORS
*/

LinkedList::~LinkedList() {
	while (head != nullptr) {
		removeLast();
	}
}

/*
* USER METHODS
*/

// returns the length of the list
int LinkedList::length() const {
	return size;
} // O(1)

// returns whether the list is devoid of elements or not
bool LinkedList::isEmpty() const {
	return head == nullptr;
} // O(1)

// adds the element `n` at the index `index` of the list, if possible 
void LinkedList::addAt(int n, int index) {
	if (index < 0 || index > length()) throw "index out of range"; // O(1)
	if (index == 0) {
		head = new Link(n, head, nullptr);
		size ++;
		return;
	}
	Link* ll = head;
	for (int i = 0; i < index - 1; ++i)ll = ll->next;
	ll->next = new Link(n, ll->next , ll->prev);
	size ++;
} // O(n)

// adds an integer at the end of the list
void LinkedList::addLast(int i) {
	Link* toAdd = new Link(i, nullptr, tail);
	tail = toAdd;
	if (head == nullptr) head = toAdd;
	size ++;
}

void LinkedList::addFirst(int i) {
	Link* toAdd = new Link(i, head, nullptr);
	head = toAdd;
	if (tail == nullptr) tail = toAdd;
	size ++;
}

// remove the link at index "n", if possible
void LinkedList::removeAt(int index) {
	if (index < 0 || index >= length()) throw "index out of range";
	Link* l = head;
	if (index == 0) {
		head = head->next;
		delete l;
		size --;
		return;
	}
	while(index > 1) {
		l = l->next;
		index--;
	}
	Link* toDelete = l->next;
	l->next = toDelete->next;
	delete toDelete;
	size --;
} // O(n)

void LinkedList::removeLast() {
	if (isEmpty()) throw "empty list";
	Link* toRemove = head;
	delete head;
	head = toRemove->prev;
	if (head == toRemove) tail = nullptr;
	size --;
}

void LinkedList::removeFirst() {
	if (isEmpty()) throw "empty list";
	Link* toRemove = head;
	delete head;
	head = toRemove->next;
	if (head == toRemove) tail = nullptr;
	size --;
}

int LinkedList::numAt(int index) const {
	if (index < 0 || isEmpty()) throw "index out of range";
	Link* l = head;
	while (index > 0 && l != nullptr) {
		l = l->next;
		index--;
	}
	if (l == nullptr) throw "index out of range";
	return l->value;
} // O(n)
