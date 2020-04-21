/* 
* Implement memory handling here
*/

#include <stdlib.h>
#include <IXMalloc.h>

void *inMemAlloc(size_t size) {
    return malloc(size);
}

void inMemFree(void *ptr)
{
    free(ptr);
}

