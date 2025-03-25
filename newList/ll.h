#pragma once
#include <iostream>
#include "link.h"

template <typename T>
class LinkedList {
public:
    //fields

    //construtors
    LinkedList() {}
    ~LinkedList() {
        while (!isEmpty()) removeLast();
    }

    //methods
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

    //operator overload
    friend std::ostream& operator<<(std::ostream& out, const LinkedList<T>& ll) {
        if (ll.isEmpty()) return out << "empty list please add";
        out << "NULL <- ";
        for (Link<T>* temp = ll.head; temp != nullptr; temp = temp->next){
            out << "-> " << temp->value << " <-";
        }
        return out << "-> NULL";
    } 

private: 
    Link<T>* head = nullptr;
    Link<T>* tail = nullptr;
    unsigned int size = 0;
};

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

template <typename T> void LinkedList<T>::removeLast() {
    if (isEmpty())
        throw "empty list";
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
    if (isEmpty())
        throw "empty list";
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
    if (isEmpty()) throw "empty list";
    if (index >= length()) throw "index out of bounds";
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



//LinkedList<int> ll;
//ll.addLast(0);
//ll.addLast(1);
//ll.addLast(2);
//
//std::cout << ll << std::endl; // NULL <- 0 <-> 1  <-> 2 -> NULL
