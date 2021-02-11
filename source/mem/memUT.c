/*
* Lets write unit tests for memory apis here
*/


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <IXMalloc.h>
#include <IXFalloc.h>

int test_IXMalloc()
{
    size_t size = 1024;
    void *ptr, *freePtr;
    int i;
    if(!(ptr = inMemAlloc(size)))
        return -1;
    freePtr = ptr;

    /* write some char data */
    for(i = 0; i < size; i++) {
        *(char *)ptr++ = 'a' + (i % 26);
        printf("%c ", *(char *)(ptr - 1));
    }

    inMemFree(freePtr);
    return 0;
}

int test_IXFalloc() {
    char *addr = NULL;
    int offset = 0;
    if(fInit() < 0) {
        printf("Init fail\n");
    }

    if((addr = fAlloc(20, &offset)) == NULL) {
        printf("fAlloc failed\n");
    }


    fUnMap(addr, 20);
    return 0;
}

int main()
{
    test_IXFalloc();
    //test_IXMalloc();
    return 0;
}
