#pragma once
#include <functional>

template<typename T>
class BASE {
public:
    using Predicate = std::function<bool(T)>;

    virtual ~BASE() = default;

    // These cannot be templated virtual functions directly
    virtual BASE<T>* map(std::function<T(T)> f) = 0;
    virtual BASE<T>* reduce(std::function<T(T, T)> f) = 0;
    virtual BASE<T>* filter(Predicate p) = 0;
};
