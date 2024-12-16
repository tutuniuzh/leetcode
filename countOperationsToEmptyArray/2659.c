typedef struct comb{
    int val;
    int pos;
}COMB;

int cmp(const void *a, const void *b){
    int val1 = (*(COMB*)a).val;
    int val2 = (*(COMB*)b).val;

    if(val1 == val2) return 0;
    return val2 < val1 ? 1 : -1;
}

long long countOperationsToEmptyArray(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return 0LL;
    
    if(numsSize == 1)
        return 1;
    
    COMB* comb = (COMB*)malloc(sizeof(COMB)*numsSize);

    for(int i = 0; i < numsSize; i++){
        comb[i].val = nums[i];
        comb[i].pos = i;
    }
    qsort(comb, numsSize, sizeof(COMB), cmp);

    int pos = comb[0].pos;
    long long distant = numsSize;

    for(int i = 1; i < numsSize; i ++){
        if(pos > comb[i].pos){
            distant += numsSize - i;
        }
        pos = comb[i].pos;
    }
    free(comb);
    return distant;
}