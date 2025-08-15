class Solution {
public:
    int func(vector<int>& nums, int target, vector<int>& dp)
    {
        if(target == 0) return 1;
        if(target < 0) return 0;
        if(dp[target] != -1) return dp[target];
        int count = 0;
        for(int num : nums)
        {
            count += func(nums, target - num, dp);
        }
        return dp[target] = count;
    }
    int combinationSum4(vector<int>& nums, int target) 
    {
        vector<int> dp(target + 1, -1);
        return func(nums, target, dp);
    }
};