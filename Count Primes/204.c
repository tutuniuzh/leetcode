#define SIZE (5000001)
int countPrimes(int n) {

    bool hash[SIZE] = {0};
    
    if(n <= 2)
        return 0;
    if(n <= 3)
        return 1;
    if(n <= 5)
        return 2;
    // if(n <= 7)
    //     return 3;
    // if(n < 11)
    //     return 4;


    //subtract the even number
    int num = n/2;

    for(int i = 3; i*i < n; i+=2){
        //i + i will generate even number, wrong result
        //i + 2*i will generate 3*i, reduntant step
        int check = i*i;
        if( !hash[i]){
            do{
                if(!hash[check]){
                    hash[check] = true;
                    num--;
                }
                //check += i will generate even number
                check += 2*i;
            }while(check < n);
        }
    }

    return num;
}