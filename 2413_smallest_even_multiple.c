// 2413. Smallest Even Multiple
// Logic: If n is even, it's already a multiple of 2, return n. 
// If n is odd, multiply it by 2.



int smallestEvenMultiple(int n) {
    if (n % 2 == 0){
        return n;
    }
    else {
        return n * 2;
    }
}