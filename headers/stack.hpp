#pragma once

template <class T>
class Stack {
public:
    Stack(int size);
    ~Stack();
    Stack(const Stack& stack);

    T Pop();
    void Push(T data);

    int GetSize() const;

private:
    int curr_size
    int max_size;
    T buffer[];
}

