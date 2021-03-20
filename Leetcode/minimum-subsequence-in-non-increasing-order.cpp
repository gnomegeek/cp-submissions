class Solution {
   public:
    vector<int> minSubsequence(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        int sum = 0;
        for (int i = 0; i < nums.size(); i++) sum += nums[i];
        int start = -1;
        int curSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            curSum += nums[i];

            if (curSum >= sum - curSum) {
                start = i;
                break;
            }
        }
        cout << start << " ";
        vector<int> res;
        for (int i = nums.size() - 1; i >= max(start, 0); i--) {
            res.push_back(nums[i]);
        }

        return res;
    }
};