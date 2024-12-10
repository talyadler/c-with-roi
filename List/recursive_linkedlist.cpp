#include "recursive_linkedlist.h"


void RecursiveLinkedList::add(int i) {
	if (isEmpty()) {
		head = new RecursiveLink(i);
		return;
	}
	head->add(i);
}

void RecursiveLinkedList::RecursiveLink::add(int value) {
	if (next == nullptr) { 
		// I'm the last link
		next = new RecursiveLink(value);
		return;
	}
	// now I'm not the last link
	next->add(value);
}

void RecursiveLinkedList::remove() {
	if (isEmpty()) {
		return;
	} 
	if (head->isLast()) { // is head the last link in chain?
		delete head;
		head = nullptr;
		return;
	}
	head->remove();
}

void RecursiveLinkedList::RecursiveLink::remove() {
	if (hasNext() && next->isLast()){
		delete next;
		next = nullptr;
		return;
	}
	next->remove();
}
