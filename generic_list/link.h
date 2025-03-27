#pragma once

template <typename T>

class Link {
public:
    //fields
    T value;
    Link<T>* prev = nullptr;
    Link<T>* next = nullptr;

    //constructors
    Link(T value) : value(value) {}
    Link(Link<T>* prev, T value, Link<T>* next) : value(value), prev(prev), next(next) {}
    ~Link() = default;

    //methods
private:
};

