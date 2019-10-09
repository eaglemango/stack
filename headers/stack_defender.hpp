#include "canary.hpp"
#include "hash.hpp"
#include <stdlib.h>
#include <tuple>

template <class T>
class StackDefender {
public:
    StackDefender();
    StackDefender(void* buffer, size_t max_size);
    ~StackDefender();
    StackDefender(const StackDefender& defender);

    size_t GetCurrSize() const;
    size_t GetMaxSize() const;
    int GetContentHash() const;

    void Update(size_t new_curr_size);

    bool IsAlarm() const;

private:
    Canary canary;

    size_t curr_size;
    size_t max_size;
    int content_hash;

    void* defended_buffer;
};

template <class T>
bool operator!=(const StackDefender<T>& lhs, const StackDefender<T>& rhs) {
    return lhs.GetCurrSize() != rhs.GetCurrSize() ||
           lhs.GetMaxSize() != rhs.GetMaxSize() ||
           lhs.GetContentHash() != rhs.GetContentHash();
}

template <class T>
StackDefender<T>::StackDefender() {
    canary = Canary();

    curr_size = 0;
    max_size = 0;
    content_hash = 0;
}

template <class T>
StackDefender<T>::StackDefender(void* buffer, size_t init_size) {
    assert((T*) buffer - 1);

    canary = Canary((T*) buffer - 1, (T*) buffer + init_size);

    defended_buffer = buffer;

    curr_size = 0;
    max_size = init_size;
    content_hash = 0;
}

template <class T>
StackDefender<T>::~StackDefender() {

}

template <class T>
StackDefender<T>::StackDefender(const StackDefender<T>& defender) {

}

template <class T>
size_t StackDefender<T>::GetCurrSize() const {
    assert(!IsAlarm());

    return curr_size;
}

template <class T>
size_t StackDefender<T>::GetMaxSize() const {
    assert(!IsAlarm());

    return max_size;
}

template <class T>
int StackDefender<T>::GetContentHash() const {
    assert(!IsAlarm());

    return content_hash;
}

template <class T>
void StackDefender<T>::Update(size_t new_curr_size) {
    assert(!IsAlarm());

    curr_size = new_curr_size;

    content_hash = hash((char*) defended_buffer + 1, new_curr_size);
}

template <class T>
bool StackDefender<T>::IsAlarm() const {
    return canary.IsAlarm();
}
