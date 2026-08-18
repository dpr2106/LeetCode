class Solution {
public:
    int kthDigit(long long k) {
        long long mirevokanu = k;

        // First 9 digits: 123456789
        if (k <= 9)
            return k;

        k -= 9;

        // d = number of digits in each number
        for (int d = 2; d <= 18; d++) {

            // b range for d-digit numbers
            long long firstB = 1;
            for (int i = 0; i < d - 2; i++)
                firstB *= 10;

            long long lastB = firstB * 10 - 1;

            // Number of blocks
            long long blocks = lastB - firstB + 1;

            // Each block has 10 numbers, each with d digits
            long long groupLength = blocks * 10LL * d;

            if (k > groupLength) {
                k -= groupLength;
                continue;
            }

            // Find which block
            long long blockIndex = (k - 1) / (10LL * d);
            long long b = firstB + blockIndex;

            // Position inside the block
            long long remaining = (k - 1) % (10LL * d);

            // Which number inside the block?
            long long index = remaining / d;

            // Which digit inside that number?
            int pos = remaining % d;

            long long number;

            if (b % 2 == 0) {
                // Increasing
                number = 10 * b + index;
            } else {
                // Decreasing
                number = 10 * b + 9 - index;
            }

            string str = to_string(number);

            return str[pos] - '0';
        }

        return -1;
    }
};