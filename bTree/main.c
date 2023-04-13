#include <stdio.h>
#include "BinaryTree.h"

int main(void) {
    BTreeNode* bt1 = MakeBTreeNode();
    BTreeNode* bt2 = MakeBTreeNode();
    BTreeNode* bt3 = MakeBTreeNode();
    BTreeNode* bt4 = MakeBTreeNode();

    SetData(bt1, 1);
    SetData(bt2, 2);
    SetData(bt3, 3);
    SetData(bt4, 4);

    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt3, bt4);
    MakeLeftSubTree(bt2, bt4);

    printf("%d \n", GetData(GetLeftSubTree(bt1)));

    printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(bt1))));



    BTreeNode* b1 = MakeBTreeNode();
    BTreeNode* b2 = MakeBTreeNode();
    BTreeNode* b3 = MakeBTreeNode();
    BTreeNode* b4 = MakeBTreeNode();
    BTreeNode* b5 = MakeBTreeNode();
    BTreeNode* b6 = MakeBTreeNode();
    BTreeNode* b7 = MakeBTreeNode();

    SetData(b1, 1);
    SetData(b2, 2);
    SetData(b3, 3);
    SetData(b4, 4);
    SetData(b5, 5);
    SetData(b6, 6);
    SetData(b7, 7);

    MakeLeftSubTree(b1, b2);
    MakeRightSubTree(b1, b3);
    MakeLeftSubTree(b2, b4);
    MakeRightSubTree(b2, b5);
    MakeLeftSubTree(b4, b6);
    MakeRightSubTree(b4, b7);



    printf("%d \n", GetData(GetLeftSubTree(GetLeftSubTree(b1))));
    printf("%d\n", GetData(GetRightSubTree(GetLeftSubTree(GetLeftSubTree(b1)))));

    return 0;

}