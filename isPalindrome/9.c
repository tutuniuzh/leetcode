bool isPalindrome(int x) {
    if(x < 0)
        return false;
    if(x < 10)
        return true;
    int arr[10];
    int start, end;
    start = 0;
    end = 0;
    do{
        arr[end++] = x % 10;
        x = x/10;
    }while(x);
    end--;
    while(start < end){
        if(arr[end--] != arr[start++])
            return false;
    }
    return true;
}


//another way is reverse the x and then compare if it is equal to the origin number