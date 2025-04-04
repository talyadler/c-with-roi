#pragma once
#include <iostream>
#include "link.h"

template <typename T>
class LinkedList {
public:
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

    // helpers
    bool isEmpty() const{
        return size == 0;
    }
    int length() const{
        return size;
    }
    
    //add
    void addLast(T value);
    void addFirst(T value);
    void addAt(T value, unsigned int index);

    //remove
    void removeLast();
    void removeFirst();
    void removeAt(unsigned int index);

    //value
    T valueFirst() const;
    T valueLast() const;

    //replace
    void replaceByValue(T newValue, T byValue);

    //overall
    T max();
    T min();
    T sum();

    /*
    OVERLOADS
    */

    //operator << overload
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& ll){
        ll.validateInput();
        out << "NULL <-";
        for (Link<T>* temp = ll.head; temp != nullptr; temp = temp->next){
            out << "-> " << temp->value << " <-";
        }
        return out << "-> NULL";
    }

    //operator [] overload
    T& operator[](unsigned int index) {
        validateInput(index);
        Link<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->value;
    }
    
    const T& operator[](unsigned int index) const{
        validateInput(index);
        Link<T>* temp = head;
        for (int i = 0; i < index; i++) {
            temp = temp->next;
        }
        return temp->value;   
    }

    //operator=
/*
    LinkedList<T>& operator=(const LinkedList<T>& o){ // ll2 = ll1
        validateInput();
        for (Link<T>* tempL = head; tempL != nullptr; tempL = tempL->next){
            .addLast(tempL->value);
        }
        return ;
    }
/*
    //operator==
    bool operator==(const LinkedList<T>& o) const; // if (ll1 == ll2)

    //operator+
    LinkedList<T> operator+(const LinkedList<T>& o) const; // ll3 = ll1 + ll2
    LinkedList<T> operator+(const T& e) const; // ll3 = ll1 + 5;
*/

private: 
    /*
    Fields
    */
    Link<T>* head = nullptr;
    Link<T>* tail = nullptr;
    unsigned int size = 0;

    // validation
    void validateInput() const{
        if (isEmpty()) throw std::out_of_range("empty list");
    }

    // validation
    void validateInput(unsigned int index) const{
        validateInput();
        if (index >= length()) throw std::out_of_range("index out of bounds");
    }

    //get Link
    Link<T>* getByValue(T value) const;
};

/*
METHODS
*/

//add
template <typename T> void LinkedList<T>::addLast(T value) {
    if (isEmpty()) {
        head = tail = new Link<T>(value);
    } else {
        tail = tail->next = new Link<T>(tail, value, nullptr);
    }
    size++;
}

//add
template <typename T> void LinkedList<T>::addFirst(T value){
    if (isEmpty()) {
        tail = head = new Link<T>(value);
    } else {
        head = head->prev = new Link<T>(nullptr, value, head);
    }
    size ++;
}

//add
template <typename T> void LinkedList<T>::addAt(T value, unsigned int index){
    if (index > length()) throw std::out_of_range("index out of bounds");
    if (index == 0) {
       addFirst(value);
       return;
    }
    if (index == length()) {
       addLast(value);
       return;
    }
    Link<T>* temp = head;
    for (int i = 1; i < index; i++) {
        temp = temp->next;
    }
    // std::cout << "temp->value = " << temp->value << std::endl;
    temp->next = temp->next->prev = new Link<T>(temp, value, temp->next);
    size ++;
}

//remove
template <typename T> void LinkedList<T>::removeLast() {
    validateInput();
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

//remove
template <typename T> void LinkedList<T>::removeFirst() {
    validateInput();
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

//remove
template <typename T> void LinkedList<T>::removeAt(unsigned int index) {
    validateInput(index);
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

// value
template <typename T> T LinkedList<T>::valueFirst() const{
    validateInput();
    return head->value;
}

// value
template <typename T> T LinkedList<T>::valueLast() const{
    validateInput();
    return tail->value;
}

//replace
template <typename T> void LinkedList<T>::replaceByValue(T newValue, T byValue){
    validateInput();
    Link<T>* temp = getByValue(byValue);
    temp->value = newValue;
}

//overall
template <typename T> T LinkedList<T>::max(){
    validateInput();
    T max = head->value;
    for (Link<T>* temp = head->next; temp != nullptr; temp = temp->next){
        max = (max > temp->value) ? max : temp->value;
    }
    return max;
}

//overall
template <typename T> T LinkedList<T>::min(){
    validateInput();
    T min = head->value;
    for (Link<T>* temp = head->next; temp != nullptr; temp = temp->next){
        min = (min < temp->value) ? min : temp->value;
    }
    return min;
}

//overall
template <typename T> T LinkedList<T>::sum(){
    validateInput();
    T sum = head->value;
    for (Link<T>* temp = head->next; temp != nullptr; temp = temp->next){
        sum = sum+temp->value;
    }
    return sum;
}

//get
template <typename T> Link<T>* LinkedList<T>::getByValue(T value) const{
    validateInput();
    for (Link<T>* temp = head; temp != nullptr; temp = temp->next)
        if (temp->value == value) return temp;
    return nullptr;
}

/*
OVERLOADS
*/

// template <typename T> std::ostream& operator<<(std::ostream& out, const LinkedList<T>& ll);