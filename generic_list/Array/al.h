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
  virtual int length() const;
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
  virtual void clear();

  // value
  virtual T valueFirst() const;
  virtual T valueLast() const;

  // replace
  virtual void replaceByValue(T newValue, T byValue);

  /*
  OVERLOADS
  */

  // operator << overload
  friend std::ostream &operator<<(std::ostream &out, const AL<T> &al){
    al.validateInput();
    al.show_start_end();
    out << "[";
    for (int i = al.start; i <= al.end; i++) {
      out << " " << al[i] << ", ";
    }
    return out << "]";
  }

  // operator [] overload
  T &operator[](unsigned int index);
  const T &operator[](unsigned int index) const;

private:
  T *data;
  unsigned int capacity;
  unsigned int size;
  unsigned int start = 0;
  int end = 0;

  // debug
  void show_start() const;
  void show_end() const;
  void show_start_end() const;
};

/*
CONSTRUCTORS
*/
template <typename T> AL<T>::AL() {
  data = new T[16];
  capacity = 16;
  size = 0;
  start = 0;
  end = -1;
}
template <typename T> AL<T>::~AL() { delete[] data; }

/*
METHODS
*/

// helper
template <typename T> int AL<T>::length() const { return size; }

template <typename T> bool AL<T>::isEmpty() const { return length() == 0; }

template <typename T> unsigned int AL<T>::getCapacity() { return capacity; }

template <typename T> bool AL<T>::atMaxCapacity() { return size == capacity; }

template <typename T> void AL<T>::validateInput() const {
  if (isEmpty())
    throw std::out_of_range("empty list");
}

template <typename T> void AL<T>::validateInput(unsigned int index) const {
  if (isEmpty())
    throw std::out_of_range("empty list");
  if ((index < start) && (index > end))
    throw std::out_of_range("index out of bounds");
}

/*
OVERLOADS
*/

// operator [] overload
template <typename T> T& AL<T>::operator[](unsigned int index) {
  validateInput(index);
  return data[index];
}

template<typename T> const T& AL<T>::operator[](unsigned int index) const {
  validateInput(index);
  return data[index];
}

// debug
template <typename T> void AL<T>::show_start() const { printf("%d\n", start); }
template <typename T> void AL<T>::show_end() const { printf("%d\n", end); }
template <typename T> void AL<T>::show_start_end() const {
  printf("start: %d\t end:%d\t size:%d\n", start, end, size);
}

// add
template <typename T> void AL<T>::addFirst(T value) {
  if (atMaxCapacity())
    increaseCapacity(16);
  addAt(value, 0);
}

// add
template <typename T> void AL<T>::addLast(T value) {
  if (atMaxCapacity())
    increaseCapacity(16);
  data[length()] = value;
  end++;
  size = (end == 1) ? 1 : end - start;
}

// add
template <typename T> void AL<T>::addAt(T value, unsigned int index) {
  validateInput(index);
  addLast(data[size - 1]);
  for (int i = end; i >= index + start; i--) {
    data[i] = data[i - 1];
  }
  data[index + start] = value;
  end++;
  size = end - start;
}

// remove
template <typename T> void AL<T>::removeFirst() {
  validateInput();
  start++;
  size = end - start;
}

template <typename T> void AL<T>::removeLast() {
  validateInput();
  end--;
  size = end - start;
}

template <typename T> void AL<T>::removeAt(unsigned int index) {
  validateInput(index);
  for (int i = index + start; i <= end; ++i) {
    std::cout << "data[" << i << "]" << data[i] << "\t" << data[i + 1] << "\n";
    data[i] = data[i + 1];
  }
  end--;
  size = end - start;
}

// helper
template <typename T> void AL<T>::increaseCapacity(unsigned int addedCap) {
  T *newData = new T[capacity + addedCap];
  for (int i = 0; i < capacity; i++) {
    newData[i] = data[i];
  }
  delete[] data;
  data = newData;
  capacity += addedCap;
}

// value
template<typename T> T AL<T>::valueFirst() const{
  validateInput();
  return data[0];
}
template<typename T> T AL<T>::valueLast() const{
  validateInput();
  return data[length()-1];
}

// replace
template<typename T> void AL<T>::replaceByValue(T newValue, T byValue){}

template<typename T> void AL<T>::clear(){}