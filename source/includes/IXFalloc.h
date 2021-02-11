#ifndef __IX_FALLOC_H__
#define __IX_FALLOC_H__

int fInit();

void *fMap(int fd, int offset);

int fUnMap(void *addr, int len);

int fMWrite(void *addr, int len);

void *fAlloc(int size, int *offset);

#endif