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

static void _find(int* number, int level, int* returnSize, struct TreeNode* root, char** ret){
    number[level] = root->val;
    if(root->left == NULL && root->right == NULL){
        // int negtaive = (level + 1);
        char* tmp = (char*)malloc(sizeof(char)*(12*level + 3));
        for(int i = 0, j = 0; i < level + 1; i++){
            // int val = number[i];
            // if(val < 0){
            //     tmp[j++] = '-';
            //     val = -val;
            // }
            // tmp[j++] = (char)(val + '0');
            j += sprintf(&tmp[j], "%d", number[i]);
            if(i != level){
                tmp[j++] = '-';
                tmp[j++] = '>';
            }
            else
                tmp[j++] = '\0';
        }
        ret[(*returnSize)++] = tmp;
        return;
    }
    if(root->left)
        _find(number, level + 1, returnSize, root->left, ret);
    if(root->right)
        _find(number, level + 1, returnSize, root->right, ret);

}

#define SIZE (500)
char** binaryTreePaths(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;
    if(root == NULL)
        return NULL;
    
    int number[100];
    char** ret = (char**)malloc(sizeof(char*)*SIZE);
    _find(number, 0, returnSize, root, ret);


    return ret;
}