class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int, int> subarray_count;
        int n = nums.size();
        
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> unique_in_window;
            
            for (int j = i; j < i + k; j++) {
                unique_in_window.insert(nums[j]);
            }
            
            for (int num : unique_in_window) {
                subarray_count[num]++;
            }
        }
        
        int max_val = -1;
        for (auto const& [num, count] : subarray_count) {
            if (count == 1) {
                max_val = max(max_val, num);
            }
        }
        
        return max_val;
    }
};
