#include <cstdlib>

template <class T>
class Stack {
public:
    Stack(int size);
    ~Stack();
    Stack(const Stack& stack);

    T Pop();
    void Push(T data);

    int GetSize();

private:
    int curr_size;
    int max_size;
    T* buffer;
};


template <class T>
Stack<T>::Stack(int size) {
    buffer = (T*) calloc(size, sizeof(T));

    curr_size = 0;
    max_size = size;
}

template <class T>
Stack<T>::~Stack() {
    free(buffer);
}

template <class T>
Stack<T>::Stack(const Stack& stack) {
    buffer = (T*) calloc(stack.max_size, sizeof(T));

    curr_size = 0;
    max_size = stack.max_size;

    for (int i = 0; i < max_size; ++i) {
        buffer[i] = stack.buffer[i];
	
	++curr_size;
    }
}

template <class T>
T Stack<T>::Pop() {
    T temp = buffer[curr_size - 1];
    ~buffer[curr_size - 1];
    --curr_size;

    return temp;
}

template <class T>
void Stack<T>::Push(T data) {
    buffer[curr_size] = data;

    ++curr_size;
}

template <class T>
int Stack<T>::GetSize() {
    return curr_size;
}

