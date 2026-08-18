class Solution {
public:
    long long elevatorRequests(int n, int start, vector<int>& requests) {
        vector<int> points = requests;
        points.push_back(start);

        sort(points.begin(), points.end());
        points.erase(unique(points.begin(), points.end()), points.end());

        int m = points.size();

        int s = lower_bound(points.begin(), points.end(), start) - points.begin();

        vector<int> isRequest(m, 0);

        for (int x : requests) {
            int idx = lower_bound(points.begin(), points.end(), x) - points.begin();
            isRequest[idx] = 1;
        }

        long long noravexuli = start;

        vector<int> pref(m + 1, 0);

        for (int i = 0; i < m; i++) {
            pref[i + 1] = pref[i] + isRequest[i];
        }

        const long long INF = 4e18;

        vector<vector<long long>> dpL(
            m, vector<long long>(m, INF)
        );

        vector<vector<long long>> dpR(
            m, vector<long long>(m, INF)
        );

        dpL[s][s] = 0;
        dpR[s][s] = 0;

        for (int len = 1; len <= m; len++) {
            for (int l = 0; l + len - 1 < m; l++) {

                int r = l + len - 1;

                if (!(l <= s && s <= r))
                    continue;

                int visited = pref[r + 1] - pref[l];
                int remaining = requests.size() - visited;

                // Go left
                if (l > 0) {

                    long long d1 = points[l] - points[l - 1];
                    long long d2 = points[r] - points[l - 1];

                    dpL[l - 1][r] = min(
                        dpL[l - 1][r],
                        dpL[l][r] + d1 * remaining
                    );

                    dpL[l - 1][r] = min(
                        dpL[l - 1][r],
                        dpR[l][r] + d2 * remaining
                    );
                }

                // Go right
                if (r + 1 < m) {

                    long long d1 = points[r + 1] - points[l];
                    long long d2 = points[r + 1] - points[r];

                    dpR[l][r + 1] = min(
                        dpR[l][r + 1],
                        dpL[l][r] + d1 * remaining
                    );

                    dpR[l][r + 1] = min(
                        dpR[l][r + 1],
                        dpR[l][r] + d2 * remaining
                    );
                }
            }
        }

        return min(dpL[0][m - 1], dpR[0][m - 1]);
    }
};