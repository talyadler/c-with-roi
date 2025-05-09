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
  friend std::ostream& operator<<(std::ostream &out, const LinkedList<T> &ll);
  // operator [] overload
  virtual T& operator[](unsigned int index);

  // operator[] overload const
  virtual const T& operator[](unsigned int index) const;

  // operator= overload
  virtual LinkedList<T>& operator=(const LinkedList<T> &o);

  // operator== overload
  virtual bool operator==(const LinkedList<T> &o) const;

  // operator+ overload combine 2 lists
  virtual LinkedList<T> operator+(const LinkedList<T> &o) const;
  // operator+ overload add link
  virtual LinkedList<T> operator+(const T &e) const;

private:
  /*
  Fields
  */
  Link<T> *head = nullptr;
  Link<T> *tail = nullptr;
  unsigned int size = 0;

  // validation
  virtual void validateInput() const;

  // validation
  virtual void validateInput(unsigned int index) const;

  // get Link
  Link<T> *getByValue(T value) const;
};
