/* 
* Implement memory handling here
*/

#include <stdlib.h>

void *inMemAlloc(size_t size) {
    return malloc(size);
}

void inMemFree(void *ptr)
{
    free(ptr);
}

