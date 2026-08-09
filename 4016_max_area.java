public class Solution {
    public int maxArea(int[][] mat) {
        int m = mat.length, n = mat[0].length;
        int[][] dp = new int[m][n];

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (mat[i][j] == 1) {
                    if (i == 0 || j == 0) {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = 1 + Math.min(dp[i-1][j],
                                     Math.min(dp[i][j-1], dp[i-1][j-1]));
                    }
                } else {
                    dp[i][j] = 0;
                }
            }
        }

        int low = 1, high = Math.min(m, n), best = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (feasible(dp, m, n, mid)) {
                best = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return best * best;
    }

    private boolean feasible(int[][] dp, int m, int n, int k) {
        int minI = Integer.MAX_VALUE, maxI = -1;
        int minJ = Integer.MAX_VALUE, maxJ = -1;

        for (int i = k - 1; i < m; i++) {
            for (int j = k - 1; j < n; j++) {
                if (dp[i][j] >= k) {
                    if (i < minI) minI = i;
                    if (i > maxI) maxI = i;
                    if (j < minJ) minJ = j;
                    if (j > maxJ) maxJ = j;
                }
            }
        }

        if (maxI == -1) return false; // no valid k x k square exists at all

        return (maxI - minI >= k) || (maxJ - minJ >= k);
    }
}