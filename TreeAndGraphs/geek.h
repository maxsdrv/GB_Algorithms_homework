#ifndef TASK7_GEEK_H
#define TASK7_GEEK_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define T   int

typedef struct OneLinkNode {
    T dat;
    struct OneLinkNode *next;
} OneLinkNode;

typedef struct {
    OneLinkNode *head;
    int size;
} OneLinkList;

typedef struct Node {
    int key;
    struct Node *left;
    struct Node *right;
} BinTreeNode;

//Functions for LinkedNode
void InitOneLinkList(OneLinkList *stack);
bool PushOneLinkStack(OneLinkList *stack, T value);
T PopOneLinkStack(OneLinkList *stack);
void PrintOneLinkNode(OneLinkNode *n);
void PrintOneIntList(OneLinkList *stack);
bool StackIsEmpty(OneLinkList *stack);
void FreeOneLinkList(OneLinkList *stack);

//Functions for BinaryTree
BinTreeNode* BinTreeInsert(BinTreeNode *t, int data);
void PrintBinTree(BinTreeNode *root);
bool DeleteBinTreeNode(BinTreeNode *root, int key);
void freeBinTree(BinTreeNode *t);












#endif //TASK7_GEEK_H














