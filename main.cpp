#include <iostream>
#include "stack.hpp"

int main() {
    Stack<int> stack(10);
    stack.Push(5);
    std::cout << stack.Pop();

    return 0;
}

