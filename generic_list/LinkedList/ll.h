#pragma once
#include "../list.h"
#include "link.h"
#include <iostream>

template <typename T> class LinkedList : public list<T> {
public:
  /*
  CONSTRUCTORS
  */
  // defualt
  LinkedList();
  virtual ~LinkedList();

  // copy constructor
  LinkedList(const LinkedList<T> &other);

  /*
  METHODS
  */

  // helpers
  virtual bool isEmpty() const;
  virtual int length() const;

  // add
  virtual void addLast(T value);
  virtual void addFirst(T value);
  virtual void addAt(T value, unsigned int index);

  // remove
  virtual void removeLast();
  virtual void removeFirst();
  virtual void removeAt(unsigned int index);
  virtual void clear();

  // value
  virtual T valueFirst() const;
  virtual T valueLast() const;

  // replace
  virtual void replaceByValue(T newValue, T byValue);

  // overall
  virtual T max();
  virtual T min();
  virtual T sum();

  /*
  OVERLOADS
  */

  // operator << overload
  friend std::ostream &operator<<(std::ostream &out, const LinkedList<T> &ll) {
    ll.validateInput();
    out << "NULL <-";
    for (Link<T> *temp = ll.head; temp != nullptr; temp = temp->next) {
      out << "-> " << temp->value << " <-";
    }
    return out << "-> NULL";
  }

  // operator [] overload
  T &operator[](unsigned int index) {
    validateInput(index);
    Link<T> *temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp->value;
  }

  // operator[] overload const
  const T &operator[](unsigned int index) const {
    validateInput(index);
    Link<T> *temp = head;
    for (int i = 0; i < index; i++) {
      temp = temp->next;
    }
    return temp->value;
  }

  // operator= overload
  LinkedList<T> &operator=(const LinkedList<T> &o) {
    if (this == &o)
      return *this;
    this->clear();
    for (Link<T> *temp = o.head; temp != nullptr; temp = temp->next) {
      this->addLast(temp->value);
    }
    return *this;
  }

  // operator== overload
  bool operator==(const LinkedList<T> &o) const { // if (ll1 == ll2)
    if (length() != o.length())
      return false;
    for (unsigned int i = 0; i < length(); i++) {
      if ((*this)[i] != o[i])
        return false;
    }
    return true;
    // Link<T>* eval = head;
    // for (Link<T>* temp = o.head; temp != nullptr; temp = temp->next) {
    //     if (temp->value != eval->value) {
    //         return false;
    //     }
    //     eval = eval->next;
    // }
    // return true;
  }

  // operator+ overload combine 2 lists
  LinkedList<T> operator+(const LinkedList<T> &o) const { // ll3 = ll1 + ll2
    LinkedList<T> added;
    for (Link<T> *temp = this->head; temp != nullptr; temp = temp->next) {
      added.addLast(temp->value);
    }
    for (Link<T> *temp = o.head; temp != nullptr; temp = temp->next) {
      added.addLast(temp->value);
    }
    return added;
  }

  // operator+ overload add link
  LinkedList<T> operator+(const T &e) const { // ll3 = ll1 + 5;
    LinkedList<T> added;
    for (Link<T> *temp = this->head; temp != nullptr; temp = temp->next) {
      added.addLast(temp->value);
    }
    added.addLast(e);
    return added;
  }

private:
  /*
  Fields
  */
  Link<T> *head = nullptr;
  Link<T> *tail = nullptr;
  unsigned int size = 0;

  // validation
  virtual void validateInput() const {
    if (isEmpty())
      throw std::out_of_range("empty list");
  }

  // validation
  virtual void validateInput(unsigned int index) const {
    validateInput();
    if (index >= length())
      throw std::out_of_range("index out of bounds");
  }

  // get Link
  Link<T> *getByValue(T value) const;
};
