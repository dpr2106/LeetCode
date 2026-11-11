
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,
                          int need1, int need2) {

        long long separate = 1LL * need1 * cost1
                           + 1LL * need2 * cost2;

        long long allBoth = 1LL * max(need1, need2) * costBoth;

        long long mixed = 1LL * min(need1, need2) * costBoth;

        if (need1 > need2)
            mixed += 1LL * (need1 - need2) * cost1;
        else
            mixed += 1LL * (need2 - need1) * cost2;

        return min({separate, allBoth, mixed});
    }
};
