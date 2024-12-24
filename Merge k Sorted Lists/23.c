/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

#define ZERO_POS (10000)

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize) {
    if(lists == NULL || listsSize == 0)
        return NULL;

    int start = 10001;
    int end = -10001;

    int map[20000] = {0};
    int pos = -1;
    struct ListNode* head;

    for(int i = 0; i < listsSize; i++){
        if(lists[i] != NULL)
            start = (lists[i]->val < start) ? lists[i]->val : start;
    }

    if(start == 10001)
        return NULL;

    int val = -10001;
    for(int i = 0; i < listsSize; i++){
        head = lists[i];
        while(head != NULL){
            val = head->val;
            pos = (val < 0) ? ZERO_POS - abs(val) : ZERO_POS + val;
            map[pos]++;
            head = head->next;
        }
        end = (val > end) ? val : end;
    }
    
    head = (struct ListNode*)malloc(sizeof(struct ListNode));
    struct ListNode* cur = head;
    head->val = start;
    head->next = NULL;
    int last;
    if(start < 0){
        pos = ZERO_POS - abs(start);
        map[pos]--;
        last = (end < 0) ? ZERO_POS - abs(end) + 1 : ZERO_POS;

        for(int i = pos; i < last; i++){
            while(map[i]){
                cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
                cur = cur->next;
                cur->val = 0 - (ZERO_POS - i);
                cur->next = NULL;
                map[i]--;
            }
        }
    }else{
        pos = ZERO_POS + start;
        map[pos]--;
    }

    
    last = ZERO_POS + end + 1;
    for(int i = ZERO_POS; i < last; i++){
        while(map[i]){
            cur->next = (struct ListNode*)malloc(sizeof(struct ListNode));
            cur = cur->next;
            cur->val = i - ZERO_POS;
            cur->next = NULL;
            map[i]--;
        }
    }

    return head;
}