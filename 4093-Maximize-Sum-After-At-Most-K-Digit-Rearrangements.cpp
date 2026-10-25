class Solution {
public:
    long long maximizeSum(vector<int>& nums, int k) {
        long long sum = 0;
        vector<int> gains;

        for(int num : nums){
            sum += num;

            string s = to_string(num);
            sort(s.begin(),s.end(), greater<char>());
            int best = stoi(s);
            gains.push_back(best - num);
        }
        sort(gains.rbegin() , gains.rend());

        for(int i = 0 ; i < min(k, (int)gains.size()); i++){
            sum += gains[i];
        }
        return sum;
    }
};