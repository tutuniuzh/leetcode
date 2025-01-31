/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


#define SLASH (1)
#define STAR (2)
#define LENGTH (40)


char** removeComments(char** source, int sourceSize, int* returnSize) {

    int top = 0;
    *returnSize = 0;
    int curState = 0;
    int idx = 0;
    int k = 0;
    char** ret = (char**)malloc(sizeof(char*)*sourceSize);
    for(int i = 0; i < sourceSize; i++){
        int j = 0;
        if(curState != STAR){
            idx = 0;
            k = 0;
        }
        while(source[i][j] != '\0'){
            char c = source[i][j];
            if(curState == SLASH){
                // if(c == '/'){
                //     j++;
                //     if(source[i][j] == '*')
                //         curState = STAR;
                //     else if(source[i][j] == '\0')
                //         break;
                // }
                j++;
            }else if(curState == STAR){
                j++;
                if(c == '*' && source[i][j] == '/'){
                    curState = 0;
                    j++;
                }
            }else{
                if(c == '/'){
                    char next = source[i][j + 1];
                    if(next == '/'){
                        curState = SLASH;
                        j += 2;
                        continue;
                    }
                    else if(next == '*'){
                        curState = STAR;
                        j += 2;
                        continue;
                    }
                }
                if(idx == 0){
                    k = (*returnSize)++;
                    ret[k] = (char*)calloc(LENGTH, sizeof(char));
                }
                ret[k][idx++] = c;
                j++;
            }
        }
        // if(curState == 0 && idx)
        //     ret[k][idx++] = '\0';
        
        if(curState == SLASH)
            curState = 0;
    }

    return ret;
}