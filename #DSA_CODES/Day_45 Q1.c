#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* queue[1000];
int front = 0, rear = 0;

void enqueue(struct Node* node) {
    queue[rear++] = node;
}

struct Node* dequeue() {
    return queue[front++];
}

int height(struct Node* root) {
    if (root == NULL)
        return 0;

    int left = height(root->left);
    int right = height(root->right);

    return (left > right ? left : right) + 1;
}

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) {
        printf("0");
        return 0;
    }

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = NULL;

    if (arr[0] != -1)
        root = newNode(arr[0]);
    else {
        printf("0");
        return 0;
    }

    enqueue(root);

    int i = 1;

    while (i < n) {
        struct Node* current = dequeue();

        if (i < n && arr[i] != -1) {
            current->left = newNode(arr[i]);
            enqueue(current->left);
        }
        i++;

        if (i < n && arr[i] != -1) {
            current->right = newNode(arr[i]);
            enqueue(current->right);
        }
        i++;
    }

    printf("%d", height(root));

    return 0;
}
