/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
long long* maximumEvenSplit(long long finalSum, int* returnSize) {
    *returnSize = 0;
    if(finalSum % 2)
        return NULL;
    long long n = sqrt(finalSum);
    /*
    ((1 + n)n)/2
    n/2 + n*n/2 = x
    */
    long long sum = (1+n)*n;
    if(sum == finalSum){
        *returnSize = n;
        long long * ret = (long long *)malloc(sizeof(long long)*n);
        for(int i = 0; i <= n - 1; i++){
            ret[i] = (i + 1)*2;
        }
        return ret;
    }else if (sum < finalSum){
        *returnSize = n;
        sum = n*(n - 1);
        int last = finalSum - sum;
        long long * ret = (long long *)malloc(sizeof(long long)*n);
        for(int i = 0; i <= n - 2; i++){
            ret[i] = (i + 1)*2;
        }
        ret[n - 1] = last;
        return ret;
    }else{
        *returnSize = n - 1;
        sum = (n - 1)*(n - 2);
        int last = finalSum - sum;
        long long * ret = (long long *)malloc(sizeof(long long)*n);
        for(int i = 0; i <= n - 3; i++){
            ret[i] = (i + 1)*2;
        }
        ret[n - 2] = last;
        return ret;
    }

}