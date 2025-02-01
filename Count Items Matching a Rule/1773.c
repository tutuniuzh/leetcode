#define TYPE (0)
#define COLOR (1)
#define NAME (2)


int countMatches(char*** items, int itemsSize, int* itemsColSize, char* ruleKey, char* ruleValue) {
    int sum = 0;
    char c = ruleKey[0];
    int idx;
    switch(c){
        case 't':
            idx = TYPE;
            break;
        case 'c':
            idx = COLOR;
            break;
        case 'n':
            idx = NAME;
            break;
        default:
            return -1;
    }

    for(int i = 0; i < itemsSize; i++){
        if(strcmp(items[i][idx], ruleValue) == 0)
            sum++;
    }

    return sum;

}

//a piece of cake