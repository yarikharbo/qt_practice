#include "DynArray.h"
#include <iostream>

int main() {
    std::cout << "Integer DynArray" << std::endl;
    DynArray<int> intArr(3);
    intArr.initialize();
    intArr.viewDynArray();
    std::cout << std::endl;

    std::cout << "Double DynArray" << std::endl;
    DynArray<double> doubleArr(4);
    doubleArr.initialize();
    doubleArr.viewDynArray();
    std::cout << std::endl;

    std::cout << "Char DynArray" << std::endl;
    DynArray<char> charArr(5);
    charArr.initialize();
    charArr.viewDynArray();
    std::cout << std::endl;

    std::cout << "Copy constructor" << std::endl;
    DynArray<int> copied(intArr);
    copied.viewDynArray();
    std::cout << std::endl;

    std::cout << "Copy operator" << std::endl;
    DynArray<double> copied_op(1);
    copied_op = doubleArr;
    copied_op.viewDynArray();
    std::cout << std::endl;

    std::cout << "Move constructor" << std::endl;
    DynArray<double> mov(std::move(copied_op));
    mov.viewDynArray();
    copied_op.viewDynArray();
    std::cout << std::endl;
    
    std::cout << "Move operator" << std::endl;
    DynArray<double> mov_op(4);
    mov_op = std::move(doubleArr);
    mov_op.viewDynArray();
    doubleArr.viewDynArray();
    std::cout << std::endl;
    
    return 0;
}