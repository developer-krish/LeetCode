class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) 
    {
        int n = triangle.size();
        vector<vector<int>>dp(n+1, vector<int>(n, 0));
        for(int j = 0 ; j < n ; j++)
           dp[n-1][j] = triangle[n-1][j];
        for(int i = n - 2 ; i >= 0 ; i--)
        {
            for(int j = 0 ; j < triangle[i].size() ; j++)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int downDia = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, downDia);
            }
        }
        return dp[0][0];
    }
};


// ***memo***
// class Solution {
// public:
//     int func(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& dp)
//     {
//         int n = nums.size();
//         if(i == n - 1) return nums[i][j];
//         if(dp[i][j] != -1) return dp[i][j];
//         int down = nums[i][j] + func(i+1, j, nums, dp);
//         int downDia = nums[i][j] + func(i+1, j+1, nums, dp);
//         return dp[i][j] = min(down, downDia);
//     }
//     int minimumTotal(vector<vector<int>>& triangle) 
//     {
//         int n = triangle.size();
//         vector<vector<int>>dp(n, vector<int>(n, -1));
//         return func(0, 0, triangle, dp);
//     }
// };