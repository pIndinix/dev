#ifndef __IX_LIST_H__
#define __IX_LIST_H__

#include <inttypes.h>

/*
typedef struct _IXListMHead {
    struct _IXListHead *next;
} IXListHead;

typedef struct _IXListMNode {
    IXListHead *head;
    void *container;
} IXListNode;
*/

typedef struct _IXListHead { 
    int next; /*offsets are the links in file backed linked list*/
};

typedef struct _IXListNode {
    /* data */
    _IXListHead head;
    uint8_t *data[10];
};

/*
* func: initNode(IXListNode *node)
* Assign null to links and other pointers.
* param: node is a pointer of IXListNode.
*/
void initNode(IXListNode *node);

/*
*
*/
int listAdd(IXListHead **head, IXListNode *node);

/*
*
*/
int listDel(IXListHead **head, IXListNode *node);

/*
*
*/
void printList(IXListHead *head);

#endif
