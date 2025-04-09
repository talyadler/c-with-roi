#pragma once
#include "../list.h"
#include <iostream>

template<typename T>
class AL : public list<T> {
public:
    /*
    FIELDS
    */

    /*
    CONSTRUCTORS
    */
    AL() {
        data = new T[16];
        capacity = 16;
        size = 0;
        start = 0;
        end = -1;
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
        return length() == 0;
    }

    unsigned int getCapacity(){
        return capacity;
    }

    bool atMaxCapacity(){
        return size == capacity;
    }

    void isOutOfRange() const{
        if (isEmpty()) throw std::out_of_range("empty list");
    }

    void isOutOfRange(unsigned int index) const{
        if (isEmpty()) throw std::out_of_range("empty list");
        if ((index < start) && (index > end)) throw std::out_of_range("index out of bounds");
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
        al.show_start_end();
        out << "[";
        for (int i = al.start; i <= al.end; i++){
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
    unsigned int start = 0;
    unsigned int end = 0;

    //debug
    void show_start()const{
        printf("%d\n",start);
    }
    void show_end()const{
        printf("%d\n",end);
    }
    void show_start_end()const{
        printf("start: %d\t end:%d\t size:%d\n",start,end,size);
    }
};

// TODO: implement start, end index pointer
// [3,9,5,6,7,8]
//    ^     ^
//    |     |
//    s     e

//add
template<typename T> void AL<T>::addFirst(T value){
    if (atMaxCapacity()) increaseCapacity(16);
    addAt(value,0);
}

//add
template<typename T> void AL<T>::addLast(T value){
    if (atMaxCapacity()) increaseCapacity(16);
    data[length()] = value;
    end ++;
    size = (end==1) ? 1: end-start;
}

//add
template<typename T> void AL<T>::addAt(T value, unsigned int index){
    isOutOfRange(index);
    addLast(data[size-1]);
    for (int i = end; i >= index+start; i--){
        data[i] = data[i-1];
	}
	data[index+start] = value;
    end ++;
    size = end-start;
}

//remove
template<typename T> void AL<T>::removeFirst(){
    isOutOfRange();
    start++;
    size = end-start;
}

template<typename T> void AL<T>::removeLast(){
    isOutOfRange();
    end--;
    size = end-start;
}

template<typename T> void AL<T>::removeAt(unsigned int index){
    isOutOfRange(index);
    for (int i = index+start; i <= end; ++i) {
        std::cout << "data[" << i << "]" << data[i] << "\t" <<data[i+1] << "\n";
        data[i] = data[i + 1];
    }
    end--;
    size = end-start;
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
