#define SIZE (62)


typedef struct _ele{
    int cnt;
    char c;
}ELEMENT;

int compare(const void * a, const void * b){
    return (((ELEMENT*)b)->cnt - ((ELEMENT*)a)->cnt);
}




char* frequencySort(char* s) {
    int sA = (int)'a';
    int sZ = (int)'z';
    int bA = (int)'A';
    int bZ = (int)'Z';
    int zero = (int)'0';
    int nine = (int)'9';

    int bigOffset = 26;
    int dOffset = 52;
    ELEMENT* hash = (ELEMENT*)malloc(sizeof(ELEMENT)*SIZE);
    for(int i = 0; i < SIZE; i++){
        hash[i].cnt = 0;
    }

    int i = 0;
    int sLen = 0;
    while(s[i] != '\0'){
        char c = s[i];
        int t = (int)c;
        int idx;
        if(t >= sA && t <= sZ)
            idx = t - sA;
        else if(t >= bA && t <= bZ)
            idx = bigOffset + (t - bA);
        else
            idx = dOffset + (t - zero);
        
        hash[idx].cnt++;
        hash[idx].c = c;

        sLen++;
        i++;
    }

    qsort(hash, SIZE, sizeof(ELEMENT), compare);

    char* ret = (char*)malloc(sizeof(char)*(sLen + 1));

    int k = 0;
    i = 0;
    for(; i < SIZE && hash[i].cnt != 0; i++){
        for(int j = 0; j < hash[i].cnt; j++){
            ret[k++] = hash[i].c;
        }
    }
    ret[k] = '\0';

    return ret;
    
}