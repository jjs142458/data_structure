//
// Created by 정재성 on 2023/03/30.
//

#ifndef BINARYTREE2_BINARYTREE2_H
#define BINARYTREE2_BINARYTREE2_H

typedef int BTData;

typedef struct _bTreeNode {
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;
}BTreeNode;

BTreeNode  * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode *bt,BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main,BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

typedef void VisitFuncPtr(BTData data);

void PreorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void InorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void PostorderTraverse(BTreeNode *bt, VisitFuncPtr action);
void Delete(BTreeNode * bt, VisitFuncPtr action);


#endif //BINARYTREE2_BINARYTREE2_H
