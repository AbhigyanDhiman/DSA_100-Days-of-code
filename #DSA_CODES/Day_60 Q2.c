int cameras;

int dfs(struct TreeNode* node) {
    if (node == NULL) {
        return 2;
    }

    int left = dfs(node->left);
    int right = dfs(node->right);

    if (left == 0 || right == 0) {
        cameras++;
        return 1;
    }

    if (left == 1 || right == 1) {
        return 2;
    }

    return 0;
}

int minCameraCover(struct TreeNode* root) {
    cameras = 0;
    if (dfs(root) == 0) {
        cameras++;
    }
    return cameras;
}
