#pragma once
#include "BASE.h"
#include <vector>

template<typename T>
class FIRST : public BASE<T> {
private:
    std::vector<T> data;

public:
    FIRST(const std::vector<T>& d) : data(d) {}

    BASE<T>* map(std::function<T(T)> f) override {
        std::vector<T> result;
        for (const auto& item : data) {
            result.push_back(f(item));
        }
        return new FIRST<T>(result);
    }

    BASE<T>* reduce(std::function<T(T, T)> f) override {
        if (data.empty()) return nullptr;
        T result = data[0];
        for (size_t i = 1; i < data.size(); ++i) {
            result = f(result, data[i]);
        }
        return new FIRST<T>({ result });
    }

    BASE<T>* filter(typename BASE<T>::Predicate p) override {
        std::vector<T> result;
        for (const auto& item : data) {
            if (p(item)) result.push_back(item);
        }
        return new FIRST<T>(result);
    }
};
