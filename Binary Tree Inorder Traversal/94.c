/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
#define SIZE (101)

// static inline void _travel(struct TreeNode* root, int* returnSize, int* ret){
//     if(root == NULL)
//         return;
//     _travel(root->left, returnSize, ret);
//     ret[(*returnSize)++] = root->val;
//     _travel(root->right, returnSize, ret);
// }


// int* inorderTraversal(struct TreeNode* root, int* returnSize) {
//     *returnSize = 0;
//     if(root == NULL)
//         return NULL;
//     int* ret = (int*)malloc(sizeof(int)*SIZE);
//     _travel(root, returnSize, ret);
//     return ret;
// }


int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    int* ret = (int*)malloc(sizeof(int)*SIZE);

    struct TreeNode** stack = (struct TreeNode**)malloc(sizeof(struct TreeNode*)*SIZE);

    struct TreeNode* cur = root;
    int top = 0;

    while(cur){
        while(cur){
            stack[top++] = cur;
            cur = cur->left;
        }

        cur = stack[--top];
        ret[(*returnSize)++] = cur->val;

        cur = cur->right;
        while(cur == NULL && top > 0){
            cur = stack[--top];
            ret[(*returnSize)++] = cur->val;
            cur = cur->right;
        }

    }

    return ret;
}