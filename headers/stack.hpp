#include <cstdlib>
#include "stack_defender.hpp"

template <class T>
class Stack {
public:
    Stack(size_t init_size);
    ~Stack();
    Stack(const Stack& stack);

    T Top() const;

    void Pop();
    void Push(T data);

    size_t GetSize() const;
    bool IsEmpty() const;

    bool IsAlarm() const;

private:
    size_t curr_size;
    size_t max_size;

    T* buffer;

    StackDefender<T> defender;
};

template <class T>
Stack<T>::Stack(size_t init_size) {
    buffer = ((T*) calloc(init_size, sizeof(T) + 2)) + 1;
    assert(buffer);

    defender = StackDefender<T>(buffer - 1, init_size);

    curr_size = 0;
    max_size = init_size;
}

template <class T>
Stack<T>::~Stack() {
    defender.~StackDefender();

    free(buffer - 1);
    buffer = nullptr;
}

template <class T>
Stack<T>::Stack(const Stack& stack) {
    buffer = (T*) calloc(stack.max_size, sizeof(T));
    assert(buffer);

    curr_size = 0;
    max_size = stack.max_size;

    for (size_t i = 0; i < max_size; ++i) {
        buffer[i] = stack.buffer[i];
	
	    ++curr_size;
    }

    assert(curr_size == stack.curr_size);
}

template <class T>
T Stack<T>::Top() const {
    assert(!IsAlarm());
    assert(curr_size);

    return buffer[curr_size - 1];
}

template <class T>
void Stack<T>::Pop() {
    assert(!IsAlarm());

    assert(curr_size);
    ~buffer[curr_size - 1];

    --curr_size;

    defender.Update(curr_size);
}

template <class T>
void Stack<T>::Push(T data) {
    assert(!IsAlarm());

    assert(curr_size != max_size);
    buffer[curr_size] = data;

    ++curr_size;
    
    defender.Update(curr_size);
}

template <class T>
size_t Stack<T>::GetSize() const {
    assert(!IsAlarm());

    return curr_size;
}

template <class T>
bool Stack<T>::IsEmpty() const {
    assert(!IsAlarm());

    return !curr_size;
}

template <class T>
bool Stack<T>::IsAlarm() const {
    StackDefender<T> temp_defender = StackDefender<T>(buffer, max_size);
    temp_defender.Update(curr_size);

    return defender != temp_defender;
}
