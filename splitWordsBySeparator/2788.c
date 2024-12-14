/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define NUM_SIZE (1000)
char** splitWordsBySeparator(char** words, int wordsSize, char separator, int* returnSize) {
    *returnSize = 0;
    if(words == NULL || wordsSize == 0)
        return NULL;
    int idx = 0;
    char** ret = (char**)malloc(sizeof(char*)*NUM_SIZE);
    while(wordsSize != idx){
        char* s = words[idx++];
        int i = 0;
        int start = 0;
        int end = 0;
        while(s[i] != '\0'){
            if(s[i++] != separator){
                end++;
            }else{
                int sLen = end - start;
                if(sLen > 0){
                    char* copy = (char*)malloc(sizeof(char)*sLen+1);
                    strncpy(copy, &s[start], sLen);
                    copy[sLen] = '\0';
                    ret[(*returnSize)++] = copy;
                }
                start = i;
                end = start;
            }
        }
        int sLen = end - start;
        if(sLen > 0){
            char* copy = (char*)malloc(sizeof(char)*sLen+1);
            strncpy(copy, &s[start], sLen);
            copy[sLen] = '\0';
            ret[(*returnSize)++] = copy;
        }
    }
    return ret;
}