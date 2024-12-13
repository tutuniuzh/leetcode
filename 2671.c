#define HASH (0)

#if HASH
#define HASH_CODE (1000)
#define NUM_SIZE HASH_CODE

typedef struct node{
    struct node* next;
    int val;
    int count;
}NODE;

typedef struct {
    NODE **arr;
    NODE **freq;
} FrequencyTracker;

typedef enum operation{
    SUB,
    ADD
}OP;
#else

#define NUM_SIZE (100001)

typedef struct {
    int *arr;
    int *freq;
} FrequencyTracker;

#endif

FrequencyTracker* frequencyTrackerCreate() {
    FrequencyTracker* ft = (FrequencyTracker*)malloc(sizeof(FrequencyTracker));
    #if HASH
    ft->arr = (NODE**)calloc(NUM_SIZE, sizeof(NODE*));
    ft->freq = (NODE**)calloc(NUM_SIZE, sizeof(NODE*));
    #else
    ft->arr = (int*)calloc(NUM_SIZE, sizeof(int));
    ft->freq = (int*)calloc(NUM_SIZE, sizeof(int));
    #endif
    return ft;
}

#if HASH

static inline int addCountNode(NODE** arr, int val){
    int idx = val % HASH_CODE;

    if(arr[idx] == NULL){
        //first one
        arr[idx] = (NODE*)malloc(sizeof(NODE));
        arr[idx]->val = val;
        arr[idx]->count = 1;
        arr[idx]->next = NULL;
        //return previous value
        return 0;
    }

    //entry exist
    NODE* tmp = arr[idx];
    //check first one
    if(tmp->val == val)
        return tmp->count++;


    while(tmp->next){
        tmp = tmp->next;
        if(tmp->val == val){
            return tmp->count++;
        }
    }

    //new one
    tmp->next = (NODE*)malloc(sizeof(NODE));
    tmp->next->val = val;
    tmp->next->count = 1;
    tmp->next->next = NULL;
    return 0;
}


static inline int subCountNode(NODE** arr, int val){
    int idx = val % HASH_CODE;

    if(arr[idx] == NULL)
        return 0;

    //entry exist
    NODE* tmp = arr[idx];
    //check first one
    if(tmp->val == val)
        return (tmp->count) ? tmp->count-- : 0;

    while(tmp->next){
        tmp = tmp->next;
        if(tmp->val == val)
            return (tmp->count) ? tmp->count-- : 0;
    }

    return 0;
}

static inline void opFreqNode(NODE** arr, int val, OP op){
    int idx = val % HASH_CODE;
   

    if(op == SUB){
        //count already exists
        //it would always be founded and be bigger than zero
        NODE* tmp = arr[idx];
        while(tmp){
            if(tmp->val == val){
                tmp->count--;
                return;
            }
            tmp = tmp->next;
        }
    }else{
        //ADD
        if(arr[idx] == NULL){
            //first one
            arr[idx] = (NODE*)malloc(sizeof(NODE));
            arr[idx]->val = val;
            arr[idx]->count = 1;
            arr[idx]->next = NULL;
            return;
        }

        NODE* tmp = arr[idx];
        if(tmp->val == val){
            tmp->count++;
            return;
        }

        while(tmp->next){
            tmp = tmp->next;
            if(tmp->val == val){
                tmp->count++;
                return;
            }
        }

        //new one
        tmp->next = (NODE*)malloc(sizeof(NODE));
        tmp->next->val = val;
        tmp->next->count = 1;
        tmp->next->next = NULL;
        return;
    }
}




static inline int getFreqNode(NODE** arr, int val){
    int idx = val % HASH_CODE;

    if(arr[idx] == NULL)
        return 0;

    //entry exist
    NODE* tmp = arr[idx];
    //check first one
    if(tmp->val == val)
        return tmp->count;


    while(tmp->next){
        tmp = tmp->next;
        if(tmp->val == val){
            return tmp->count;
        }
    }

    return 0;
}

#endif

void frequencyTrackerAdd(FrequencyTracker* obj, int number) {
    #if HASH
    int cnt = addCountNode(obj->arr, number);
    if(cnt)
        opFreqNode(obj->freq, cnt, SUB);
    opFreqNode(obj->freq, cnt + 1, ADD);
    #else
    int val = obj->arr[number]++;
    if(val)
        obj->freq[val]--;
    
    obj->freq[obj->arr[number]]++;
    #endif
}

void frequencyTrackerDeleteOne(FrequencyTracker* obj, int number) {
    #if HASH
    int cnt = subCountNode(obj->arr, number);
    if(cnt){
        opFreqNode(obj->freq, cnt--, SUB);
        if(cnt)
            opFreqNode(obj->freq, cnt, ADD);
    }
    #else
    if(obj->arr[number]){
        int val = obj->arr[number]--;
        obj->freq[val]--;
        if(obj->arr[number])
            obj->freq[obj->arr[number]]++;
    }
    #endif
}

bool frequencyTrackerHasFrequency(FrequencyTracker* obj, int frequency) {
    #if HASH
    return (getFreqNode(obj->freq, frequency) != 0);
    #else
    return (obj->freq[frequency] != 0);
    #endif
}

void frequencyTrackerFree(FrequencyTracker* obj) {

    #if HASH
    for(int i = 0; i < NUM_SIZE; i++){
        NODE* tmp = obj->freq[i];
        while(tmp){
            NODE* next = tmp->next;
            free(tmp);
            tmp = next;
        }

        tmp = obj->arr[i];
        while(tmp){
            NODE* next = tmp->next;
            free(tmp);
            tmp = next;
        }
    }
    #else
    free(obj->freq);
    free(obj->arr);
    #endif
    free(obj);
}

/**
 * Your FrequencyTracker struct will be instantiated and called as such:
 * FrequencyTracker* obj = frequencyTrackerCreate();
 * frequencyTrackerAdd(obj, number);
 
 * frequencyTrackerDeleteOne(obj, number);
 
 * bool param_3 = frequencyTrackerHasFrequency(obj, frequency);
 
 * frequencyTrackerFree(obj);
*/

/*
    Big Array is the best solution for this problem
    calloc is much better than malloc to initialize the array
    HASH table conflicts are much more then I expected
*/