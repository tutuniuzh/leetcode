static int _findPos(int* nums, int start, int end, int* new){
    if(start < end){
        int mid = (end + start) / 2;
        if(nums[mid] < nums[end])
            return mid;
        *new = mid;
        return _findPos(nums, mid + 1, end, new);
    }
    return end;
}


int findMin(int* nums, int numsSize) {
    if(numsSize == 0 || nums == NULL)
        return 0;
    
    if(nums[0] < nums[numsSize - 1])
        return nums[0];

    int lastPos = numsSize - 1;
    int start = 1;
    int newStart = 1;
    int pos = _findPos(nums, start, numsSize - 1, &newStart);
    while(lastPos != pos){
        lastPos = pos;
        start = newStart;
        pos = _findPos(nums, start, pos, &newStart);
    }
    return nums[pos];    
}

//Iterative way is more concise than recursion