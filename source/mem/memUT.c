/*
* Lets write unit tests for memory apis here
*/


#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
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
    char *data = "This should be node";
    int offset = 0;
    if(fInit() < 0) {
        printf("Init fail\n");
    }


    if((addr = fAlloc(getpagesize(), &offset)) == NULL) {
        printf("fAlloc failed\n");
        return -1;
    }

    memcpy(addr, data, strlen(data));

    //fUnMap(addr, getpagesize());
    return 0;
}

int main()
{
    test_IXFalloc();
    //test_IXMalloc();
    return 0;
}
