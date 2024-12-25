int maxSubArray(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return 0;
    int max = nums[0];
    int sum = max;
    for(int i = 1; i < numsSize; i++){
        //max = (nums[i] > max) ? nums[i] : max;
        sum += nums[i];
        if(sum < nums[i]){
            sum = nums[i];

        }
        max = (sum > max) ? sum : max;
    }
    return max;
}