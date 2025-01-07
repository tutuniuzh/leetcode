/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

static void _connect(struct Node* root){
    if(root == NULL)
        return;

    struct Node* cur = root;
    root = NULL;
    struct Node* right = NULL;

    while(cur != NULL){
        if(right != NULL){
            if(cur->left){
                right->next = cur->left;
                right = cur->left;
                if(cur->right){
                    right->next = cur->right;
                    right = cur->right;
                }
            }else if(cur->right){
                right->next = cur->right;
                right = cur->right;
            }
        }else{
            if(cur->left){
                root = cur->left;
                right = cur->left;
                if(cur->right){
                    right->next = cur->right;
                    right = cur->right;
                }
            }else if(cur->right){
                root = cur->right;
                right = cur->right;
            }
        }
        cur = cur->next;
    }
    _connect(root);
}




struct Node* connect(struct Node* root) {

	//     if (!root) {
    //     return NULL;
    // }

    // struct Node* levelStart = root;

    // while (levelStart) {
    //     struct Node* curr = levelStart;
    //     levelStart = NULL;

    //     struct Node* prev = NULL;
    //     while (curr) {
    //         if (curr->left) {
    //             if (!levelStart) {
    //                 levelStart = curr->left;
    //             }
    //             if (prev) {
    //                 prev->next = curr->left;
    //             }
    //             prev = curr->left;
    //         }

    //         if (curr->right) {
    //             if (!levelStart) {
    //                 levelStart = curr->right;
    //             }
    //             if (prev) {
    //                 prev->next = curr->right;
    //             }
    //             prev = curr->right;
    //         }

    //         curr = curr->next;
    //     }
    // }

    // return root;
    
    _connect(root);

    return root;
}

//iteration way is better, no need to setup the stack
