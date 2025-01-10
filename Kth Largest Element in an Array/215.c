static inline void _swap(int *a, int *b){
    int tmp = *b;
    *b = *a;
    *a = tmp;
}

static int quickSelection(int* nums, int start, int end, int k){
    if(start < end){
    //    int mid = (start + end) / 2;
        int pivot = nums[end];
        int i = start;
        int j = end - 1;
        while(i <= j){
            for(;i <= end && nums[i] < pivot; i++);
            for(;j >= start && nums[j] > pivot; j--);
            if(i <= j)
                _swap(&nums[i++], &nums[j--]);
        }
        _swap(&nums[i], &nums[end]);
        if(i == k)
            return nums[i];
        else if( i > k)
            return quickSelection(nums, start, i - 1, k);
        else
            return quickSelection(nums, i + 1, end, k);
    }
    
    return nums[start];

}




int findKthLargest(int* nums, int numsSize, int k) {
    // if(nums == NULL || numsSize == 0)

    // quick selection way
    //return quickSelection(nums, 0, numsSize - 1, numsSize - k);

    int max = nums[0];
    int min = max;
    for(int i = 1; i < numsSize; i++){
        max = (nums[i] > max) ? nums[i] : max;
        min = (nums[i] < min) ? nums[i] : min;
    }


    //granularity is 1
    int range = max - min + 1;
    int * c = (int*)calloc(range, sizeof(int));



    for(int i = 0; i < numsSize; i++){
        c[max - nums[i]] ++; //represent how many element eaqual to this value;
    }

    int rank = 0;


    if(k < numsSize/2){
        //find from max
        for(int i = 0; i < range; i++){
            rank += c[i];
            if(rank >= k)
                return max - i;
        }
    }else{
        //find from min
        for(int i = range - 1; i >= 0; i--){
            rank += c[i];
            if(rank >= numsSize - k + 1)
                return max - i;
        }
    }


    return -1;
}

//quick selection is a common way for this kind of problem.
//but using range is a more interesting method