int search(int* inorder, int start, int end, int val) {
    for (int i = start; i <= end; i++) {
        if (inorder[i] == val)
            return i;
    }
    return -1;
}

struct TreeNode* build(int* inorder, int inStart, int inEnd,
                       int* postorder, int* postIndex) {
    if (inStart > inEnd)
        return NULL;

    int val = postorder[*postIndex];
    (*postIndex)--;

    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->left = root->right = NULL;

    if (inStart == inEnd)
        return root;

    int pos = search(inorder, inStart, inEnd, val);

    root->right = build(inorder, pos + 1, inEnd, postorder, postIndex);
    root->left = build(inorder, inStart, pos - 1, postorder, postIndex);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize, int* postorder, int postorderSize) {
    int postIndex = postorderSize - 1;
    return build(inorder, 0, inorderSize - 1, postorder, &postIndex);
}
