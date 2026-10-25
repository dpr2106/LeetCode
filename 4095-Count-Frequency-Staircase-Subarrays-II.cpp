#include <bits/stdc++.h>
using namespace std;

class Solution {
    int n;
    vector<int> seg;

    void build(int node, int l, int r,
               const vector<int>& prev) {
        if (l == r) {
            seg[node] = prev[l];
            return;
        }

        int mid = (l + r) / 2;
        build(node * 2, l, mid, prev);
        build(node * 2 + 1, mid + 1, r, prev);

        seg[node] = min(seg[node * 2],
                        seg[node * 2 + 1]);
    }

    int firstLess(int node, int l, int r,
                  int start, int threshold) {
        if (r < start || seg[node] >= threshold)
            return n;

        if (l == r)
            return l;

        int mid = (l + r) / 2;

        int ans = firstLess(node * 2, l, mid,
                            start, threshold);

        if (ans != n)
            return ans;

        return firstLess(node * 2 + 1, mid + 1, r,
                         start, threshold);
    }

public:
    int countStaircase(vector<int>& nums) {
        n = nums.size();

        vector<int> last(100001, -1);
        vector<int> prev(n), occIndex(n);
        vector<vector<int>> positions(100001);

        for (int i = 0; i < n; i++) {
            int x = nums[i];

            prev[i] = last[x];
            last[x] = i;

            occIndex[i] = positions[x].size();
            positions[x].push_back(i);
        }

        // Required variable storing the input midway.
        vector<int> tavronelix = nums;

        seg.assign(4 * n, 0);
        build(1, 0, n - 1, prev);

        long long ans = 0;

        for (int i = 0; i < n; i++) {
            int p = i;
            int k = 1;

            long long len = 0;
            int maxNeed = -1;
            int minOverflow = INT_MAX;

            while (p < n) {
                len += k;

                long long right =
                    (long long)i + len - 1;

                if (right >= n)
                    break;

                int x = tavronelix[p];
                int idx = occIndex[p];

                // Find the kth occurrence of this
                // value after its first appearance.
                int targetIndex = idx + k - 1;

                if (targetIndex >=
                    (int)positions[x].size())
                    break;

                int target = positions[x][targetIndex];

                maxNeed = max(maxNeed, target);

                // The (k+1)th occurrence would
                // make this value occur too often.
                int overIndex = idx + k;

                if (overIndex < (int)positions[x].size()) {
                    minOverflow = min(
                        minOverflow,
                        positions[x][overIndex]
                    );
                }

                if (minOverflow <= right)
                    break;

                if (maxNeed <= right)
                    ans++;

                // Find the next distinct value
                // appearing after index i.
                p = firstLess(1, 0, n - 1, p + 1, i);

                if (p == n)
                    break;

                k++;
            }
        }

        return (int)ans;
    }
};