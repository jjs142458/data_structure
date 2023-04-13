#include <stdio.h>
#include "BinaryTree.h"

void InorderTraverse(BTreeNode * bt) {
    if (bt == NULL)
        return;

    InorderTraverse(bt->left);
    printf("%c\n",bt->data);
    InorderTraverse(bt->right);
}

void PreorderTraverse(BTreeNode * bt) {
    if (bt == NULL)
        return;
    printf("%c\n",bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}


void PostorderTraverse(BTreeNode * bt) {
    if (bt == NULL)
        return;

    PostorderTraverse(bt->left);
    PostorderTraverse(bt->right);
    printf("%c\n", bt->data);
}



int main() {
    BTreeNode *bt1 = MakeBTreeNode();
    BTreeNode *bt2 = MakeBTreeNode();
    BTreeNode *bt3 = MakeBTreeNode();
    BTreeNode *bt4 = MakeBTreeNode();
    BTreeNode *bt5 = MakeBTreeNode();
    BTreeNode *bt6 = MakeBTreeNode();

    /*
    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);




    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
     */


    SetData(bt1, 'A');
    SetData(bt2, 'B');
    SetData(bt3, 'C');
    SetData(bt4, 'D');
    SetData(bt5, 'E');
    SetData(bt6, 'F');

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeRightSubTree(bt3, bt6);


    printf("PreorderTraverse\n");
    PreorderTraverse(bt1);
    printf("InorderTraverse\n");
    InorderTraverse(bt1);
    printf("PostorderTraverse\n");
    PostorderTraverse(bt1);

    return 0;
}
