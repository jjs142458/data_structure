//
// Created by 정재성 on 2023/04/13.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include "BinaryTree2.h"

typedef BTData  BSTData;

void BSTMakeAndInit(BTreeNode ** pRoot);

BSTData BSTGetNodeData(BTreeNode * bst);

void BSTInsert(BTreeNode ** pRoot, BSTData data);

BTreeNode * BSTSearch(BTreeNode * bst, BSTData target);

#endif//BINARYSEARCHTREE_BINARYSEARCHTREE_H
