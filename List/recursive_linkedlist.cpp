#include "recursive_linkedlist.h"
#include <iostream>

void RecursiveLinkedList::add(int i) {
	if (isEmpty()) {
		head = new RecursiveLink(i);
		// std::cout << "add head " << head << std::endl;
		return;
	}
	head->add(i);
}

void RecursiveLinkedList::RecursiveLink::add(int value) {
	if (isLast()) { 
		// I'm the last link
		next = new RecursiveLink(value);
		// std::cout << "add next " << next << std::endl;
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

int RecursiveLinkedList::length() const {
	if (isEmpty()){
		return 0;
	}
	return head->length();
}

int RecursiveLinkedList::RecursiveLink::length() const {
	if (isLast()){
		return 1;
	}
	return next->length()+1;
}

int RecursiveLinkedList::numAt(int index) const {
	if (index < 0 || index >= length()) throw "index out of range";
	return head->numAt(index);
}

int RecursiveLinkedList::RecursiveLink::numAt(int index) const {
	if (index == 0){
		return value;
	}
	return next->numAt(index-1);
}

void RecursiveLinkedList::addAt(int n, int index){
	if (index < 0 || index >= length()) throw "index out of range";
	return head->addAt(n, index);
}

void RecursiveLinkedList::RecursiveLink::addAt(int n, int index){
	if (index == 1){
		next = new RecursiveLink(n, next);
		return;
	}
	return next->addAt(n, index-1);
}

void RecursiveLinkedList::removeAt(int index){
	return;
}

void RecursiveLinkedList::RecursiveLink::removeAt(int index){
	return;
}