#include "canary.hpp"
#include "hash.hpp"
#include <stdlib.h>

template <class T>
class StackDefender {
public:
    StackDefender();
    StackDefender(void* buffer, size_t max_size);
    ~StackDefender();
    StackDefender(const StackDefender& defender);

    bool IsAlarm();

private:
    Canary canary;
};

template <class T>
StackDefender<T>::StackDefender() {
    canary = Canary();
}

template <class T>
StackDefender<T>::StackDefender(void* buffer, size_t init_size) {
    assert((T*) buffer - 1);

    canary = Canary((T*) buffer - 1, (T*) buffer + init_size);
}

template <class T>
StackDefender<T>::~StackDefender() {

}

template <class T>
StackDefender<T>::StackDefender(const StackDefender<T>& defender) {

}

template <class T>
bool StackDefender<T>::IsAlarm() {
    return canary.IsAlarm();
}
