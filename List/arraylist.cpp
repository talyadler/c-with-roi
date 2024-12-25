#include "arraylist.h"
#include <iostream>

/*
* CONSTRUCTORS
*/

ArrayList::ArrayList() : List() {
	data = new int[16];
	capacity = 16;
	size = 0;
}

/*
* DESTRUCTORS
*/

ArrayList::~ArrayList() {
	delete[] data;
}

/*
* USER METHODS
*/

// returns the length of the list
int ArrayList::length() const {
	return size;
} // O(1)

// returns whether the list is devoid of elements or not
bool ArrayList::isEmpty() const {
	return size == 0; // O(1)
} // O(1)

// adds the element `n` at the index `index` of the list, if possible 
void ArrayList::addAt(int n, int index){
	if (index < 0 || index > size){ // O(1)
		throw std::out_of_range("Index out of bounds"); // O(1)
	}
	addLast(data[size-1]); //O(n)
	for (int i = size; i >= index;i--){ //O(n)
		data[i] = data[i-1]; // O(1)
	} // O(n)
	data[index] = n; // O(1)
} //O(n)

//
void ArrayList::addLast(int i) {
	if (size == capacity) { // O(1)
		increaseCapacity(16); // O(n)
	}
	data[size] = i; // O(1)
	size++; // O(1)
} // O(n)

//
void ArrayList::addFirst(int i) {
	if (size == capacity) { // O(1)
		increaseCapacity(16); // O(n)
	}
	data[size] = i; // O(1)
	size++; // O(1)
} // O(n)

void ArrayList::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
} // O(n)

void ArrayList::removeLast() {
	if (isEmpty()) { // O(1)
		throw std::out_of_range("Arry is at minimum"); // O(1)
	}
	size--; // O(1)
} // O(1)

void ArrayList::removeFirst() {
	if (isEmpty()) { // O(1)
		throw std::out_of_range("Arry is at minimum"); // O(1)
	}
	size--; // O(1)
} // O(1)

// int ArrayList::numAt(int index) const {
int ArrayList::numAt(int index) const {
    if (index < 0 || index >= size) { // O(1)
        throw std::out_of_range("Index out of bounds"); // O(1)
    }
    return data[index]; // O(1)
} // O(1)


//-----------------------------------------------------------
/*
* HELPER FUNCTIONS
*/

int ArrayList::getCapacity() const {
	return capacity;
} // O(1)

void ArrayList::increaseCapacity(unsigned int addedCap) {
	int *newData = new int[capacity + addedCap]; // O(1)
	for (int i = 0; i < capacity ; i++) { // O(n)
		newData[i] = data[i]; // O(1)
	} // O(n*1) == O(n)
	delete[] data; // O(n)
	data = newData; // O(1)
	capacity += addedCap; // O(1)
} // O(n)

