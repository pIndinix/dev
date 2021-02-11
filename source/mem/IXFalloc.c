#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>
#include <unistd.h>

static char *_fileName = "list.txt";
static int _fd;
static int _offset = 0;

int fInit() {
    if((_fd = open(_fileName, O_RDWR|O_CREAT, S_IRWXU)) < 0) {
        perror("open");
        return -1;
    }
    return 0;
}

void *fMap(int fd, int offset, int size) {
    void *addr = NULL;

    if((addr = mmap(NULL, size, PROT_WRITE | PROT_READ, MAP_SHARED, fd, offset)) != MAP_FAILED) {
        return addr;
    } else {
        perror("mmap: ");
    }
    return NULL;
}

int fUnMap(void *addr, int len) {
    return munmap(addr, len);
}

int fMsync(void *addr, int len) {
    if(msync(addr, len, MS_SYNC) < 0) {
        perror("msync");
        return -1;
    }
    return 0;
}

void *fAlloc(int size, int *offset) {
    void *addr = NULL;

    if((_offset = lseek(_fd, size - 1, SEEK_END)) < 0) {
        return NULL;
    }

    if(write(_fd, "", 1) != 1) {
        perror("write");
        return NULL;
    }

    *offset = _offset - (size - 1);

    printf("offset = %d\n", *offset);
    printf("size = %d\n", size);
    if((addr = fMap(_fd, *offset, size)) == NULL) {
        return NULL;
    }

    return addr;
}