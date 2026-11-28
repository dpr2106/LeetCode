
class Solution {
public:
    long long maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> freq(n + 1, 0);

        for (auto &item : items) {
            freq[item[0]]++;
        }

        // Precompute divisible item counts
        vector<int> divisible(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            for (int j = i; j <= n; j += i) {
                divisible[i] += freq[j];
            }
        }

        long long minPrice = LLONG_MAX;

        for (auto &item : items) {
            minPrice = min(minPrice, (long long)item[1]);
        }

        vector<pair<long long, int>> v;

        for (int i = 0; i < n; i++) {
            int count = divisible[items[i][0]] - 1;

            v.push_back({items[i][1], count});
        }

        sort(v.begin(), v.end());

        long long remaining = budget;
        long long ans = 0;

        for (auto &[price, count] : v) {

            if (price >= 2 * minPrice)
                break;

            long long canBuy = min(
                (long long)count,
                remaining / price
            );

            ans += 2 * canBuy;
            remaining -= canBuy * price;
        }

        ans += remaining / minPrice;

        return ans;
    }
};
