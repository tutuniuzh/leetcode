static int _max(int a, int b, int c){
    return (a > b) ? ((a > c) ? a : c) : ((b > c) ? b : c);
}


int maxProduct(int* nums, int numsSize) {
    if(nums == NULL || numsSize == 0)
        return 0;
    if(numsSize == 1)
        return nums[0];
    
    int positive = 1;
    int negative = 1;
    int max = -11;

    for(int i = 0; i < numsSize; i++){
        if(nums[i] == 0){
            positive = 1;
            negative = 1;
            max = (max > 0) ? max : 0;
        }else if(nums[i] < 0){
            negative = negative * nums[i];
            max = (negative > max) ? negative : max;
            positive = 1;
        }else{
            positive *= nums[i];
            negative *= nums[i];
            // max = (positive > max) ? positive : max;
            max = _max(max, positive, negative);
        }
    }

    int ret = max;
    positive = 1;
    negative = 1;
    max = -11;

    for(int i = numsSize - 1; i >= 0 ; i--){
        if(nums[i] == 0){
            positive = 1;
            negative = 1;
            max = (max > 0) ? max : 0;
        }else if(nums[i] < 0){
            negative = negative * nums[i];
            max = (negative > max) ? negative : max;
            positive = 1;
        }else{
            positive *= nums[i];
            negative *= nums[i];
            // max = (positive > max) ? positive : max;
            max = _max(max, positive, negative);
        }
    }

    return (max > ret) ? max : ret;
}

//if there are even numbers of negative figures in a none zero procession one loop is enough
//if there are odd numbers of negative figures in a none zero procession, which one of the two outter odd numbers should be discarded is a problem
//a loop from zero to max, will only fetch the most right one of the two outtter odd numbers
//use a reverse loop will figure out this problem, the reverse one will always fetch the most left one of the two outter odd numbers
// -3 ... -5 ... -2 ... -8 ... -1 first loop win
// -3 ... -5 ... -2 ... -8 ... -5 reverse win 