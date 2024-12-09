#include "arraylist.h"
#include <iostream>

ArrayList::ArrayList() : List() {
	data = new int[16];
	capacity = 16;
	size = 0;
}

ArrayList::~ArrayList() {
	delete[] data;
}

void ArrayList::increaseCapacity(unsigned int addedCap) {
	int *newData = new int[capacity + addedCap];
	for (int i = 0; i < capacity ; i++) {
		newData[i] = data[i];
	}
	delete[] data;
	data = newData;
}

void ArrayList::add(int i) {
	// std::cout << size << "\t" << i << std::endl;
	if (size == capacity) {
		increaseCapacity(16);
	}
	data[size] = i;
	size++;
	// std::cout << size << "\t" << i << std::endl;
}

int ArrayList::getCapacity() {
	return capacity;
}

void ArrayList::remove() {
	if (size == 0) {
		throw std::out_of_range("Arry is at minimum");
	}
	size--;
}

int ArrayList::numAt(int index) const {
	// std::cout << size << "<--- size \t index--->" << index << std::endl;
	int _size_check = size;
	_size_check --;
	if (index < 0 || index > _size_check){
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}

// returns the length of the list
int ArrayList::length(){
	int __counter = 1;
	for (int i = 1; i < size; i++) __counter ++;
	return __counter;
}

// returns whether the list is devoid of elements or not
bool ArrayList::isEmpty(){
	bool _check = false;
	if (size == 0){
		_check = true;
	}
	return _check;
}

/*
// adds the element `n` at the index `index` of the list, if possible 
void ArrayList::addAt(int n, int index){
	return;
}

// removes the element at the index `index` of the list, if possible 
void ArrayList::removeAt(int index){
	return;
}
*/