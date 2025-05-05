class Solution {
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n, 1);
        for(int ind = 0 ; ind < n ; ind++)
        {
            for(int prev = 0 ; prev <= ind - 1 ; prev++)
            {
                if(nums[prev] < nums[ind])
                  dp[ind] = max(1 + dp[prev], dp[ind]);
            }
        }
        return *max_element(dp.begin(), dp.end());
    }
};

// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<int> next(n+1, 0);
//         vector<int> curr(n+1, 0);
//         for(int ind = n - 1 ; ind >= 0 ; ind--)
//         {
//             for(int prev = ind - 1 ; prev >= -1 ; prev--)
//             {
//                 int notTake = next[prev+1];
//                 int take = 0;
//                 if(prev == -1 || nums[ind] > nums[prev])
//                   take = 1 + next[ind+1];
//                 curr[prev+1] = max(take, notTake);
//             }
//             next = curr;
//         }
//         return next[0];
//     }
// };

// Tabulation
// class Solution {
// public:
//     int lengthOfLIS(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
//         for(int ind = n - 1 ; ind >= 0 ; ind--)
//         {
//             for(int prev = ind - 1 ; prev >= -1 ; prev--)
//             {
//                 int notTake = dp[ind+1][prev+1];
//                 int take = 0;
//                 if(prev == -1 || nums[ind] > nums[prev])
//                   take = 1 + dp[ind+1][ind+1];
//                 dp[ind][prev+1] = max(take, notTake);
//             }
//         }
//         return dp[0][0];
//     }
// };

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