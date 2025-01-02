/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
// #define TreeNode struct TreeNode




struct TreeNode* buildBST(int* nums, int start, int end){
    if(start == end){
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = nums[start];
        node->left = NULL;
        node->right = NULL;
        return node;
    }else{
        int mid = (start + end) / 2;
        struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
        node->val = nums[mid];
        if(mid == start)
            node->left = NULL;
        else
            node->left = buildBST(nums, start, mid - 1);
        if(mid == end)
            node->right = NULL;
        else
            node->right = buildBST(nums, mid + 1, end);
        return node;
    }
}

struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return NULL;
    return buildBST(nums, 0, numsSize - 1);
}