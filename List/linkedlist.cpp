#include "linkedlist.h"
// #include <iostream>

LinkedList::LinkedList() : List() {}

LinkedList::LinkedList() : head(nullptr) {}

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
	if (head == nullptr) {
		return;
	}
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
int LinkedList::length() {
    int __counter = 0;
    Link* ll = head;
    while (ll != nullptr) {
        __counter++;
        ll = ll->next;
    }
    return __counter;
}

// returns whether the list is devoid of elements or not
bool LinkedList::isEmpty() {
    return head == nullptr;
}

/*
// adds the element `n` at the index `index` of the list, if possible 
void LinkedList::addAt(int n, int index){
	return;
}

// removes the element at the index `index` of the list, if possible 
void LinkedList::removeAt(int index){
	return;
}
*/
 
// Private function to provide funstionality to add
LinkedList::Link* LinkedList::getLast() {
	Link* ll = head;
	while (ll->next != nullptr)	ll = ll->next;
	// after while loop `ll->next == nullptr` meaning ll points to the last link
	return ll;
}
