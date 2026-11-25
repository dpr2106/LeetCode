#include <vector>
#include <unordered_map>
#include <chrono>
#include <random>
#include <cstdint>
using namespace std;

class Solution {
public:
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        const uint64_t M1 = 1000000007ULL, M2 = 998244353ULL;

        mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
        uint64_t B1 = rng() % (M1 - 1000) + 500;
        uint64_t B2 = rng() % (M2 - 1000) + 500;

        vector<uint64_t> h1(n + 1, 0), h2(n + 1, 0), p1(n + 1, 1), p2(n + 1, 1);
        for (int i = 0; i < n; i++) {
            h1[i + 1] = (h1[i] * B1 + nums[i]) % M1;
            h2[i + 1] = (h2[i] * B2 + nums[i]) % M2;
            p1[i + 1] = p1[i] * B1 % M1;
            p2[i + 1] = p2[i] * B2 % M2;
        }

        auto hasUniqueWindow = [&](int L) -> bool {
            unordered_map<uint64_t, int> cnt;
            cnt.reserve(n * 2);
            for (int i = 0; i + L <= n; i++) {
                uint64_t a = (h1[i + L] + M1 - h1[i] * p1[L] % M1) % M1;
                uint64_t b = (h2[i + L] + M2 - h2[i] * p2[L] % M2) % M2;
                cnt[(a << 32) | b]++;
            }
            for (auto& [k, v] : cnt) {
                if (v == 1) return true;
            }
            return false;
        };

        int lo = 1, hi = n;
        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;
            if (hasUniqueWindow(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};