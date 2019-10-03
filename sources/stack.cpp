#include "stack.hpp"

template <class T>
Stack<T>::Stack(int size) {

}

template <class T>
Stack<T>::~Stack() {}

template <class T>
Stack<T>::Stack(const Stack& stack) {}

template <class T>
T Stack<T>::Pop() {}

template <class T>
void Stack<T>::Push(T data) {}

template <class T>
int Stack<T>::GetSize() {
    return curr_size;
}

