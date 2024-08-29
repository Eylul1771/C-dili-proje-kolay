//
//  main.c
//  BST
//
//  Created by Eylül Demirdağ on 29.08.2024.
//
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node* insert(struct Node* root, int data) {
    if (root == NULL) {
        return newNode(data);
    }
    if (data < root->data) {
        root->left = insert(root->left, data);
    } else if (data > root->data) {
        root->right = insert(root->right, data);
    }
    return root;
}

struct Node* search(struct Node* root, int key) {
    if (root == NULL || root->data == key) {
        return root;
    }
    if (key < root->data) {
        return search(root->left, key);
    }
    return search(root->right, key);
}

void inorderTraversal(struct Node* root) {
    if (root != NULL) {
        inorderTraversal(root->left);
        printf("%d -> ", root->data);
        inorderTraversal(root->right);
    }
}

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}

struct Node* deleteNode(struct Node* root, int key) {
    if (root == NULL) return root;
    if (key < root->data)
        root->left = deleteNode(root->left, key);
    else if (key > root->data)
        root->right = deleteNode(root->right, key);
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }
        struct Node* temp = minValueNode(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int findMin(struct Node* root) {
    struct Node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current->data;
}

int findMax(struct Node* root) {
    struct Node* current = root;
    while (current && current->right != NULL)
        current = current->right;
    return current->data;
}

int maxDepth(struct Node* node) {
    if (node == NULL)
        return 0;
    int leftDepth = maxDepth(node->left);
    int rightDepth = maxDepth(node->right);
    if (leftDepth > rightDepth)
        return(leftDepth + 1);
    else return(rightDepth + 1);
}

int isBalanced(struct Node* root) {
    if (root == NULL)
        return 1;
    int leftHeight = maxDepth(root->left);
    int rightHeight = maxDepth(root->right);
    if (abs(leftHeight - rightHeight) <= 1 && isBalanced(root->left) && isBalanced(root->right))
        return 1;
    return 0;
}

int main() {
    struct Node* root = NULL;
    root = insert(root, 50);
    insert(root, 30);
    insert(root, 20);
    insert(root, 40);
    insert(root, 70);
    insert(root, 60);
    insert(root, 80);

    printf("Inorder traversal: \n");
    inorderTraversal(root);
    printf("\n");

    printf("Delete 20\n");
    root = deleteNode(root, 20);
    printf("Inorder traversal: \n");
    inorderTraversal(root);
    printf("\n");

    printf("Min value: %d\n", findMin(root));
    printf("Max value: %d\n", findMax(root));
    printf("Tree depth: %d\n", maxDepth(root));
    printf("Is tree balanced? %s\n", isBalanced(root) ? "Yes" : "No");

    return 0;
}
