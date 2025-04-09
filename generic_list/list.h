#pragma once

template<typename T>
class list{
public:
      /*
  METHODS
  */

  // helpers
  virtual bool isEmpty() const = 0; 
  virtual int length() const  = 0;

  // add
  virtual void addLast(T value) = 0; 
  virtual void addFirst(T value) = 0; 
  virtual void addAt(T value, unsigned int index) = 0; 

  // remove
  virtual void removeLast() = 0; 
  virtual void removeFirst() = 0; 
  virtual void removeAt(unsigned int index) = 0; 
  virtual void clear() = 0; 

  // value
  virtual T valueFirst() const = 0; 
  virtual T valueLast() const = 0; 

  // replace
  virtual void replaceByValue(T newValue, T byValue) = 0;

  // validation
  virtual void validateInput() const = 0;
  virtual void validateInput(unsigned int index) const = 0;
};