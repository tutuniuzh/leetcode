/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize) {
    int final = nums[0];
    for(int i = 1; i < numsSize; i++)
        final ^= nums[i];
    
    //find first set bit from bit0
    int n = 0;
    long long check = 1;
    while((final & check) == 0){
        // n++;
        check = check << 1;
    }

    // int check = 1;
    // check = check << n;
    int first = final;
    int second = final;


    for(int i = 0; i < numsSize; i++){
        if(nums[i] & check){
            first ^= nums[i];
        }else{
            second ^= nums[i];
        }
    }

    int* ret = (int*)malloc(sizeof(int)*2);
    ret[0] = first;
    ret[1] = second;

    *returnSize = 2;
    return ret;
}