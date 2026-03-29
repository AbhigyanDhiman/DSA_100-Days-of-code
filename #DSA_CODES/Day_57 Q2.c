void flatten(struct TreeNode* root) {
    if (root == NULL)
        return;

    flatten(root->left);
    flatten(root->right);

    struct TreeNode* left = root->left;
    struct TreeNode* right = root->right;

    root->left = NULL;
    root->right = left;

    struct TreeNode* temp = root;
    while (temp->right != NULL) {
        temp = temp->right;
    }

    temp->right = right;
}
