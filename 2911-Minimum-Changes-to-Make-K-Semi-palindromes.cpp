
class Solution {
public:
    int minimumChanges(string s, int k) {
        int n = s.size();

        vector<vector<int>> cost(n, vector<int>(n, 0));

        // Precompute minimum changes for every substring
        for (int l = 0; l < n; l++) {
            for (int r = l + 1; r < n; r++) {

                int len = r - l + 1;
                int best = INT_MAX;

                for (int d = 1; d < len; d++) {
                    if (len % d != 0)
                        continue;

                    int changes = 0;
                    int groupSize = len / d;

                    for (int offset = 0; offset < d; offset++) {
                        for (int t = 0; t < groupSize / 2; t++) {

                            int i = l + offset + t * d;

                            int j = l + offset +
                                    (groupSize - 1 - t) * d;

                            if (s[i] != s[j])
                                changes++;
                        }
                    }

                    best = min(best, changes);
                }

                cost[l][r] = best;
            }
        }

        // DP: partition string into exactly k substrings
        const int INF = 1e9;

        vector<vector<int>> dp(
            k + 1, vector<int>(n + 1, INF)
        );

        dp[0][0] = 0;

        for (int p = 1; p <= k; p++) {
            for (int i = 2 * p; i <= n; i++) {

                for (int j = 2 * (p - 1); j <= i - 2; j++) {

                    dp[p][i] = min(
                        dp[p][i],
                        dp[p - 1][j] + cost[j][i - 1]
                    );
                }
            }
        }

        return dp[k][n];
    }
};
