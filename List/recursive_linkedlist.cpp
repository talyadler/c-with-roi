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

int RecursiveLinkedList::length() {
	if (isEmpty()){
		return 0;
	}
	return head->length()+1;
}

int counter = 0;
int RecursiveLinkedList::RecursiveLink::length() {
	if (isLast()){
		return counter++;
	}
	return next->length()+1;
}

int RecursiveLinkedList::numAt(int index) const {
	// RecursiveLink* rll = head;
	// if (index < 0) throw "index out of range";
	return 0;
}

int RecursiveLinkedList::RecursiveLink::numAt(int index) const {
	return 0;
}

bool RecursiveLinkedList::isEmpty(){
	// std::cout << head << std::endl;
	return head == nullptr;
}

bool RecursiveLinkedList::RecursiveLink::isEmpty(){
	// std::cout << next << std::endl;
	return next == nullptr;
}

void RecursiveLinkedList::addAt(int n, int index){
	return;
}

void RecursiveLinkedList::removeAt(int index){
	return;
}