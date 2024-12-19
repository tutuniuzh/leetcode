int getLeftNum(int* arr, double val, int start, int end){
    if(start == end){
        if(val >= arr[start])
            return start + 1;
        else
            return start;
    }else if(start < end){
        int mid = (end + start) / 2;
        if(val == arr[mid])
            return mid + 1;
        else if (val > arr[mid])
            return getLeftNum(arr, val, mid + 1, end);
        else
            return getLeftNum(arr, val, start, mid - 1);
    }else
        return end + 1;
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {

    if(nums1 == NULL && nums2 == NULL || (nums1Size == 0 && nums2Size == 0))
        return 0.0;
    
    if(nums1 == NULL || nums1Size == 0){
        int mid = nums2Size / 2;
        if(nums2Size%2)
            return nums2[mid];
        else
            return (nums2[mid - 1] + nums2[mid]) / 2.0F;
    }

    if(nums2 == NULL || nums2Size == 0){
        int mid = nums1Size / 2;
        if(nums1Size%2)
            return nums1[mid];
        else
            return (nums1[mid - 1] + nums1[mid]) / 2.0F;
    }

    int mid1 = nums1Size/2;
    double median;
    if(nums1Size % 2){
        median = nums1[mid1];
    }else{
        median = (nums1[mid1 - 1] + nums1[mid1]) / 2.0F;
    }


    int numOfNums2LessThanMidinNums1 = getLeftNum(nums2, median, 0, nums2Size - 1);
    int odd = 0;
    int len = nums1Size + nums2Size;
    int mid = len/2;
    if(len % 2)
        odd = 1;


    if(nums1[0] >= nums2[nums2Size - 1]){
        //nums2 + nums1
        if(mid > nums2Size)
            if(odd)
                return nums1[mid - nums2Size];
            else
                return (nums1[mid - nums2Size - 1] + nums1[mid - nums2Size])/2.0F;
        else if(mid == nums2Size){
            if(odd)
                return nums1[0];
            else
                return (nums2[mid - 1] + nums1[0]) / 2.0F;
        }else{
            if(odd)
                return nums2[mid];
            else 
                return (nums2[mid - 1] + nums2[mid])/2.0F;
        }
    }else if(nums2[0] >= nums1[nums1Size - 1]){
        //nums1 + nums2
        if(mid > nums1Size){
            if(odd)
                return nums2[mid - nums1Size];
            else
                return (nums2[mid - nums1Size - 1] + nums2[mid - nums1Size])/2.0F;
        }
        else if(mid == nums1Size){
            if(odd)
                return nums2[0];
            else
                return (nums1[mid - 1] + nums2[0])/2.0F;

        }else{
            if(odd)
                return nums1[mid];
            else
                return (nums1[mid - 1] + nums1[mid])/2.0F;
        }
    }
    
    
    int nums2Pos, ceiling, floor, start, end, leastPos, mostPos;
    int right = nums2Size - numOfNums2LessThanMidinNums1;
    int left = numOfNums2LessThanMidinNums1;

    if(left == right){
        if(odd)
            return median;
        else{
            int val1, val2;
            if(getLeftNum(nums1, nums2[numOfNums2LessThanMidinNums1 - 1], 0, nums1Size - 1) + numOfNums2LessThanMidinNums1 - 1 == mid - 1)
                val1 = nums2[numOfNums2LessThanMidinNums1 - 1];
            else
                val1 = nums1[mid - left - 1];
            
            if(getLeftNum(nums1, nums2[numOfNums2LessThanMidinNums1], 0, nums1Size - 1) + numOfNums2LessThanMidinNums1 == mid)
                val2 = nums2[numOfNums2LessThanMidinNums1];
            else
                val2 = nums1[mid - left];
            return (val1 + val2) / 2.0F;
        }
    }

    if(right > left){
        leastPos = numOfNums2LessThanMidinNums1;
        mostPos = nums2Size;
        nums2Pos = leastPos;
        ceiling = mostPos;
        floor = leastPos;
        start = mid1;
        end = nums1Size - 1;
    }
    else{
        mostPos = numOfNums2LessThanMidinNums1 - 1;
        leastPos = 0;
        nums2Pos = mostPos;
        ceiling = mostPos;
        floor = leastPos;
        start = 0;
        end = mid1 - 1;
    }

    while(1){
        int nums1Pos = getLeftNum(nums1, nums2[nums2Pos], 0, nums1Size - 1);
        int newPos = nums1Pos + nums2Pos;
        if( newPos > mid){
            if(leastPos == nums2Pos){
                //case 1
                //least element in nums2 bigger than middle pos
                //if the total length is odd, in this scenario
                //middle pos must be in the nums1
                if(odd)
                    return nums1[mid - leastPos];
                else
                    return (nums1[mid - leastPos - 1] + nums1[mid - leastPos]) / 2.0F;
            }else{
                if(nums2Pos == floor){
                //cannot be decreased anymore
                    if(odd)
                        return nums1[mid - left];
                    else{
                        int newNums1Pos = getLeftNum(nums1, nums2[nums2Pos], 0, nums1Size - 1);
                        if(newNums1Pos + nums2Pos == mid - 1)
                            return (nums2[nums2Pos] + nums1[mid - left]) / 2.0F;
                        return (nums1[mid - left - 1] + nums1[mid - left]) / 2.0F;
                    }
                }

                ceiling = nums2Pos;
                nums2Pos = (nums2Pos + floor) / 2;
            }
        }else if(newPos < mid){
            if(nums2Pos == nums2Size - 1){
                //case2
                if(odd)
                    return nums1[mid - nums2Size];
                else
                    if(newPos == mid - 1)
                        return (nums2[nums2Pos] + nums1[mid - nums2Size])/2.0F;
                    return (nums1[mid - nums2Size - 1] + nums1[mid - nums2Size]) / 2.0F;

            }
            else{
                //can not use (nums2Pos+ceiling)/2 to reach ceiling
                //ceiling - 1 is the highest pos can get
                //if nums2pos equals to ceiling - 1 it can't be increased anymore
                if(nums2Pos == ceiling || nums2Pos == ceiling - 1){
                    if(odd)
                        return nums1[mid - nums2Pos - 1];
                    else{
                        if(newPos == mid - 1)
                            return (nums2[nums2Pos] + nums1[mid - nums2Pos - 1]) / 2.0F;
                        return (nums1[mid - nums2Pos - 2] + nums1[mid - nums2Pos - 1]) / 2.0F;
                    }
                }
                floor = nums2Pos;
                nums2Pos = (nums2Pos + ceiling) / 2;
            }
        }else{
            //find the middle
            if(odd)
                return nums2[nums2Pos];
            else{
                //find mid - 1
                if(nums2Pos == leastPos)
                    return (nums1[nums1Pos - 1] + nums2[nums2Pos]) / 2.0F;
                
                int newNums1Pos = getLeftNum(nums1, nums2[nums2Pos - 1], 0, nums1Size - 1);
                if(newNums1Pos + nums2Pos - 1 == mid - 1)
                    return (nums2[nums2Pos - 1] + nums2[nums2Pos]) / 2.0F;
                else
                    return (nums1[nums1Pos - 1] + nums2[nums2Pos]) / 2.0F;
            }
        }
    }

}

//My solution is the only one solution in leetcode which meet O(log(m+n)) of time complexity