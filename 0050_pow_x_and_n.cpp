class Solution {
public:
    double myPow(double x, int n) {
        long long nn = n; // Use long long to prevent overflow when n = -2147483648
        
        // If power is negative, make it positive and invert x
        if (nn < 0) {
            nn = -nn;
            x = 1.0 / x;
        }
        
        double ans = 1.0;
        while (nn > 0) {
            // If power is odd, multiply ans by x and reduce power by 1
            if (nn % 2 == 1) {
                ans = ans * x;
                nn = nn - 1;
            } else {
                // If power is even, square x and halve the power
                x = x * x;
                nn = nn / 2;
            }
        }
        
        return ans;
    }
};
