int bitwiseComplement(int n) {
    long mask = 1;
    while (mask < n) {
        mask =(mask << 1) | 1;
    }
    return n ^ mask;
}