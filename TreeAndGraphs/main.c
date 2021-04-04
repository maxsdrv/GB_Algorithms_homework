#include <stdio.h>

#include "geek.h"

FILE *file;

BinTreeNode *balancedTree(int count) {
    BinTreeNode *newNode;
    int x = 0;
    int nL = 0;
    int nR = 0;

    if (count == 0) {
        return NULL;
    }
    else {
        fscanf(file, "%d", &x);
        nL= count / 2;
        nR = count - nL - 1;
        newNode = (BinTreeNode*) malloc(sizeof(BinTreeInsert));
        newNode->key = x;
        newNode->left = balancedTree(nL);
        newNode->right = balancedTree(nR);
    }
    return newNode;
}

bool isBalanced(BinTreeNode *root) {
    if (root == NULL) {
        return false;
    }
    BinTreeNode *current = root;
    int count_left = 0;
    int count_right = 0;
    while (current->left != NULL) {
        current->left = current->left->left;
        count_left++;
    }
    while (current->right != NULL) {
        current->right = current->right->right;
        count_right++;
    }
    int difference = count_left - count_right;
    if (abs(difference) > 1) {
        return false;
    }
    else {
        return true;
    }

}

void CreatingTrees() {

}


int main() {
BinTreeNode *tree = NULL;
file = fopen("balance.txt", "r");
if (file == NULL) {
    printf("Cannot open file\n");
    return 1;
}
const int count = 15;
tree = balancedTree(count);
fclose(file);
PrintBinTree(tree);
freeBinTree(tree);
printf("\n");

/*Task  1.) Написать функцию проверяющую является ли переданное в неё бинарное дерево
 * сбалансированным bool isBalanced(BinTreeIntNode *root)
 *Входные параметры: указатель на вершину дерева
* Выходные параметры: Bool. True, если сбалансированно; False, если несбалансированно */
printf("Exercise 1.\n");
int result = 0;
result = isBalanced(tree);
if (result == 1) {
    printf("true\n");
}
else printf("false\n");

BinTreeNode *no_balance = BinTreeInsert(no_balance, 10);
BinTreeInsert(no_balance, 10);
BinTreeInsert(no_balance, 20);
BinTreeInsert(no_balance, 30);
BinTreeInsert(no_balance, 40);
BinTreeInsert(no_balance, 50);
BinTreeInsert(no_balance, 60);
PrintBinTree(no_balance);
printf("\n");
result = isBalanced(no_balance);
if (result == 1) {
    printf("true\n");
}
else {
    printf("false\n");
}

/*Task2  2.) Написать программу, которая:
2.a) Создаст [50] бинарных деревьев по [10000] узлов и заполнит узлы случайными целочисленными
 значениями; */
printf("Exercise 2.a)\n");
CreatingTrees();



    return 0;
}
