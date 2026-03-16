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

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

void preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node* root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main() {
    int n, i;
    scanf("%d", &n);

    int arr[n];
    for(i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* nodes[n];

    for(i = 0; i < n; i++)
        nodes[i] = createNode(arr[i]);

    for(i = 0; i < n; i++) {
        int left = 2*i + 1;
        int right = 2*i + 2;

        if(left < n)
            nodes[i]->left = nodes[left];
        if(right < n)
            nodes[i]->right = nodes[right];
    }

    struct Node* root = nodes[0];

    inorder(root);
    printf("\n");

    preorder(root);
    printf("\n");

    postorder(root);
    printf("\n");

    return 0;
}
