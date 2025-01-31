#define SIZE (50000)

int findShortestSubArray(int* nums, int numsSize) {
    int cnt[SIZE] = {0};
    int start[SIZE] = {0};
    int shortest = 0;
    int max = 0;
    for(int i = 0; i < numsSize; i ++){
        int cur = nums[i];
        if(cnt[cur] == 0){
            cnt[cur] = 1;
            start[cur] = i;
            if(max < 1){
                max = 1;
                shortest = 1;
            }
        }else{
            int c = ++cnt[cur];
            if(max == c){
                max = c;
                int dis = i -  start[cur] + 1;
                shortest = (dis < shortest) ? dis : shortest;
            }else if(max < c){
                max = c;
                shortest = i -  start[cur] + 1;
            }
        }
    }

    return shortest;
    
}