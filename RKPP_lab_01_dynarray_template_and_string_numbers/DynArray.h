#ifndef DYNARRAY_H
#define DYNARRAY_H

#include <cstddef> 
#include <vector>

template <typename T>
class DynArray {
private:
    std::vector<T> arr;
public:
    DynArray(size_t a_size);
    ~DynArray();
    DynArray(const DynArray& other);
    DynArray& operator=(const DynArray& other);
    DynArray(DynArray&& other) noexcept;
    DynArray& operator=(DynArray&& other) noexcept;
    void initialize();
    void viewDynArray() const;
};

#endif