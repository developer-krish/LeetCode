class Solution {
public:
    int func(int m, int n, vector<vector<int>>& nums, vector<vector<int>>& dp)
    {
        if(m == 0 && n == 0) return 1;
        if(m < 0 || n < 0) return 0;
        if(nums[m][n] == 1) return 0;
        if(dp[m][n] != -1) return dp[m][n];
        int up = func(m - 1, n, nums, dp);
        int left = func(m, n - 1, nums, dp);
    
        return dp[m][n] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) 
    {
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        if (obstacleGrid[0][0] == 1) return 0;
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return func(m - 1, n - 1, obstacleGrid, dp);
    }
};