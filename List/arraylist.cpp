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
	if (size == capacity) {
		increaseCapacity(16);
	}
	data[size] = i;
	size++;
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
	if (index < 0 || index > size){
		throw std::out_of_range("Index out of bounds");
	}
	return data[index];
}
