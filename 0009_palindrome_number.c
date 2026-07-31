bool isPalindrome(int x) {
    long reversed = 0;
    int temp = x;
    while (temp > 0){
        int digit = temp % 10;
        reversed = (reversed * 10) + digit;
        temp = temp / 10;
    }
    if (reversed == x){
        return true;
    }
    else {
        return false;
    }
}