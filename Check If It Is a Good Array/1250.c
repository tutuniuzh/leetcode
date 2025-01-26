static inline int _findGcd(int a, int b){

    int max, min;
    if(a > b){
        max = a;
        min = b;
    }else{
        max = b;
        min = a;
    }

    int r = max % min;
    while(r){
        int tmp = r;
        r = min % tmp;
        min = tmp;
    }

    return min;
}

bool isGoodArray(int* nums, int numsSize) {
    if(numsSize == 1){
        if(nums[0] == 1)
            return true;
        return false;
    }

    int gcd = _findGcd(nums[0], nums[1]);
    if(gcd == 1)
        return true;
    for(int i = 2; i < numsSize; i++){
        gcd = _findGcd(gcd, nums[i]);
        if(gcd == 1)
            return true;
    }
    return false;
}