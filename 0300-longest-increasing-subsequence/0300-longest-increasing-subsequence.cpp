class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
        for(int ind = n - 1 ; ind >= 0 ; ind--)
        {
            for(int prev = ind - 1 ; prev >= -1 ; prev--)
            {
                int notTake = dp[ind+1][prev+1];
                int take = 0;
                if(prev == -1 || nums[ind] > nums[prev])
                  take = 1 + dp[ind+1][ind+1];
                dp[ind][prev+1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }
};

// memo
// class Solution {
// public:
//     int func(int ind, int prev, vector<int>& nums, vector<vector<int>>& dp)
//     {
//         int n = nums.size();
//         if(ind == n) return 0;
//         int len = 0;
//         if(dp[ind][prev+1] != -1) return dp[ind][prev+1]; // prev != -1
//         len = func(ind + 1, prev, nums, dp); // notTake
//         if(prev == -1 || nums[ind] > nums[prev])
//            len = max(1 + func(ind + 1, ind, nums, dp), len); // take
//         return dp[ind][prev+1] = len;
//     }
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, -1));
//         return func(0, -1, nums, dp);   
//     }
// };