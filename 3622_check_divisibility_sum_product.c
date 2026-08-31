bool checkDivisibility(int n) {
    int sum = 0;
    int product = 1;
    int num = n;
    while(num>0){
        int rem = num%10;
        sum = sum + rem;
        product = product * rem;
        num = num / 10;
    }
    int sum_real = sum + product;

    if(n%sum_real == 0){
        return true;
    }
    return false;
}