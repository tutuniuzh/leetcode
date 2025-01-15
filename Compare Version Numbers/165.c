int compareVersion(char* version1, char* version2) {

    int sLen1 = 0;
    int sLen2 = 0;
    int n1 = 0;
    int n2 = 0;
    int len1 = 0;
    int len2 = 0;

    //get first integer 
    while(version1[sLen1] != '\0' && version1[sLen1] != '.')
        n1 = n1*10 + (int)(version1[sLen1++] - '0');

    while(version2[sLen2] != '\0' && version2[sLen2] != '.')
        n2 = n2*10 + (int)(version2[sLen2++] - '0');
    

    if(n1 > n2)
        return 1;
    else if(n1 < n2)
        return -1;

    int v1[200] = {0};
    while(version1[sLen1] != '\0'){
        sLen1++;
        n1 = 0;
        while(version1[sLen1] != '.' && version1[sLen1] != '\0')
            n1 = n1*10 + (int)(version1[sLen1++] - '0');
        v1[len1++] = n1;
    }


    while(version2[sLen2] != '\0'){
        sLen2++;
        n2 = 0;
        while(version2[sLen2] != '.' && version2[sLen2] != '\0')
            n2 = n2*10 + (int)(version2[sLen2++] - '0');
        if(len2 < len1){
            if(v1[len2] > n2)
                return 1;
            else if(v1[len2] < n2)
                return -1;
            len2++;
        }else if(n2)
            return -1;
    }

    while(len2 < len1){
        if(v1[len2++])
            return 1;
    }
    
    return 0;
    
}



/*
sample code is more straight forward. 
*/

// int compareVersion(char* version1, char* version2) {
//     int i = 0;
//     int j = 0;
//     while(i<strlen(version1) || j<strlen(version2)){
//         int block1 = 0;
//         int block2 = 0;
//         while(i<strlen(version1) && version1[i]!='.'){
//             block1 = block1*10 + (version1[i]-'0');
//             i++;
//         }
//         while(j<strlen(version2) && version2[j]!='.'){
//             block2 = block2*10 + (version2[j]-'0');
//             j++;
//         }
//         if (block1<block2){
//             return -1;
//         }
//         else if(block1>block2){
//             return 1;
//         }
//         i++;
//         j++;
//     }
//     return 0;
    
// }