/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool isPalindrome(struct ListNode* head) {
    if(head == NULL)
        return false;
    if(head->next == NULL)
        return true;
    int start = head->val;
    int end = -1;
    int len = 1;
    struct ListNode* tmp = head;
    while(tmp->next != NULL){
        tmp = tmp->next;
        end = tmp->val;
        len++;

    }

    if(start != end)
        return false;
    if(len < 4)
        return true;
    
    int stop = len/2 - 1;
    int i = 0;
    struct ListNode* prev = head;
    struct ListNode* cur = head->next;
    prev->next = NULL;
    for(int i = 0; i < stop; i++){
        tmp = cur;
        cur = cur->next;
        tmp->next = prev;
        prev = tmp;
    }

    if(len % 2 == 1)
        cur = cur->next;

    while(cur != NULL){
        if(cur->val != tmp->val)
            return false;
        cur = cur->next;
        tmp = tmp->next;
    }
    return true;

}


//same way, but use slow && fast pointer is more natual way to split the linklist

/*
 struct ListNode* rev(struct ListNode *head);
bool isPalindrome(struct ListNode* head) {
    
if(head==NULL || head->next==NULL){
    return true;
}

struct ListNode *slow=head;
    struct ListNode *fast=head;
    while(fast !=NULL &&fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    struct ListNode *second=rev(slow);
    struct ListNode *first =head;

    while(second!=NULL){
    if(first->val!=second->val)
        return false;
    
        first=first->next;
        second=second->next;
    
    }

    return true;
    
}
struct ListNode* rev(struct ListNode *head){

    struct ListNode *curr=head;
    struct ListNode *nextnode=NULL;
    struct ListNode *prev=NULL;

    while(curr!=NULL){
        nextnode=curr->next;
        curr->next =prev;
        prev=curr;
        curr=nextnode;
    }

return prev;
}
*/



