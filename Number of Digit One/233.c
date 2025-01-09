static void _calDp(int digital, int* d,  int* dp){
    if(dp[digital] == 0)
        _calDp(digital - 1, d, dp);
    else
        dp[digital + 1] = 10*dp[digital] + d[digital + 1];
        
}



int _cal1(int digital, int n, int* d, int* dp, int* num){
    if(digital == 0){
        //units place
        if(n > 0)
            return 1;
        else
            return 0;
    }

    if(dp[digital - 1] == 0)
        _calDp(digital, d, dp);

    int sum = 0;
    if(n > 0){
        if(n > 1)
            sum += n*dp[digital - 1] + d[digital];
        else{
            int tmp = digital - 1;
            sum = num[tmp];
            while(--tmp >= 0)
                sum = sum*10 + num[tmp];
            sum += dp[digital - 1] + 1;
        }
    }
    return sum;

}


int countDigitOne(int n) {
    if(n == 0)
        return 0;

    int d[10];
    d[0] = 1;
    d[1] = 10;
    d[2] = 100;
    d[3] = 1000;
    d[4] = 10000;
    d[5] = 100000;
    d[6] = 1000000;
    d[7] = 10000000;
    d[8] = 100000000;
    d[9] = 1000000000;

    int dp[10] = {0};
    /*
        1 : 0~9
        2 : 0~99
        3 : 0~999
        4 : 0~9999
    */
    dp[0] = 1;

    int number[10];

    int digital = 0;

    int sum = 0;
    while(n){
        number[digital] = n%10;
        n = n/10;
        sum += _cal1(digital, number[digital], d, dp, number);
        digital++;
    }

    return sum;
}

/*
sample code seems using a mathmatic way to solve this problem
my solution use three auxilary array, but still O(lgn) complexity
*/

// int countDigitOne(int n) {
//     if (n < 0) return 0; // Handle negative input

//     int count = 0;
//     long long factor = 1; // Represents 10^i, starting with the least significant digit

//     while (factor <= n) {
//         long long lower = n % factor;
//         long long current = (n / factor) % 10;
//         long long higher = n / (factor * 10);

//         if (current == 0) {
//             // Contribution from higher digits
//             count += higher * factor;
//         } else if (current == 1) {
//             // Contribution from higher digits + lower part + 1 for the current digit
//             count += higher * factor + lower + 1;
//         } else {
//             // Contribution from all numbers with 1 in the current position
//             count += (higher + 1) * factor;
//         }

//         factor *= 10; // Move to the next digit
//     }

//     return count;
// }