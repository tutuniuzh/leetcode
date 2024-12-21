int biSearch(int* nums, int start, int end, int target){
    if(start == end){
        if(target == nums[start])
            return start;
        return -1;
    }else{
        int mid = (start + end) / 2 ;
        if(nums[mid] == target)
            return mid;
        if(nums[mid] > target){
            if(mid == start)
                return -1;
            return biSearch(nums, start, mid - 1, target);
        }
        else{
            if(mid == end)
                return -1;
            return biSearch(nums, mid + 1, end, target);
        }
    }
}

int rotateSearch(int* nums, int target, int start, int end, int origin){
    if(start == end){
        if(nums[start] == target)
            return start;
        return -1;
    }else if(start < end){
        int mid = (start + end) / 2;
        if(nums[mid] == target)
            return mid;
        else{
            if(nums[mid] >= origin){
                if(target >= origin){
                    if(nums[mid] > target)
                        return rotateSearch(nums, target, start, mid - 1, origin);
                    else
                        return rotateSearch(nums, target, mid + 1, end, origin);
                }else{
                    //keep right to find the pivot
                    return rotateSearch(nums, target, mid+1, end, origin);
                }
            }else{
                //find pivot
                if(target >= origin){
                    //target bigger than origin, backtrack to left
                    return rotateSearch(nums, target, start, mid - 1, origin);
                }else{
                    if(nums[mid] > target)
                        return rotateSearch(nums, target, start, mid - 1, origin);
                    else
                        return rotateSearch(nums, target, mid + 1, end, origin);
                }
            }
        }
    }else
        return -1;
}



int search(int* nums, int numsSize, int target) {
    if(nums == NULL || numsSize == 0)
        return -1;
    if(numsSize < 2){
        for(int i = 0; i < numsSize; i++)
            if(nums[i] == target)
                return i;
        return -1;
    }

    if(nums[numsSize - 1] > nums[0]){
        //no rotated
        return biSearch(nums, 0, numsSize-1, target);
    }else{
        // uncomment below code can concise the >= to > in rotateSearch
        // if(nums[0] > target && nums[numsSize - 1] < target)
        //     return -1;
        return rotateSearch(nums, target, 0, numsSize-1, nums[0]);
    }
}