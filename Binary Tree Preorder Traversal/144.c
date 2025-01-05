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


#define SIZE (100)
int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    //root->left->right
    *returnSize = 0;
    if(root == NULL)
        return NULL;
    
    struct TreeNode* stack[SIZE];
    int* ret = (int*)malloc(sizeof(int)*SIZE);
    int top = 0;
    //push root
    stack[top] = root;
    struct TreeNode* cur = root;
    ret[(*returnSize)++] = cur->val;
    while(top >= 0){
        cur = stack[top];
        if(cur->left != NULL && cur->left->val <200){
            //push into stack
            stack[++top] = cur->left;
            ret[(*returnSize)++] = cur->left->val;
        }else if(cur->right != NULL && cur->right->val < 200){
            stack[++top] = cur->right;
            ret[(*returnSize)++] = cur->right->val;
        }else{
            //free(cur);
            cur->val = 200;

            top--;
        }
    }

    return ret;

}

//do preorder by iteratively
//have to modify the value of node to mark the node has been traversed