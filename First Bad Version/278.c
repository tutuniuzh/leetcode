// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

int firstBadVersion(int n) {
    long long start = 0;
    long long  end = n;
    int lastBad = n;
    while(start <= end){
        long long  mid = (start + end ) / 2;
        if(isBadVersion(mid)){
            lastBad = mid;
            end = mid - 1;
        }
        else{
            start = mid + 1;
        }
    }

    return lastBad;
    
}