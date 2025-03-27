#pragma once
#include <iostream>
#include "link.h"

template <typename T>
class LinkedList {
public:
    /*
    fields
    */

    /*
    CONSTRUCTORS
    */
    LinkedList() {}
    ~LinkedList() {
        while (!isEmpty()) removeLast();
    }

    /*
    METHODS
    */

    //helpers
    bool isEmpty() const{
        return size == 0;
    }
    int length() const{
        return size;
    }
    bool isOutOfRange() const{
        if (isEmpty()) throw std::out_of_range("empty list");
        return isEmpty();
    }
    bool isOutOfRange(unsigned int index) const{
        if (isEmpty()) throw std::out_of_range("empty list");
        if (index >= length()) throw std::out_of_range("index out of bounds");
        return (index >= length()) || isEmpty();
    }
    
    //add
    void addLast(T value);
    void addFirst(T value);
    void addAt(T value, unsigned int index);

    //remove
    void removeLast();
    void removeFirst();
    void removeAt(unsigned int index);

    //get Link
    Link<T>* getFirst() const;
    Link<T>* getLast() const;
    Link<T>* getAt(unsigned int index) const;
    Link<T>* getByValue(T value) const;

    //value
    T valueFirst() const;
    T valueLast() const;
    T valueAt(unsigned int index) const;

    //replace
    void replaceFirst(T newValue);
    void replaceLast(T newValue);
    void replaceAt(T newValue, unsigned int index);
    void replaceByValue(T newValue, T byValue);

    //overall
    T max();
    T min();
    T sum();

    /*
    OVERLOADS
    */

    //operator << overload
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& ll) {
        if (ll.isEmpty()) return out << "empty list please add";
        out << "NULL <-";
        for (Link<T>* temp = ll.head; temp != nullptr; temp = temp->next){
            out << "-> " << temp->value << " <-";
        }
        return out << "-> NULL";
    }

    //operator [] overload
    T& operator[](unsigned int index) {
        isOutOfRange(index);
        Link<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->value;
    }
    
    const T& operator[](unsigned int index) const{
        isOutOfRange(index);
        Link<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->value;   
    }

private: 
    Link<T>* head = nullptr;
    Link<T>* tail = nullptr;
    unsigned int size = 0;
};

/*
METHODS
*/

//add
template <typename T> 
void LinkedList<T>::addLast(T value) {
    if (isEmpty()) {
        head = tail = new Link<T>(value);
    } else {
        tail = tail->next = new Link<T>(tail, value, nullptr);
    }
    size++;
}

template <typename T>
void LinkedList<T>::addFirst(T value){
    if (isEmpty()) {
        tail = head = new Link<T>(value);
    } else {
        head = head->prev = new Link<T>(nullptr, value, head);
    }
    size ++;
}


template <typename T>
void LinkedList<T>::addAt(T value, unsigned int index){
    if (index > length()) throw "index out of bounds";
    if (index == 0) {
       addFirst(value);
       return;
    }
    if (index == length()) {
       addLast(value);
       return;
    }
    Link<T>* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    temp->next = temp->next->prev = new Link<T>(temp, value, temp->next);
    size ++;
}

//remove
template <typename T> void LinkedList<T>::removeLast() {
    isOutOfRange();
    if (length() == 1) {
        delete tail;
        tail = head = nullptr;
    } else {
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
    }
    size--;
}

template <typename T> void LinkedList<T>::removeFirst() {
    isOutOfRange();
    if (length() == 1) {
        delete head;
        head = tail = nullptr;
        return;
    } else {
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
    }
    size--;
}

template <typename T> void LinkedList<T>::removeAt(unsigned int index) {
    isOutOfRange(index);
    if (index == 0) {
        removeFirst();
        return;
    }
    if (index == length()-1){
        removeLast();
        return;
    }
    Link<T>* temp = head;
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    delete temp;
    size --;
}

//get
template <typename T> Link<T>* LinkedList<T>::getFirst() const{
    isOutOfRange();
    return head;
}

template <typename T> Link<T>* LinkedList<T>::getLast() const{
    isOutOfRange();
    return tail;
}

template <typename T> Link<T>* LinkedList<T>::getAt(unsigned int index) const{
    isOutOfRange(index);
    Link<T>* temp = head;
    for (int i = 0; i < index; i++) {
        temp = temp->next;
    }
    return temp;
}

template <typename T> Link<T>* LinkedList<T>::getByValue(T value) const{
    isOutOfRange();
    Link<T>* temp = head;
    do {
        if (temp->value == value || temp->next == nullptr) break;
        temp = temp->next;
    }
    while (temp->value != value);
    return (temp->value == value) ? temp : nullptr;
}

// value
template <typename T> T LinkedList<T>::valueFirst() const{
    isOutOfRange();
    return head->value;
}

template <typename T> T LinkedList<T>::valueLast() const{
    isOutOfRange();
    return tail->value;
}

template <typename T> T LinkedList<T>::valueAt(unsigned int index) const{
    isOutOfRange(index);
    Link<T>* temp = head;
    for (int i = 0; i < index; i++){
        temp = temp->next;
    }
    return temp->value;
}

//replace
template <typename T> void LinkedList<T>::replaceFirst(T newValue){
    isOutOfRange();
    head->value = newValue;
}

template <typename T> void LinkedList<T>::replaceLast(T newValue){
    isOutOfRange();
    tail->value = newValue;
}

template <typename T> void LinkedList<T>::replaceAt(T newValue, unsigned int index){
    isOutOfRange();
    Link<T>* temp = getAt(index);
    temp->value = newValue;
}

template <typename T> void LinkedList<T>::replaceByValue(T newValue, T byValue){
    isOutOfRange();
    Link<T>* temp = getByValue(byValue);
    temp->value = newValue;
}

//overall
template <typename T> T LinkedList<T>::max(){
    isOutOfRange();
    T max = head->value;
    for (Link<T>* temp = head->next; temp != nullptr; temp = temp->next){
        // std::cout << max << "\\" << temp->value << "\n";
        max = (max > temp->value) ? max : temp->value;
    }
    return max;
}

template <typename T> T LinkedList<T>::min(){
    isOutOfRange();
    T min = head->value;
    for (Link<T>* temp = head->next; temp != nullptr; temp = temp->next){
        min = (min < temp->value) ? min : temp->value;
    }
    return min;
}

template <typename T> T LinkedList<T>::sum(){
    isOutOfRange();
    T sum = head->value;
    for (Link<T>* temp = head->next; temp != nullptr; temp = temp->next){
        sum = sum+temp->value;
    }
    return sum;
}