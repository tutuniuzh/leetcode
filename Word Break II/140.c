/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct _node{
    int idx; //dict index
    int end;
    struct _node* next;
    
}NODE;

typedef struct _queue{
    NODE* head;
    NODE* tail;
}QUEUE;


#define SIZE (512)
#define ILEN (32)
#define SUB (64)

void breakWord(char** ret, int qIdx, QUEUE* seq, char** wordDict, int *returnSize, int* words, int idx, int len){
    if(seq[qIdx].head == NULL)
        return;
    
    NODE* cur = seq[qIdx].head;
    do{
        //each sub will overwrite this position
        words[idx] = cur->idx;

        if(cur->end == len){
            char* tmp = (char*)malloc(sizeof(char)*SUB);
            int k = 0;
            for(int i = 0; i < idx + 1; i++){
                int j = 0;
                while(wordDict[words[i]][j] != '\0')
                    tmp[k++] = wordDict[words[i]][j++];
                if(idx != i)
                    tmp[k++] = ' ';
            }
            tmp[k++] = '\0';
            ret[(*returnSize)++] = tmp;
        }else{
            breakWord(ret, cur->end, seq, wordDict, returnSize, words, idx + 1, len);
        }

        cur = cur->next;
    }while(cur != NULL);
}


char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
    *returnSize = 0;
    if(s == NULL)
        return NULL;
    
    int sLen = strlen(s);
    if(sLen == 0)
        return NULL;

    QUEUE* seq = (QUEUE*)calloc(sLen, sizeof(QUEUE));

    // QUEUE seq[QLEN];
    // for(int i = 0; i < QLEN; i++){
    //     seq[i].head = NULL;
    //     seq[i].tail = NULL;
    // }

    for(int i = 0; i < wordDictSize; i++){
        char first = wordDict[i][0];
        int wLen = strlen(wordDict[i]);
        for(int j = 0; j < sLen; j++){
            if(s[j] == first && j + wLen <= sLen && !strncmp((char*)(s + j), wordDict[i], wLen)){
                NODE* node = (NODE*)malloc(sizeof(NODE));
                //word dictionary index
                node->idx = i;
                // node->len = len;
                //next compare poisition on s
                node->end = j + wLen;
                node->next = NULL;
                if(seq[j].head == NULL){
                    //empty queue
                    seq[j].head = node;
                    seq[j].tail = node;
                }else{
                    //queue with nodes
                    seq[j].tail->next = node;
                    seq[j].tail = node;
                }
            }
        }
    }

    if(seq[0].head == NULL){
        for(int i = 1; i < sLen; i++){
            while(seq[i].head != NULL){
                NODE* cur = seq[i].head;
                seq[i].head = seq[i].head->next;
                free(cur);
            }
        }
        return NULL;
    }

    char** ret = (char**)malloc(sizeof(char*)*SIZE);

    int words[ILEN];
    while(seq[0].head != NULL){
        NODE* cur = seq[0].head;
        words[0] = cur->idx;
        if(cur->end == sLen){
            char* tmp = (char*)malloc(sizeof(char)*(sLen + 1));
            strncpy(tmp, s, sLen);
            tmp[sLen] = '\0';
            ret[(*returnSize)++] = tmp;
        }else
            breakWord(ret, cur->end, seq, wordDict, returnSize, words, 1, sLen);
        seq[0].head = seq[0].head->next;
        free(cur);
    }


    for(int i = 0; i < sLen; i++){
        while(seq[i].head != NULL){
            NODE* cur = seq[i].head;
            seq[i].head = seq[i].head->next;
            free(cur);
        }
    }

    if(*returnSize)
        return ret;
    free(ret);

    return NULL;

}


/*
    below is the backtrack way, much more concise same
    exactly the same way, same time complexity
    but my sloution use extra data structure which is a hash table
    
*/

// #define MAXANS 100000
// void backTrack(char *s, int i, char **dict, int dsz, int curp, char **ans, int *ansLen) {
//     static char curr[MAXANS];
//     int j, dLen;
//     if (s[i] == '\0') {
//         ans[*ansLen] = strdup(curr);
//         *ansLen += 1;
//         return;
//     }
//     if (curp > 0) curr[curp++] = ' ';
//     for (j = 0; j < dsz; ++j) {
//         dLen = strlen(dict[j]);
//         if (strncmp(s+i, dict[j], dLen)) continue;
//         strcpy(curr+curp, dict[j]);
//         backTrack(s, i+dLen, dict, dsz, curp+dLen, ans, ansLen);
//     }
// }
// char** wordBreak(char* s, char** wordDict, int wordDictSize, int* returnSize) {
//     char **ans = (char**) malloc(MAXANS * sizeof(char*));
//     int ansLen = 0;
//     backTrack(s, 0, wordDict, wordDictSize, 0, ans, &ansLen);
//     *returnSize = ansLen;
//     return ans;
// }