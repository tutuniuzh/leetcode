/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


void bfs(struct TreeNode* root, int* level, long long * arr, int up){
    if(root == NULL)
        return;

    if(up == *level)
        (*level)++;
    
    arr[up] += root->val;
    bfs(root->left, level, arr, up + 1);
    bfs(root->right, level, arr, up + 1);
}






void quickSort(int start, int end, long long* arr){
    if(start < end){
        if(end == start + 1){
            if(arr[end] < arr[start]){
                long long tmp = arr[end];
                arr[end] = arr[start];
                arr[start] = tmp;
            }
            return;
        }
        int pivot = (end - start)/2;
        long long first = arr[start];
        long long last = arr[end];
        long long mid = arr[pivot];
        if(first > last){
            if(last > mid){
                pivot = end;
            }else if(mid > first){
                pivot = start;
            }
        }else{
            if(first > mid){
                pivot = start;
            }else if(mid > last){
                pivot = end;
            }
        }

        long long tmp;

        if(pivot != end){
            tmp = arr[end];
            arr[end] = arr[pivot];
            arr[pivot] = tmp;
        }


        int i = start;
        int j = end - 1;
        while(i < j){
            while(i < j && arr[i] <= arr[end])
                i++;
            while(i < j && arr[j] >= arr[end])
                j--;
            if(i < j){
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
            }
            
        }
        tmp = arr[end];
        arr[end] = arr[i];
        arr[i] = tmp;
        quickSort(start, i-1, arr);
        quickSort(i+1, end, arr);
    }

}

long long quickSelect(int start, int end, long long* arr, int k){
    if(start < end){
        // if(end == start + 1){
        //     if(arr[end] < arr[start]){
        //         long long tmp = arr[end];
        //         arr[end] = arr[start];
        //         arr[start] = tmp;
        //     }
        //     return arr[k];
        // }
        int pivot = (end - start)/2;
        long long first = arr[start];
        long long last = arr[end];
        long long mid = arr[pivot];
        if(first > last){
            if(last > mid){
                pivot = end;
            }else if(mid > first){
                pivot = start;
            }
        }else{
            if(first > mid){
                pivot = start;
            }else if(mid > last){
                pivot = end;
            }
        }

        long long tmp;

        if(pivot != end){
            tmp = arr[end];
            arr[end] = arr[pivot];
            arr[pivot] = tmp;
        }
        //long long pivot = arr[end];

        int i = start;
        int j = end - 1;
        while(i <= j){
            while(i < end && arr[i] < arr[end])
                i++;
            while(j > -1 && arr[j] > arr[end])
                j--;
            if(i <= j){
                tmp = arr[j];
                arr[j] = arr[i];
                arr[i] = tmp;
                i++;
                j--;
            }
            
        }
        tmp = arr[end];
        arr[end] = arr[i];
        arr[i] = tmp;
        // int pos = k - 1;
        if(k == i)
            return arr[i];
        if(k < i)
            return quickSelect(start, i-1, arr, k);
        else
            return quickSelect(i+1, end, arr, k);
    }else if(start == end){
        return arr[k];
    }else
        return -1;

}


int cmp(const void *a, const void *b) {
    long long val1 = *(long long*)a;
    long long val2 = *(long long*)b;

    if (val1 == val2) return 0;

    return val1 < val2 ? 1 : -1;    
}


void swap(long long *a, long long *b)
{
    long long t = *a;
    *a = *b;
    *b = t;
}
int partition(long long *data, int l, int h)
{
    int i=l, j=l;
    long long pivot = data[h-1];
    for(j-l;j<h-1;j++) if(data[j] < pivot) swap(&data[i++], &data[j]);
    swap(&data[i], &data[h-1]);
    return i;
}
void quick_select(long long *data, int l, int h, int k)
{
    if(l+1<h)
    {
        int p = partition(data, l, h);
        if(p == k) return;
        else if(p<k) quick_select(data, p+1, h, k);
        else quick_select(data, l, p, k);
    }
}

void mergeSort(long long * arr, int start, int end){
    if(start == end)
        return;
    int mid = (end + start)/2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    int len = end - start + 1;
    long long * merge = (long long *)malloc(sizeof(long long)*(len));
    

    int i = start;
    int j = mid + 1;
    int k = 0;
    int len1 = mid - start + 1;
    int len2 = end - mid;
    while(len1 > 0 && len2 > 0){
        if(arr[j] < arr[i]){
            merge[k++] = arr[j++];
            len2--;
        }else{
            merge[k++] = arr[i++];
            len1--;
        }
    }


    if(len1)
        memcpy((void*)(&merge[k]), (void*)(&arr[i]), len1*sizeof(long long));


    memcpy((void*)(&arr[start]), (void*)merge, (len - len2)*sizeof(long long));
    free(merge);    
}

#define NUM_LEVEL (100000)
long long kthLargestLevelSum(struct TreeNode* root, int k) {
    if(root == NULL)
        return 0;
    //long long * arr = (long long *)malloc(sizeof(long long)*NUM_LEVEL);
    // for(int i = 0; i < NUM_LEVEL; i++)
    //     arr[i] = 0LL;
    
    long long arr[NUM_LEVEL] = {0};
    int level = 0;

    bfs(root, &level, arr, 0);
    if(k > level)
        return - 1;
    //return quickSelect(0, level - 1, arr, level - 1 - (k - 1));
    // mergeSort(arr, 0, level - 1);
    // return arr[level - k];
    //qsort(arr, level, sizeof(long long), cmp);
    //return arr[k - 1];

    if(k < 20){
        //find max
        long long max = 0;
        int pos;
        for(int i = 0; i < k; i++){
            for(int j = i; j < level; j++){
                if(arr[j] > max){
                    max = arr[j];
                    pos = j;
                }
            }
            arr[pos] = arr[i];
            arr[i] = max;
            max = 0;
        }
        return arr[k - 1];
    }else if((level - k) < 20){
        //find min
        k = level - k;
        long long min = 1000000;
        int pos;
        for(int i = 0; i <= k; i++){
            for(int j = i; j < level; j++){
                if(arr[j] < min){
                    min = arr[j];
                    pos = j;
                }
            }
            arr[pos] = arr[i];
            arr[i] = min;
            min = 1000000;
        }
        return arr[k];
    }else{
        return quickSelect(0, level - 1, arr, level - k);
    }    
}

// quickSelect used to the fatest solution for this problem
// however as the test case updated, some extream cases are really terriable for the quickselect
// mergeSort has a stable performance, but the best optimise algrothim would still take 200ms 
// heapsort is the best one stop solution for this problem, but it is not fast enough