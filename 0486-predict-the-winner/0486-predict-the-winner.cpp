class Solution {
public:
    bool predictTheWinner(vector<int>& nums) 
    {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
         for (int i = 0; i < n; ++i) {
            dp[i][i] = nums[i];
        }
        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                int left = nums[i] - dp[i + 1][j];
                int right = nums[j] - dp[i][j - 1];
                dp[i][j] = max(left, right);
            }
        }
        return dp[0][n-1] >= 0;
    }
};

// class Solution {
// public:
//     int func(vector<int>& nums, int i, int j, vector<vector<int>>& dp)
//     {
//         if(i > j) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         int left = nums[i] - func(nums, i + 1, j, dp);
//         int right = nums[j] - func(nums, i, j - 1, dp);
//         return dp[i][j] = max(left, right);
//     }
//     bool predictTheWinner(vector<int>& nums) 
//     {
//         int n = nums.size();
//         vector<vector<int>> dp(n, vector<int>(n, -1));
//         return func(nums, 0, n - 1, dp) >= 0;
//     }
// };