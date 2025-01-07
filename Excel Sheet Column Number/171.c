static inline int _c2i(char c){
    return (int)c - (int)'A' + 1;
}

int titleToNumber(char* columnTitle) {
    if(columnTitle == NULL || columnTitle[0] == '\0')
        return 0;
    int sLen = strlen(columnTitle);
    int sum = _c2i(columnTitle[sLen - 1]);
    int k = 0;
    while(--sLen > 0){
        int c = _c2i(columnTitle[k++]);
        for(int i = 0; i < sLen; i++){
            c *= 26;
        }
        sum += c;
    }

    return sum;
}


// int titleToNumber(char* columnTitle) {
//      int i=0;
//     long int ans=0;
//     while(columnTitle[i]!='\0'){
//         ans=ans*26+columnTitle[i++]-64;
//     }
//     return ans;
// }

/*
This code leverages the associative property of addition to simplify the calculation. It naturally starts from the 0th position and processes sequentially without requiring the entire array length to be precomputed.
*/