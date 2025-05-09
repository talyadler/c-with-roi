#pragma once
#include "../list.h"
#include <iostream>

template <typename T> class AL : public list<T> {
public:
  /*
  CONSTRUCTORS
  */
  AL();
  ~AL();

  /*
  METHODS
  */

  // helper
  virtual unsigned int length() const;
  virtual bool isEmpty() const;
  virtual void validateInput() const;
  virtual void validateInput(unsigned int index) const;

  unsigned int getCapacity();
  bool atMaxCapacity();
  void increaseCapacity(unsigned int addedCap);

  // add
  virtual void addFirst(T value);
  virtual void addLast(T value);
  virtual void addAt(T value, unsigned int index);

  // remove
  virtual void removeFirst();
  virtual void removeLast();
  virtual void removeAt(unsigned int index);

  /*
  OVERLOADS
  */

  // operator << overload
  friend std::ostream &operator<<(std::ostream &out, const AL<T> &al);

  // operator [] overload
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;

private:
  T *data;
  unsigned int capacity;
  unsigned int size;
  unsigned int start = 0;
  unsigned int end = 0;

  // debug
  void show_start() const;
  void show_end() const;
  void show_start_end() const;
};

