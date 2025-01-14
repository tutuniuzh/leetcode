#define SIZE (500)
int calculate(char* s) {
    if(s == NULL)
        return 0;
    int top = 0;
    int addStack[SIZE];

    int i = 0;
    int lastNum = 0;

    //remove heading space
    while(s[i] == ' '){
        i++;
    }

    do{
        lastNum = 10*lastNum + (int)(s[i] - '0');
        while(s[++i] == ' ');
        if(s[i] == '\0'){
            return lastNum;
        }
    }while(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' );


    while(s[i] != '\0'){
        char lastOp = s[i];
        while(s[++i] == ' ');
        int n = 0;
        while(s[i] != '+' && s[i] != '-' && s[i] != '*' && s[i] != '/' && s[i] != '\0'){
            n = 10*n + (int)(s[i] - '0');
            while(s[++i] == ' ');
        }
        if(lastOp == '*'){
            lastNum *= n;
        }else if(lastOp == '/'){
            lastNum /= n;
        }else if(lastOp == '+'){
            if(s[i] == '*' || s[i] == '/'){
                addStack[top++] = lastNum;
                lastNum = n;
            }else
                lastNum += n;
        }else{
            if(s[i] == '*' || s[i] == '/'){
                addStack[top++] = lastNum;
                lastNum = -n;
            }else
                lastNum -= n;
        }
    }

    i = 0;
    for(; i < top; i++)
        lastNum += addStack[i];

    return lastNum;
}