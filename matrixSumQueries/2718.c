#define ROWTYPE (0)
#define COLTYPE (1)


long long matrixSumQueries(int n, int** queries, int queriesSize, int* queriesColSize) {
    if(n == 0 || queries == NULL || queriesSize == 0)
        return 0;
    int* col = (int*)calloc(n,sizeof(int));
    int* row = (int*)calloc(n,sizeof(int));
    int count = queriesSize - 1;
    int leftCol = n;
    int leftRow = n;

    //check last one
    if(queries[count][0] == ROWTYPE){
        row[queries[count][1]] = 1;
        leftRow--;
    }else{
        col[queries[count][1]] = 1;
        leftCol--;
    }
    long long sum = n*queries[count][2];
    count--;
    
    while((leftCol || leftRow) && count > -1){
        if(queries[count][0] == ROWTYPE){
            if(row[queries[count][1]] == 0){
                row[queries[count][1]] = 1;
                sum += leftCol*queries[count][2];
                leftRow--;
            }
        }else{
            if(col[queries[count][1]] == 0){
                col[queries[count][1]] = 1;
                sum += leftRow*queries[count][2];
                leftCol--;
            }
        }
        count--;
    }
    return sum;
}