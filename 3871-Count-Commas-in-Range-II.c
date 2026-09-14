long long countCommas(long long n) {
    long long total_commas = 0;
    long long threshold = 1000;
    
    // While our comma threshold is within the range of n
    while (threshold <= n) {
        // Add 1 comma for every number from `threshold` up to `n`
        total_commas += (n - threshold + 1);
        
        // Jump to the next comma boundary (1,000 -> 1,000,000 -> 1,000,000,000)
        threshold *= 1000;
    }
    
    return total_commas;
}
