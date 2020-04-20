#ifndef __IX_LIST_H__
#define __IX_LIST_H__

typedef struct _IXListHead {
    struct _IXListHead *next;
    struct _IXListHead *prev;
} IXListHead;

typedef _IXListNode {
    IXListHead *head;
    void *contatiner;
} IXListNode;

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
