int** zigzagLevelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes) {
    if (!root) {
        *returnSize = 0;
        *returnColumnSizes = NULL;
        return NULL;
    }

    struct TreeNode** queue = malloc(2000 * sizeof(struct TreeNode*));
    int front = 0, rear = 0;

    int** result = malloc(2000 * sizeof(int*));
    *returnColumnSizes = malloc(2000 * sizeof(int));

    queue[rear++] = root;
    int level = 0;

    while (front < rear) {
        int size = rear - front;
        result[level] = malloc(size * sizeof(int));
        (*returnColumnSizes)[level] = size;

        for (int i = 0; i < size; i++) {
            struct TreeNode* node = queue[front++];

            if (level % 2 == 0)
                result[level][i] = node->val;
            else
                result[level][size - i - 1] = node->val;

            if (node->left)
                queue[rear++] = node->left;
            if (node->right)
                queue[rear++] = node->right;
        }

        level++;
    }

    *returnSize = level;
    return result;
}
