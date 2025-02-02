typedef struct _node{
    int id;
    int event;
    int size;
    struct _node* next;
}Node;

typedef struct _queue{
    Node *head;
    Node *tail;
}Queue;


int maxFreeTime(int eventTime, int* startTime, int startTimeSize, int* endTime, int endTimeSize) {

    int idx = 0;
    Queue *freeQ = (Queue*)malloc(sizeof(Queue));
    Node* node = (Node*)malloc(sizeof(Node));
    node->event = 0;
    node->id = idx++;
    node->size = startTime[0];
    node->next = NULL;
    freeQ->head = node;
    freeQ->tail = node;
    
    Node * max = node;
    Node * left = NULL;
    Node * right = NULL;

    for(int i = 1; i < startTimeSize; i++){
        node = (Node*)malloc(sizeof(Node));
        node->event = endTime[i - 1] - startTime[i - 1];
        node->size = startTime[i] - endTime[i - 1];
        node->id = idx++;
        node->next = NULL;

        if(max->size < node->size){
            max = node;
            left = freeQ->tail;
        }

        if(max == freeQ->tail)
            right = node;

        freeQ->tail->next = node;
        freeQ->tail = node;
    }

    node = (Node*)malloc(sizeof(Node));
    node->event = endTime[startTimeSize - 1] - startTime[startTimeSize - 1];
    node->id = idx++;
    node->size = eventTime - endTime[startTimeSize - 1];
    node->next = NULL;
    if(max->size < node->size){
        max = node;
        left = freeQ->tail;
        right = NULL;
    }

    if(max == freeQ->tail)
        right = node;

    freeQ->tail->next = node;
    freeQ->tail = node;

    int maxSize = max->size;

    if(left != NULL){
        maxSize = maxSize + left->size;
        int checkId1 = left->id;
        int checkId2 = max->id;
        Node* tmp = freeQ->head;
        while(tmp != NULL){
            if(max->event <= tmp->size && tmp->id != checkId1 && tmp->id != checkId2){
                maxSize = max->size + left->size + max->event;
                break;
            }
            tmp = tmp->next;
        }
    }

    int tmpSize = max->size;
    if(right != NULL){
        tmpSize = max->size + right->size;
        int checkId1 = right->id;
        int checkId2 = max->id;
        Node* tmp = freeQ->head;
        while(tmp != NULL){
            if(right->event <= tmp->size && tmp->id != checkId1 && tmp->id != checkId2){
                tmpSize = max->size + right->size + right->event;
                break;
            }
            tmp = tmp->next;
        }
    }

    if(tmpSize > maxSize)
        maxSize = tmpSize;

    Node* cur = freeQ->head;
    Node* tmp = cur;
    freeQ->head = NULL;
    freeQ->tail = NULL;
    free(freeQ);
    tmpSize = max->size;
    if(max == cur){
        cur = cur->next;
        //should not happen
        // if(cur == NULL){
        //     free(tmp);
        //     return maxSize;
        // }

        int prevFree = cur->size;

        cur = cur->next;
        free(tmp);

        while(cur != NULL){
        
            if(cur->event <= tmpSize)
                maxSize = (cur->size + prevFree + cur->event  > maxSize) ? cur->size + prevFree + cur->event : maxSize;
            else
                maxSize = (cur->size + prevFree > maxSize) ? cur->size + prevFree : maxSize;

            prevFree = cur->size;
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
    }else{
        int prevFree = cur->size;
        cur = cur->next;
        free(tmp);
        while(cur != max){        
            if(cur->event <= tmpSize)
                maxSize = (cur->size + prevFree + cur->event  > maxSize) ? cur->size + prevFree + cur->event : maxSize;
            else
                maxSize = (cur->size + prevFree > maxSize) ? cur->size + prevFree : maxSize;

            prevFree = cur->size;
            tmp = cur;
            cur = cur->next;
            free(tmp);
        }
        if(cur->next != NULL){
            tmp = cur;
            cur = cur->next;
            free(tmp);
            prevFree = cur->size;
            tmp = cur;
            cur = cur->next;
            free(tmp);
            while(cur != NULL){        
                if(cur->event <= tmpSize)
                    maxSize = (cur->size + prevFree + cur->event  > maxSize) ? cur->size + prevFree + cur->event : maxSize;
                else
                    maxSize = (cur->size + prevFree > maxSize) ? cur->size + prevFree : maxSize;

                prevFree = cur->size;
                tmp = cur;
                cur = cur->next;
                free(tmp);
            }

        }
    }

    return maxSize;
}

//time complexity is O(n), usually case will take 4 loops
//max in the first, or in the end will take 3 loops