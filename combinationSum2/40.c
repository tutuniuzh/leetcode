int compare(const void* a, const void* b){
    return(*(int*)a - *(int*)b);
}


void findSub(int** ret, int* tmp, int* returnSize, int* returnColumnSizes, int target, int* candidates, int start, int end, int len){
    if(end < start)
        return;

    if(start == end){
        if(candidates[start] == target){
            ret[*returnSize] = (int*)malloc(sizeof(int)*(len + 1));
            memcpy(ret[*returnSize], tmp, len*sizeof(int));
            ret[*returnSize][len] = target;
            returnColumnSizes[(*returnSize)++] = len + 1;
        }
        return;
    }
    
    if(candidates[start] > target)
        return;
    else if(candidates[start] == target){
        ret[*returnSize] = (int*)malloc(sizeof(int)*(len + 1));
        memcpy(ret[*returnSize], tmp, len*sizeof(int));
        ret[*returnSize][len] = target;
        returnColumnSizes[(*returnSize)++] = len + 1;
        return;
    }else{
        tmp[len] = candidates[start];
        findSub(ret, tmp, returnSize, returnColumnSizes, target - candidates[start], candidates, start + 1, end, len+1);
    }

    for(int i = start + 1; i < end + 1; i++){
        if(candidates[i - 1] == candidates[i])
            continue;
        if(candidates[i] < target){
            tmp[len] = candidates[i];
            findSub(ret, tmp, returnSize, returnColumnSizes, target - candidates[i], candidates, i + 1, end, len+1);
        }else if(candidates[i] == target){
            ret[*returnSize] = (int*)malloc(sizeof(int)*(len + 1));
            memcpy(ret[*returnSize], tmp, len*sizeof(int));
            ret[*returnSize][len] = target;
            returnColumnSizes[(*returnSize)++] = len + 1;
            return;
        }else
            return;
    }
}

#define NUM_SIZE (200)
int** combinationSum2(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    *returnSize = 0;
    if(candidates == NULL || candidatesSize == 0)
        return NULL;

    // int** ret = (int**)malloc(sizeof(int*)*candidatesSize);
    // *returnColumnSizes = (int*)calloc(candidatesSize, sizeof(int));
    int** ret = (int**)malloc(sizeof(int*)*NUM_SIZE);
    *returnColumnSizes = (int*)calloc(NUM_SIZE, sizeof(int));


    qsort(candidates, candidatesSize, sizeof(int), compare);
    //found the number which equal to target
    int end = candidatesSize - 1;
    bool find = false;
    for(;end >= 0; end--){
        if(candidates[end] < target)
            break;
        else if(candidates[end] == target){
            if(find == true)
                continue;
            find = true;
            ret[(*returnSize)] = (int*)malloc(sizeof(int));
            ret[(*returnSize)][0] = target;
            *((*returnColumnSizes) + (*returnSize)) = 1;
            (*returnSize)++;
        }
    }

    if(end < 1)
        return ret;

    int* tmp = (int*)malloc(sizeof(int)*(end + 1));
    tmp[0] = candidates[0];

    findSub(ret, tmp, returnSize, *returnColumnSizes, target - candidates[0], candidates, 1, end, 1);


    for(int i = 1; i < end; i++){
        if(candidates[i] == candidates[i - 1])
            continue;
        tmp[0] = candidates[i];
        findSub(ret, tmp, returnSize, *returnColumnSizes, target - candidates[i], candidates, i + 1, end, 1);
    }

    free(tmp);

    if(*returnSize)
        return ret;
    else{
        free(ret);
        free(*returnColumnSizes);
    }
    return NULL;
}
