#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() : List() {}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		remove();
	}
}

void LinkedList::add(int i) {
	Link* toAdd = new Link(i); // O(1)
	if (head == nullptr) { // O(1)
		head = toAdd; // O(1)
		return;
	} // O(1)
	Link* ll = getLast(); // O(n)
	ll->next = toAdd; // O(1)
} // O(n)

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

void LinkedList::remove() {
	if (isEmpty()) throw "empty list";
	if (head->next == nullptr) {
		delete head;
		head = nullptr;
		return;
	}
	Link* ll = head;	
	while ((ll->next)->next != nullptr) ll = ll->next;
	// after while loop `ll->next == nullptr` meaning ll points to the last link
	delete ll->next;
	ll->next = nullptr;
} // O(n - 1) == O(n)

// returns the length of the list
int LinkedList::length() const {
	if (isEmpty()) return 0;
	int counter = 0;
	Link* ll = head;
	while (ll != nullptr) {
		counter++;
		ll = ll->next;
	}
	return counter;
} // O(n)

// returns whether the list is devoid of elements or not
bool LinkedList::isEmpty() const {
	return head == nullptr;
} // O(1)

// adds the element `n` at the index `index` of the list, if possible 
void LinkedList::addAt(int n, int index) {
	if (index < 0 || index > length())throw "index out of range";
	if (index == 0) {
		head = new Link(n, head);
		return;
	}
	Link* ll = head;
	for (int i = 0; i < index - 1; ++i)ll = ll->next;
	ll->next = new Link(n, ll->next);
} // O(n)

// remove the link at index "n", if possible
void LinkedList::removeAt(int index) {
	if (index < 0 || index >= length()) throw "index out of range";
	Link* l = head;
	if (index == 0) {
		head = head->next;
		delete l;
		return;
	}
	while(index > 1) {
		l = l->next;
		index--;
	}
	Link* toDelete = l->next;
	l->next = toDelete->next;
	delete toDelete;
} // O(n)

// Private function to provide funstionality to add
LinkedList::Link* LinkedList::getLast() {
	Link* ll = head; // O(1)
	while (ll->next != nullptr)	ll = ll->next;  //O(n)
	// after while loop `ll->next == nullptr` meaning ll points to the last link
	return ll; 
} // O(n)
