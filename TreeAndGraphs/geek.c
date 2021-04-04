#include "geek.h"


//Functions for OneLinkedNode
void InitOneLinkList(OneLinkList *stack) {
    stack->head = NULL;
    stack->size = 0;
}

bool PushOneLinkStack(OneLinkList *stack, T value) {
    OneLinkNode *temp = (OneLinkNode*) malloc(sizeof(OneLinkNode));
    if (temp == NULL) {
        printf("Stack overflow\n");
        return false;
    }
    temp->dat = value;
    temp->next = stack->head;

    stack->head = temp;
    stack->size++;
    return true;
}

T PopOneLinkStack(OneLinkList *stack) {
    if (StackIsEmpty(stack)) {
        printf("Stack is empty \n");
        return -1;
    }
    OneLinkNode *temp = stack->head;
    T data = stack->head->dat;
    stack->head = stack->head->next;
    free(temp);
    stack->size--;
    return data;
}

void PrintOneLinkNode(OneLinkNode *n) {
    if (n == NULL) {
        printf("[]");
        return;
    }
    printf("[%d]", n->dat);
}

void PrintOneIntList(OneLinkList *stack) {
    OneLinkNode *current = stack->head;
    if (current == NULL) {
        PrintOneLinkNode(current);
    }
    else {
        do {
            PrintOneLinkNode(current);
            current = current->next;
        } while (current != NULL);
    }
    printf(" Size: %d \n", stack->size);
}

bool StackIsEmpty(OneLinkList *stack) {
    if (stack->size == 0) {
        return true;
    }
    return false;
}

void FreeOneLinkList(OneLinkList *stack) {
    while (stack->size != 0) {
        PopOneLinkStack(stack);
    }
    free(stack);
}

//Functions for BinaryTree
BinTreeNode* BinTreeInsert(BinTreeNode *t, int data) {
   BinTreeNode *newNode;
   newNode = (BinTreeNode*) malloc(sizeof(BinTreeNode));
   newNode->key = data;
   newNode->left = NULL;
   newNode->right = NULL;
   BinTreeNode *current = t;
   BinTreeNode *parent = t;
   if (t == NULL) {
       t = newNode;
   }
   else {
        while (true) {
            parent = current;
            if (current->key > data) {
                current = current->left;
                if (current == NULL) {
                    parent->left = newNode;
                    return t;
                }
            }
            else {
                current = current->right;
                if (current == NULL) {
                    parent->right = newNode;
                    return t;
                }
            }
        }
   }

   return t;
}

void PrintBinTree(BinTreeNode *root) {
    if (root) {
        printf("%d", root->key);
        if (root->left || root->right) {
            printf("(");
            if (root->left) {
                PrintBinTree(root->left);
            } else {
                printf("NULL");
            }
            printf(",");
            if (root->right) {
                PrintBinTree(root->right);
            }
            else {
                printf("NULL");
            }
            printf(")");
        }
    }
}

BinTreeNode* getSuccessor(BinTreeNode *node) {
    BinTreeNode *current = node->right;
    BinTreeNode *parent = node;
    BinTreeNode *s = node;

    while (current != NULL) {
        parent = s;
        s = current;
        current = current->left;
    }
    if (s != node->right) {
        parent->left = s->right;
        s->right = node->right;
    }
    return s;
}

bool DeleteBinTreeNode(BinTreeNode *root, int key) {
    BinTreeNode *current = root;
    BinTreeNode *parent = root;
    bool isLeftChild = true;

    while (current->key != key) {
        parent = current;
        if (key < current->key) {
            current = current->left;
            isLeftChild = true;
        }
        else {
            current = current->right;
            isLeftChild = false;
        }
        if (current == NULL) {
            return false;
        }

    }
    if (current->left == NULL && current->right == NULL) {
        if (current == root) {
            root = NULL;
        }
        else if (isLeftChild) {
            parent->left = NULL;
        }
        else {
            parent->right = NULL;
        }
    }
    else if (current->right == NULL) {
        if (isLeftChild) {
            parent->left = current->left;
        }
        else {
            parent->right = current->left;
        }
    }
    else if (current->left == NULL) {
        if (isLeftChild) {
            parent->left = current->right;
        }
        else {
            parent->right = current->right;
        }
    }
    else {
        BinTreeNode *successor = getSuccessor(current);
        if (current == root) {
            root = successor;
        }
        else if (isLeftChild) {
            parent->left = successor;
        }
        else {
            parent->right = successor;
        }
        successor->left = current->left;
    }
    return true;
}

void freeBinTree(BinTreeNode *t) {
    if (t != NULL) {
        freeBinTree(t->right);
        freeBinTree(t->left);
        free(t);
    }
}


























