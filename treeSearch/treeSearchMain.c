//
// Created by 정재성 on 2023/04/20.
//
#include <stdio.h>
#include <stdlib.h>


typedef int element;
typedef struct TreeNode {
    element key;
    struct TreeNode * left, * right;
} TreeNode;

TreeNode *search(TreeNode *node, int key) {

    if (node == NULL) return NULL;
    if(key == node->key) return node;
    else if (key < node->key)
        return search(node->left,key);
    else
        return search(node->right, key);
}

TreeNode * newNode(int item) {

    TreeNode * temp = (TreeNode*) malloc(sizeof(TreeNode));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

TreeNode * insertNode(TreeNode* node, int key) {

    if (node == NULL) return newNode(key);

    if (key < node->key)
        node->left = insertNode(node->left,key);
    else if(key > node->key)
        node->right = insertNode(node->right,key);

    return node;

}

TreeNode * minValueNode(TreeNode * node) {

    TreeNode * current = node;

    while (current->left !=  NULL)
        current = current->left;

    return current;
}

TreeNode * deleteNode(TreeNode * root, int key) {

    if (root == NULL) return root;

    if (key < root->key)
        root->left = deleteNode(root->left, key);
    else if (key > root->key)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            TreeNode * temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            TreeNode *temp = root->left;
            free(root);
            return temp;
        }

        TreeNode *temp = minValueNode(root->right);

        root -> key = temp->key;

        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}

void inorder(TreeNode * root) {
    if (root) {
        inorder(root->left);
        printf("[%d]", root->key);
        inorder(root->right);
    }
}

int main() {

    TreeNode *root = NULL;

    root = insertNode(root, 30);
    insertNode(root, 20);
    insertNode(root, 10);
    insertNode(root, 40);
    insertNode(root, 50);
    insertNode(root, 60);

    printf("Inorder traversal: ");
    inorder(root);

    printf("\n");

    TreeNode * result = search(root, 30);
    if (result != NULL) {
        printf("이진 탐색 트리에서 %d를 발견함!\n",result->key);
    } else {
        printf("이진 탐색 트리에서 30를 발견못함.\n");
    }

    result = search(root, 70);
    if (result != NULL) {
        printf("이진 탐색 트리에서 %d를 발견함!\n",result->key);
    } else {
        printf("이진 탐색 트리에서 70를 발견못함.\n");
    }


    return 0;
}
