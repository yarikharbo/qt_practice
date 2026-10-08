#include "DynArray.h"
#include <iostream>
#include <algorithm> 
#include <cmath> 
#include <vector>

template <typename T>
DynArray<T>::DynArray(size_t a_size) : arr(a_size) {}

template <typename T>
DynArray<T>::~DynArray() = default;

template <typename T>
DynArray<T>::DynArray(const DynArray& other) : arr(other.arr) {}

template <typename T>
DynArray<T>& DynArray<T>::operator=(const DynArray& other) {
    if (this != &other) {
        arr = other.arr;
    }
    return *this;
}

template<typename T>
DynArray<T>::DynArray(DynArray&& other) noexcept : arr(std::move(other.arr)) {}

template <typename T>
DynArray<T>& DynArray<T>::operator=(DynArray&& other) noexcept {
    if (this != &other) {
        arr = std::move(other.arr);
    }
    return *this;
}

template <typename T>
void DynArray<T>::initialize() {
    std::cout << "Enter " << arr.size() << " array elements:\n";
    for (size_t i = 0; i < arr.size(); ++i) {
        std::cin >> arr[i];
    }
}

template <typename T>
void DynArray<T>::viewDynArray() const {
    std::cout << "View DynArray:" << std::endl;
    T sum{};
    for (size_t i = 0; i < arr.size(); ++i) {
        sum += arr[i];
        std::cout << "|";
        for (size_t j = 0; j <= i; ++j) {
            std::cout << arr[j];
            if (j < i) std::cout << " + ";
        }
        std::cout << "| = " << std::abs(sum) << std::endl;
    }
}

template class DynArray<int>;
template class DynArray<double>;
template class DynArray<char>;