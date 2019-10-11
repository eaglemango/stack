/*!
    @file
    @brief File with hash functions
*/

#include <stdlib.h>
#include <iostream>

/*!
    @brief Simple hash function
    @param[in] memory Pointer to start of memory chunk
    @param[in] size Memory chunk size
    @param[out] hash Resulting hash
*/
int hash(char* memory, size_t size) {
    int result = 0;

    for (size_t i = 0; i < size; ++i) {
        result += static_cast<int>(*(memory + i));
    }

    return result;
}
