#include "ll.h"

/*
CONSTRUCTORS
*/
// defualt
template <typename T> LinkedList<T>::LinkedList() {}
template <typename T> LinkedList<T>::~LinkedList() { clear(); }

// copy constructor
template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &other)
    : head(nullptr), tail(nullptr) {
  for (Link<T> *current = other.head; current != nullptr;
       current = current->next) {
    addLast(current->value);
  }
}

/*
METHODS
*/

// helpers
template <typename T> bool LinkedList<T>::isEmpty() const { return size == 0; }
template <typename T> int LinkedList<T>::length() const { return size; }

// add
template <typename T> void LinkedList<T>::addLast(T value) {
  if (isEmpty()) {
    head = tail = new Link<T>(value);
  } else {
    tail = tail->next = new Link<T>(tail, value, nullptr);
  }
  size++;
}

// add
template <typename T> void LinkedList<T>::addFirst(T value) {
  if (isEmpty()) {
    tail = head = new Link<T>(value);
  } else {
    head = head->prev = new Link<T>(nullptr, value, head);
  }
  size++;
}

// add
template <typename T> void LinkedList<T>::addAt(T value, unsigned int index) {
  if (index > length())
    throw std::out_of_range("index out of bounds");
  if (index == 0) {
    addFirst(value);
    return;
  }
  if (index == length()) {
    addLast(value);
    return;
  }
  Link<T> *temp = head;
  for (int i = 1; i < index; i++) {
    temp = temp->next;
  }
  temp->next = temp->next->prev = new Link<T>(temp, value, temp->next);
  size++;
}

// remove
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

// remove
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

// remove
template <typename T> void LinkedList<T>::removeAt(unsigned int index) {
  validateInput(index);
  if (index == 0) {
    removeFirst();
    return;
  }
  if (index == length() - 1) {
    removeLast();
    return;
  }
  Link<T> *temp = head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  temp->next->prev = temp->prev;
  temp->prev->next = temp->next;
  delete temp;
  size--;
}

template <typename T> void LinkedList<T>::clear() {
  while (!isEmpty())
    removeLast();
}

// value
template <typename T> T LinkedList<T>::valueFirst() const {
  validateInput();
  return head->value;
}

// value
template <typename T> T LinkedList<T>::valueLast() const {
  validateInput();
  return tail->value;
}

// replace
template <typename T>
void LinkedList<T>::replaceByValue(T newValue, T byValue) {
  validateInput();
  Link<T> *temp = getByValue(byValue);
  temp->value = newValue;
}

// overall
template <typename T> T LinkedList<T>::max() {
  validateInput();
  T max = head->value;
  for (Link<T> *temp = head->next; temp != nullptr; temp = temp->next) {
    max = (max > temp->value) ? max : temp->value;
  }
  return max;
}

// overall
template <typename T> T LinkedList<T>::min() {
  validateInput();
  T min = head->value;
  for (Link<T> *temp = head->next; temp != nullptr; temp = temp->next) {
    min = (min < temp->value) ? min : temp->value;
  }
  return min;
}

// overall
template <typename T> T LinkedList<T>::sum() {
  validateInput();
  T sum = head->value;
  for (Link<T> *temp = head->next; temp != nullptr; temp = temp->next) {
    sum = sum + temp->value;
  }
  return sum;
}

// get
template <typename T> Link<T>* LinkedList<T>::getByValue(T value) const {
  validateInput();
  for (Link<T> *temp = head; temp != nullptr; temp = temp->next)
    if (temp->value == value)
      return temp;
  return nullptr;
}

// validation
template <typename T> void LinkedList<T>::validateInput() const {
  if (isEmpty())
    throw std::out_of_range("empty list");
}

// validation
template <typename T> void LinkedList<T>::validateInput(unsigned int index) const {
  validateInput();
  if (index >= length())
    throw std::out_of_range("index out of bounds");
}

/*
OVERLOADS
*/

// operator << overload
template <typename T> std::ostream& LinkedList<T>::operator<<(std::ostream& out, const LinkedList<T>& ll) {
  ll.validateInput();
  out << "NULL <-";
  for (Link<T> *temp = ll.head; temp != nullptr; temp = temp->next) {
    out << "-> " << temp->value << " <-";
  }
  return out << "-> NULL";
}

// operator [] overload
template <typename T> T& LinkedList<T>::operator[](unsigned int index) {
  validateInput(index);
  Link<T> *temp = head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp->value;
}

// operator[] overload const
template <typename T> const T& LinkedList<T>::operator[](unsigned int index) const {
  validateInput(index);
  Link<T> *temp = head;
  for (int i = 0; i < index; i++) {
    temp = temp->next;
  }
  return temp->value;
}

// operator= overload
template <typename T> LinkedList<T> &LinkedList<T>::operator=(const LinkedList<T> &o) {
  if (this == &o)
    return *this;
  this->clear();
  for (Link<T> *temp = o.head; temp != nullptr; temp = temp->next) {
    this->addLast(temp->value);
  }
  return *this;
}

// operator== overload
template <typename T> bool LinkedList<T>::operator==(const LinkedList<T> &o) const { // if (ll1 == ll2)
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
template <typename T> LinkedList<T> LinkedList<T>::operator+(const LinkedList<T> &o) const { // ll3 = ll1 + ll2
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
template <typename T> LinkedList<T> LinkedList<T>::operator+(const T &e) const { // ll3 = ll1 + 5;
  LinkedList<T> added;
  for (Link<T> *temp = this->head; temp != nullptr; temp = temp->next) {
    added.addLast(temp->value);
  }
  added.addLast(e);
  return added;
}
