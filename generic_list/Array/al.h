#pragma once
#include <iostream>

template<typename T>
class AL {
public:
    /*
    FIELDS
    */

    /*
    CONSTRUCTORS
    */
    AL() {
        data = new T[3];
        capacity = 3;
        size = 0;
    }
    ~AL() {
        delete[] data;
    }

    /*
    METHODS
    */

    //helper
    unsigned int length() const {
        return size;
    }

    bool isEmpty() const {
        return size == 0;
    }

    unsigned int getCapacity(){
        return capacity;
    }

    bool maxCapacity(){
        return size == capacity;
    }

    void isOutOfRange() const{
        if (isEmpty()) throw std::out_of_range("empty list");
    }

    void isOutOfRange(unsigned int index) const{
        if (isEmpty()) throw std::out_of_range("empty list");
        if (index >= length()) throw std::out_of_range("index out of bounds");
    }

    void increaseCapacity(unsigned int addedCap);

    //add
    void addFirst(T value);
    void addLast(T value);
    void addAt(T value, unsigned int index);

    //remove
    void removeFirst();
    void removeLast();
    void removeAt(unsigned int index);

    /*
    OVERLOADS
    */

    //operator << overload
    friend std::ostream& operator<<(std::ostream& out, const AL<T>& al) {
        al.isOutOfRange();
        out << "[";
        for (int i = 0; i < al.length(); i++){
            out << " " << al[i] << ", ";
        }
        return out << "]";
    }

    //operator [] overload
    T& operator[](unsigned int index) {
        isOutOfRange(index);
        return data[index];
    }

    const T& operator[](unsigned int index) const {
        isOutOfRange(index);
        return data[index];
    }
    
    
private:
    T* data;
    unsigned int capacity;
    unsigned int size;
};

//add
template<typename T> void AL<T>::addFirst(T value){
    if (maxCapacity()) increaseCapacity(1);
    addAt(value,0);
    size++;
}

//add
template<typename T> void AL<T>::addLast(T value){
    if (maxCapacity()) increaseCapacity(1);
    data[length()] = value;
    size ++;
}

//add
template<typename T> void AL<T>::addAt(T value, unsigned int index){
    isOutOfRange(index);
    addLast(data[size-1]);
    for (int i = length(); i >= index; i--){
		data[i] = data[i-1]; 
	}
	data[index] = value;
    size++;
}

// TODO: implement start, end index pointer
// [3,9,5,6,7,8]
//    ^     ^
//    |     |
//    s     e

//remove
template<typename T> void AL<T>::removeFirst(){
    isOutOfRange();
    removeAt(0);
}

template<typename T> void AL<T>::removeLast(){
    isOutOfRange();
    size--;
}

template<typename T> void AL<T>::removeAt(unsigned int index){
    isOutOfRange(index);
    for (int i = index; i < length() - 1; ++i) {
        data[i] = data[i + 1];
    }
    size--;
}

//helper
template<typename T> void AL<T>::increaseCapacity(unsigned int addedCap){
    T* newData = new T[capacity+addedCap];
    for (int i = 0; i < capacity; i++){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
    capacity += addedCap;
}
