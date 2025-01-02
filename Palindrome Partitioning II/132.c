static inline int _min(int a, int b){
    return (a < b) ? a : b;
}

int minCut(char* s) {
    if(s == NULL)
        return 0;
    int sLen = strlen(s);
    if(sLen < 2)
        return 0;
    
    int* dp = (int*)malloc(sizeof(int)*(sLen + 1));
    dp[0] = -1;
    for(int i = 1; i < sLen + 1 ; i++)
        dp[i] = dp[i - 1] + 1;
    
    for(int i = 0; i < sLen; i++){
        dp[i + 1] = _min(dp[i] + 1, dp[i + 1]);

        //aba
        for(int k = 1; 
        i - k >= 0
        && i + k < sLen
        && s[i - k] == s[i + k]; 
        k++)
            dp[i + k + 1] = _min(dp[i + k + 1], dp[i - k] + 1);
        
        //abba
        for(int k = 1; 
        i - k + 1 >= 0
        && i + k < sLen
        && s[i - k + 1] == s[i + k]; k++)
            dp[i + k + 1] = _min(dp[i + k + 1], dp[i - k + 1] + 1);
    }

    int n = dp[sLen];
    free(dp);
    return n;
}

//check each pos as the middle position 