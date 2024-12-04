#include "linkedlist.h"

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

LinkedList::Link* LinkedList::getLast() {
	Link* ll = head;	
	while (ll->next != nullptr) ll = ll->next;
	// after while loop `ll->next == nullptr` meaning ll points to the last link
	return ll;
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

int LinkedList::numAt(int index) const {
	Link* l = head; 
	while (index > 0){
		if (l == nullptr) {
			throw "index out of range";
		}
		index --;
	}
	if (l == nullptr) {
		throw "index out of range";
	}
	return l->value;
}
