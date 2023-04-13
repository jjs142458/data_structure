#include "LCRSTree.h"

LCRSNode* LCRS_CreateNode(ElementType NewData) {
    LCRSNode * NewNode = (LCRSNode*)malloc(sizeof(LCRSNode));
    NewNode->LeftChild = nullptr;
    NewNode->RightSibling = nullptr;
    NewNode->Data = NewData;

    return NewNode;
}


void LCRS_DestroyNode(LCRSNode* Node) {
    free(Node);
}

void LCRS_DestroyTree(LCRSNode* Root) {
    if (Root->RightSibling != nullptr) {
        LCRS_DestroyTree(Root->RightSibling);
    }
    if (Root->LeftChild != nullptr) {
        LCRS_DestroyTree(Root->LeftChild);
    }

    Root->LeftChild = nullptr;
    Root->RightSibling = nullptr;

    LCRS_DestroyNode(Root);

}

void LCRS_AddChildNode(LCRSNode* Parent, LCRSNode* Child) {
    if (Parent->LeftChild == nullptr) {
        Parent->LeftChild = Child;
    }
    else {
        LCRSNode* TempNode = Parent->LeftChild;
        while (TempNode->RightSibling != nullptr) {
            TempNode = TempNode->RightSibling;
        }
        TempNode->RightSibling = Child;
    }
}


void LCRS_PrintTree(LCRSNode* Node, int Depth) {
    int i = 0;
    for (i = 0; i < Depth - 1; i++) {
        printf("   ");
    }

    if (Depth > 0) {
        printf("+--");
    }

    printf("%c\n", Node->Data);

    if (Node->LeftChild != nullptr) {
        LCRS_PrintTree(Node->LeftChild, Depth + 1);
    }

    if (Node->RightSibling != nullptr) {
        LCRS_PrintTree(Node->RightSibling, Depth);
    }
}

int main(void) {
    LCRSNode* Root = LCRS_CreateNode('A');

    LCRSNode* B = LCRS_CreateNode('B');
    LCRSNode* C = LCRS_CreateNode('C');
    LCRSNode* D = LCRS_CreateNode('D');
    LCRSNode* E = LCRS_CreateNode('E');
    LCRSNode* F = LCRS_CreateNode('F');
    LCRSNode* G = LCRS_CreateNode('G');
    LCRSNode* H = LCRS_CreateNode('H');
    LCRSNode* I = LCRS_CreateNode('I');
    LCRSNode* J = LCRS_CreateNode('J');
    LCRSNode* K = LCRS_CreateNode('K');


    LCRS_AddChildNode(Root, B);
    LCRS_AddChildNode(B, C);
    LCRS_AddChildNode(B, D);
    LCRS_AddChildNode(D, E);
    LCRS_AddChildNode(D, F);

    LCRS_AddChildNode(Root, G);
    LCRS_AddChildNode(G, H);

    LCRS_AddChildNode(Root, I);
    LCRS_AddChildNode(I, J);
    LCRS_AddChildNode(J, K);

    LCRS_PrintTree(Root, 0);

    LCRS_DestroyTree(Root);

    return 0;
}