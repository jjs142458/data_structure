#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}


int levelCount(struct Node* root) {
    if (root == NULL)
        return 0;

    int leftLevel = levelCount(root->left);
    int rightLevel = levelCount(root->right);


    return (leftLevel > rightLevel) ? leftLevel + 1 : rightLevel + 1;
}

int main() {

    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->left->left = createNode(4);
    root->left->right = createNode(5);


    int level = levelCount(root);

    printf("레벨: %d\n", level);

    return 0;
}
