#ifndef __IX_MALLOC_H__
#define __IX_MALLOC_H__

/*
* allocate memory in using malloc library call
*/
void *inMemAlloc(size_t size);

/*
* free pointer which holds memory allocated using malloc
*/
void inMemFree(void *ptr);


#endif
