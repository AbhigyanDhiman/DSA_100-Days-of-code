#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* newNode(int data) {
    struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}

void zigzagTraversal(struct Node* root) {
    if (root == NULL) return;

    struct Node* queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    int leftToRight = 1;

    while (front < rear) {
        int size = rear - front;
        int arr[100];

        for (int i = 0; i < size; i++) {
            struct Node* temp = queue[front++];

            int index;
            if (leftToRight)
                index = i;
            else
                index = size - i - 1;

            arr[index] = temp->data;

            if (temp->left) queue[rear++] = temp->left;
            if (temp->right) queue[rear++] = temp->right;
        }

        for (int i = 0; i < size; i++)
            printf("%d ", arr[i]);

        leftToRight = !leftToRight;
    }
}

int main() {
    struct Node* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->right->left = newNode(6);
    root->right->right = newNode(7);

    zigzagTraversal(root);

    return 0;
}
