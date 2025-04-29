class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) 
    {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        dp[0][0] = grid[0][0];
        for(int i = 0 ; i < m ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                if (i == 0 && j == 0) continue;
                int up = i > 0 ? dp[i - 1][j] : INT_MAX;
                int left = j > 0 ? dp[i][j - 1] : INT_MAX;
                dp[i][j] = grid[i][j] + min(up, left);
            }
        }
        return dp[m - 1][n - 1];
    }
};

// ***memo ****
// class Solution {
// public:
//     int func(int m, int n, vector<vector<int>>& nums, vector<vector<int>>& dp)
//     {
//         if(m == 0 && n == 0) return nums[0][0];
//         if(m < 0 || n < 0) return INT_MAX;
//         if(dp[m][n] != -1) return dp[m][n];
//         int up = func(m - 1, n, nums, dp);
//         int left = func(m, n - 1, nums, dp);
//         return dp[m][n] = nums[m][n] + min(up, left);
//     }
//     int minPathSum(vector<vector<int>>& grid) 
//     {
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<vector<int>> dp(m, vector<int>(n, -1));
//         return func(m - 1, n - 1, grid, dp);
//     }
// };