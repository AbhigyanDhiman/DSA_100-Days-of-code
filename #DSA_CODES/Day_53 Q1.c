#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

void findMinMax(struct Node* root, int *min, int *max, int hd) {
    if (root == NULL) return;

    if (hd < *min) *min = hd;
    if (hd > *max) *max = hd;

    findMinMax(root->left, min, max, hd - 1);
    findMinMax(root->right, min, max, hd + 1);
}

void printVertical(struct Node* root, int line, int hd) {
    if (root == NULL) return;

    if (hd == line)
        printf("%d ", root->data);

    printVertical(root->left, line, hd - 1);
    printVertical(root->right, line, hd + 1);
}

void verticalOrder(struct Node* root) {
    int min = 0, max = 0;

    findMinMax(root, &min, &max, 0);

    for (int i = min; i <= max; i++) {
        printVertical(root, i, 0);
        printf("\n");
    }
}

struct Node* buildTree(int arr[], int n, int i) {
    if (i >= n || arr[i] == -1)
        return NULL;

    struct Node* root = newNode(arr[i]);
    root->left = buildTree(arr, n, 2 * i + 1);
    root->right = buildTree(arr, n, 2 * i + 2);

    return root;
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n, 0);

    verticalOrder(root);

    return 0;
}
