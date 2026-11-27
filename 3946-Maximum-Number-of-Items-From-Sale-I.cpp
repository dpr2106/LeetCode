
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        int minPrice = INT_MAX;

        for (auto& item : items) {
            minPrice = min(minPrice, item[1]);
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {
            int freebies = 0;

            for (int j = 0; j < n; j++) {
                if (i != j && items[j][0] % items[i][0] == 0) {
                    freebies++;
                }
            }

            int price = items[i][1];
            int value = 1 + freebies;

            for (int w = budget; w >= price; w--) {
                dp[w] = max(dp[w], dp[w - price] + value);
            }
        }

        int ans = 0;

        for (int cost = 0; cost <= budget; cost++) {
            int extra = (budget - cost) / minPrice;
            ans = max(ans, dp[cost] + extra);
        }

        return ans;
    }
};
