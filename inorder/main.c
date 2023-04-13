#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;

}TreeNode;
/*
TreeNode n1 = { 1,NULL,NULL };
TreeNode n2 = { 4,&n1,NULL };
TreeNode n3 = { 16,NULL,NULL };
TreeNode n4 = { 25,NULL,NULL };
TreeNode n5 = { 20,&n3,&n4 };
TreeNode n6 = { 15,&n2,&n5 };
TreeNode* root = &n6;
 */


TreeNode n1 = { 'K',NULL,NULL };
TreeNode n2 = { 'L',NULL,NULL };
TreeNode n3 = { 'I',NULL,NULL };
TreeNode n4 = { 'H',NULL,NULL };
TreeNode n5 = { 'G',&n2,NULL };
TreeNode n6 = { 'F',&n3,&n1 };
TreeNode n7 = { 'E',NULL,NULL };
TreeNode n8 = { 'D',&n4,NULL };
TreeNode n9 = { 'C',&n6,&n5 };
TreeNode n10 = { 'B',&n8,&n7 };
TreeNode n11 = { 'A',&n10,&n9 };
TreeNode* root = &n11;

void inorder(TreeNode* root) {
    if (root) {
        inorder(root->left);
        printf("%c\n", root->data);
        inorder(root->right);
    }
}


void preorder(TreeNode* root) {
    if (root) {
        printf("%c\n", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(TreeNode* root) {
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%c\n", root->data);
    }
}

int main() {
    printf("inorder\n");
    inorder(root);
    printf("preorder\n");
    preorder(root);
    printf("postorder\n");
    postorder(root);

    return 0;
}