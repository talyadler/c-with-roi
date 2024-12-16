#include "arraylist.h"
#include <iostream>

// constructors
ArrayList::ArrayList() : List() {
	data = new int[16];
	capacity = 16;
	size = 0;
}

// destructors
ArrayList::~ArrayList() {
	delete[] data;
}

// user methods
void ArrayList::add(int i) {
	if (size == capacity) {
		increaseCapacity(16);
	}
	data[size] = i;
	size++;
}

void ArrayList::remove() {
	if (size == 0) {
		throw std::out_of_range("Arry is at minimum");
	}
	size--;
}

// int ArrayList::numAt(int index) const {
int ArrayList::numAt(int index) const {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    return data[index];
}

// returns the length of the list
int ArrayList::length() const {
	return size;
}

// returns whether the list is devoid of elements or not
bool ArrayList::isEmpty() const {
	return size == 0;
}

// adds the element `n` at the index `index` of the list, if possible 
void ArrayList::addAt(int n, int index){
	if (index < 0 || index > size){
		throw std::out_of_range("Index out of bounds");
	}
	add(data[size-1]);
	for (int i = size; i >= index;i--){
		data[i] = data[i-1];
	}
	data[index] = n;
}

void ArrayList::removeAt(int index) {
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bounds");
    }
    for (int i = index; i < size - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
}

//-----------------------------------------------------------
//helper functions
void ArrayList::increaseCapacity(unsigned int addedCap) {
	int *newData = new int[capacity + addedCap];
	for (int i = 0; i < capacity ; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

int ArrayList::getCapacity() const {
	return capacity;
}
