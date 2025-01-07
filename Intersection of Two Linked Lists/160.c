/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
    if(headA == NULL || headB == NULL)
        return NULL;
    struct ListNode * ret = NULL;

    struct ListNode* cur = headA;
    while(cur != NULL){
        cur->val = 0 - cur->val;
        cur = cur->next;
    }

    // while(headB != NULL){
    //     if(headB->val < 0){
    //         ret = headB;
    //         break;
    //     }
    //     headB = headB->next;
    // }
    // while(headA != NULL){
    //     headA->val = abs(headA->val);
    //     headA = headA->next;
    // }



    while(headB != NULL){
        if(headB->val < 0){
            ret = headB;
            do{
                headB->val = abs(headB->val);
                headB = headB->next;
            }while(headB != NULL);
            break;
        }
        headB = headB->next;
    }       


    do{
        headA->val = abs(headA->val);
        headA = headA->next;
    }while(headA);


    return ret;

}

//this way is better than count two linklist and start from the same pos