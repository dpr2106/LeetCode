
class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> nxt(n, n), st;

        // Next strictly greater element
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.back()] <= nums[i])
                st.pop_back();

            if (!st.empty())
                nxt[i] = st.back();

            st.push_back(i);
        }

        int LOG = 1;
        while ((1 << LOG) <= n)
            LOG++;

        vector<vector<int>> up(LOG, vector<int>(n + 1, n));
        vector<vector<long long>> sum(
            LOG, vector<long long>(n + 1, 0)
        );

        // Binary lifting preprocessing
        for (int i = 0; i < n; i++) {
            up[0][i] = nxt[i];
            sum[0][i] = 1LL * nums[i] * (nxt[i] - i);
        }

        for (int j = 1; j < LOG; j++) {
            for (int i = 0; i <= n; i++) {
                int mid = up[j - 1][i];

                up[j][i] = up[j - 1][mid];
                sum[j][i] = sum[j - 1][i] + sum[j - 1][mid];
            }
        }

        // Prefix sums
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + nums[i];

        // Minimum operations for subarray [l, r]
        auto getCost = [&](int l, int r) -> long long {
            int p = l;
            long long mxSum = 0;

            for (int j = LOG - 1; j >= 0; j--) {
                int nxtPos = up[j][p];

                if (nxtPos <= r + 1) {
                    mxSum += sum[j][p];
                    p = nxtPos;
                }
            }

            if (p <= r) {
                mxSum += 1LL * nums[p] * (r - p + 1);
            }

            return mxSum - (pref[r + 1] - pref[l]);
        };

        // Sliding window using binary search
        long long ans = 0;

        for (int r = 0; r < n; r++) {
            int lo = 0, hi = r;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (getCost(mid, r) <= k)
                    hi = mid;
                else
                    lo = mid + 1;
            }

            ans += r - lo + 1;
        }

        return ans;
    }
};
