#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() : List() {}

LinkedList::~LinkedList() {
	while (head != nullptr) {
		remove();
	}
}

void LinkedList::add(int i) {
	Link* toAdd = new Link();
	toAdd->value = i;
	if (head == nullptr) {
		head = toAdd;
		return;
	}
	Link* ll = getLast();
	ll->next = toAdd;
}

int LinkedList::numAt(int index) const {
	Link* l = head;
	if (index < 0) throw "index out of range";
	while (index > 0){
		l = l->next;
		if (l == nullptr || index < 0) {
			throw "index out of range";
		}
		index --;
	}
	if (l == nullptr) {
		throw "index out of range";
	}
	return l->value;
}

void LinkedList::remove() {
	if (head == nullptr) throw "empty list";
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
}

// returns the length of the list
int LinkedList::length() const {
	if (head == nullptr) throw "empty list";
    int counter = 0;
    Link* ll = head;
    while (ll != nullptr) {
        counter++;
        ll = ll->next;
    }
    return counter;
}

// returns whether the list is devoid of elements or not
bool LinkedList::isEmpty() const {
    return head == nullptr;
}

// adds the element `n` at the index `index` of the list, if possible 
void LinkedList::addAt(int n, int index) {
    if (index < 0 || index > length())throw "index out of range";
    Link* toAdd = new Link();
    toAdd->value = n;
    if (index == 0) {
        toAdd->next = head;
        head = toAdd;
        return;
    }
    Link* ll = head;
    for (int i = 0; i < index - 1; ++i)ll = ll->next;
    toAdd->next = ll->next;
    ll->next = toAdd;
}

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
}
 
// Private function to provide funstionality to add
LinkedList::Link* LinkedList::getLast() {
	Link* ll = head;
	while (ll->next != nullptr)	ll = ll->next;
	// after while loop `ll->next == nullptr` meaning ll points to the last link
	return ll;
}
