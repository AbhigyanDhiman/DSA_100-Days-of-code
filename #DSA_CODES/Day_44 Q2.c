void preorder(struct TreeNode* root, int* arr, int* index)
{
    if(root == NULL)
        return;

    arr[*index] = root->val;
    (*index)++;

    preorder(root->left, arr, index);
    preorder(root->right, arr, index);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize) 
{
    int* result = (int*)malloc(1000 * sizeof(int));
    int index = 0;

    preorder(root, result, &index);

    *returnSize = index;
    return result;
}
