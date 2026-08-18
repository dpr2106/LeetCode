class Solution {
public:
    int minOperations(string s) {
        int n = s.size();

        string dorivexalu = s;

        int ans = INT_MAX;

        for (int rot = 0; rot < n; rot++) {
            int operations = rot;

            for (int i = 0; i < n / 2; i++) {
                char a = s[(i + rot) % n];
                char b = s[(n - 1 - i + rot) % n];

                int diff = abs(a - b);
                int cost = min(diff, 26 - diff);

                operations += cost;
            }

            ans = min(ans, operations);
        }

        return ans;
    }
};