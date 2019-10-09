#include <stdlib.h>
#include <iostream>
int hash(char* memory, size_t size) {
    int result = 0;

    for (size_t i = 0; i < size; ++i) {
        result += static_cast<int>(*(memory + i));
    }

    return result;
}
