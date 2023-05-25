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

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        root = createNode(data);
    } else if (data <= root->data) {
        root->left = insertNode(root->left, data);
    } else {
        root->right = insertNode(root->right, data);
    }
    return root;
}

struct Node* searchNode(struct Node* root, int data) {
    if (root == NULL || root->data == data) {
        return root;
    } else if (data < root->data) {
        return searchNode(root->left, data);
    } else {
        return searchNode(root->right, data);
    }
}

struct Node* findMinNode(struct Node* root) {
    struct Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) {
        return root;
    } else if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* minValueNode = findMinNode(root->right);
        root->data = minValueNode->data;
        root->right = deleteNode(root->right, minValueNode->data);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d ", root->data);
        inorderTraversal(root->right);
    }
}

int main() {
    struct Node* root = NULL;

    root = insertNode(root, 12);
    root = insertNode(root, 5);
    root = insertNode(root, 17);
    root = insertNode(root, 30);
    root = insertNode(root, 55);
    root = insertNode(root, 48);

    printf("중위 순회: ");
    inorderTraversal(root);
    printf("\n");

    int searchData = 5;
    struct Node* searchResult = searchNode(root, searchData);
    if (searchResult != NULL) {
        printf("%d 값을 찾았습니다.\n", searchData);
    } else {
        printf("%d 값을 찾지 못했습니다.\n", searchData);
    }

    int insertData = 22;
    root = insertNode(root, insertData);
    printf("%d 값을 삽입했습니다 : ", insertData);
    inorderTraversal(root);
    printf("\n");

    int deleteData = 55;
    root = deleteNode(root, deleteData);
    printf("%d 값을 삭제했습니다 : ", deleteData);
    inorderTraversal(root);
    printf("\n");

    return 0;
}
