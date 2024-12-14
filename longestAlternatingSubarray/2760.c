typedef enum pattern{
    EVEN,
    ODD
}PATTERN;

int longestAlternatingSubarray(int* nums, int numsSize, int threshold) {
    int max = -1;
    PATTERN p = EVEN;
    int cur = 0;
    for(int i = 0; i < numsSize; i++){
        int val = nums[i];
        if(val%2 == p && val <= threshold){
            cur++;
            p = p^1;
        }else if(cur){
            max = (cur > max) ? cur : max;
            cur = 0;
            p = EVEN;
            if(val <= threshold && val%2 == 0){
                cur = 1;
                p = ODD;
            }
        }
    }
    max = (cur > max) ? cur : max;
    return max;
    
}

