class Solution {
public:
    long long climbStairs(int n, vector<int>& costs) {
        long long dp_i_3 = 0; // Represents dp[i-3]
        long long dp_i_2 = 0; // Represents dp[i-2]
        long long dp_i_1 = 0; // Represents dp[i-1]
        long long dp_i = 0;   // Represents dp[i]
        
        for (int i = 1; i <= n; ++i) {
            long long cost1 = dp_i_1 + costs[i - 1] + 1; 
            long long cost2 = (i >= 2) ? dp_i_2 + costs[i - 1] + 4 : 1e18; 
            long long cost3 = (i >= 3) ? dp_i_3 + costs[i - 1] + 9 : 1e18; 
            
            dp_i = min({cost1, cost2, cost3});
            
            dp_i_3 = dp_i_2;
            dp_i_2 = dp_i_1;
            dp_i_1 = dp_i;
        }
        
        return dp_i;
    }
};