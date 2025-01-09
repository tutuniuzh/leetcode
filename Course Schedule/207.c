bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize) {
    bool** g = (bool**)malloc(sizeof(bool*)*numCourses);
    for(int i = 0; i < numCourses; i++)
        g[i] = (bool*)calloc(numCourses, sizeof(bool));
    int* q = (int*)malloc(sizeof(int)*numCourses);
    int* degree = (int*)calloc(numCourses, sizeof(int));

    int front = 0;
    int rear = 0;

    for(int i = 0; i < prerequisitesSize; i++){
        g[prerequisites[i][0]][prerequisites[i][1]] = true;
        degree[prerequisites[i][1]]++;
    }
    
    int sortedVertex = 0;

    for(int i = 0; i < numCourses; i++){
        if(degree[i] == 0){
            q[rear++] = i;
            sortedVertex++;
        }
    }

    while(front < rear){
        int node = q[front++];
        for(int i = 0; i < numCourses; i++){
            if(g[node][i]){
                if(--degree[i] == 0){
                    q[rear++] = i;
                    sortedVertex++;
                }
            }

        }
    }


    return (sortedVertex == numCourses);
}