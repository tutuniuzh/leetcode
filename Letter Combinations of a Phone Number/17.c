void combine(char* digits, const char** map, int* nums, int cur, char ** ret, int len, int loop){
    if(digits[cur] == '\0'){
        for(int i = 0; i < len; i++){
            ret[i][cur] = '\0';
        }
        return;
    }
    int idx = (int)(digits[cur] - '0');
    for(int i = 0, k = 0; i < len; ){
        for(int j = 0; j < loop; j++, i++){
            ret[i][cur] = map[idx][k];
        }
        if(k == nums[idx] - 1)
            k = 0;
        else
            k++;
    }

    cur++;
    if(loop == 1){
        for(int i = 0; i < len; i++){
            ret[i][cur] = '\0';
        }
    }else
        combine(digits, map, nums, cur, ret, len, loop/nums[(int)(digits[cur] - '0')]);
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char** letterCombinations(char* digits, int* returnSize) {

    if(digits == NULL)
        return NULL;

    const char* map[10];

    map[0] = "";
    map[1] = "";
    map[2] = "abc";
    map[3] = "def";
    map[4] = "ghi";
    map[5] = "jkl";
    map[6] = "mno";
    map[7] = "pqrs";
    map[8] = "tuv";
    map[9] = "wxyz";

    int nums[10];
    nums[0] = 0;
    nums[1] = 0;
    nums[2] = 3;
    nums[3] = 3;
    nums[4] = 3;
    nums[5] = 3;
    nums[6] = 3;
    nums[7] = 4;
    nums[8] = 3;
    nums[9] = 4;

    //first calculate the possibility
    int i = 0;
    int len = 1;
    while(digits[i] != '\0'){
        //range is from '2' to '9', no need to concern about the '0' and '1'
        len *= nums[(int)(digits[i] - '0')];
        i++;
    }
    
    char** ret = (char**)malloc(sizeof(char*)*len);
    *returnSize = len;
    if(len == 1){
        *returnSize = 0;
        return NULL;
        // ret[0] = "";
        // return ret;
    }


    for(int j; j < (*returnSize); j++){
        ret[j] = (char*)malloc(sizeof(int)*(i + 1));
    }
    combine(digits, map, nums, 0, ret, (*returnSize), (*returnSize)/nums[(int)(digits[0] - '0')]);
    return ret;
    
}