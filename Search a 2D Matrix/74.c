bool biSearch(int* nums, int start, int end, int target){
    if(start > end)
        return false;

    if(start == end){
        if(nums[start] == target)
            return true;
        else
            return false;
    }else{
        int mid = (start + end) / 2;
        if(nums[mid] == target)
            return true;
        if(nums[mid] > target)
            return biSearch(nums, start, mid - 1, target);
        else
            return biSearch(nums, mid + 1, end, target);
    }
}

bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target) {
    if(matrix == NULL || matrixSize == 0 || matrixColSize[0] == 0)
        return false;
    if(matrixSize == 1 && matrixColSize[0] == 1)
        if(matrix[0][0] == target)
            return true;
        else
            return false;
    
    if(matrixSize == 1)
        return biSearch(matrix[0], 0, matrixColSize[0] - 1, target);
    else if(matrixColSize[0] == 1){
        int start = 0;
        int end = matrixSize - 1;
        while(start <= end){
            int mid = (start + end) / 2;
            if(matrix[mid][0] == target)
                return true;
            else if (matrix[mid][0] > target)
                end = mid - 1;
            else
                start = mid + 1;
        }
        return false;
    }

    //find row
    int start = 0;
    int end = matrixSize - 1;
    while(start <= end){
        int mid = (start + end) / 2;
        if(matrix[mid][0] == target)
            return true;
        else if (matrix[mid][0] > target)
            end = mid - 1;
        else{
            if(matrix[mid][matrixColSize[0] - 1] < target)
                start = mid + 1;
            else if(matrix[mid][matrixColSize[0] - 1] == target)
                return true;
            else{
                if(matrixColSize[0] < 2)
                    return false;
                return biSearch(matrix[mid], 1, matrixColSize[0] - 2, target);
            }
        }
    }
    return false;
    
}