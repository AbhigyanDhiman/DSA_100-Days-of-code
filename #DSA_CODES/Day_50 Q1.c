#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int val) {
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insert(struct node* root, int val) {
    if (root == NULL)
        return newNode(val);

    if (val < root->data)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);

    return root;
}

void search(struct node* root, int key) {
    if (root == NULL) {
        printf("Element not found");
        return;
    }

    if (root->data == key) {
        printf("Element found");
        return;
    }

    if (key < root->data)
        search(root->left, key);
    else
        search(root->right, key);
}

int main() {
    struct node* root = NULL;
    int n, val, key;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");
    for(int i = 0; i < n; i++) {
        scanf("%d", &val);
        root = insert(root, val);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    search(root, key);

    return 0;
}
