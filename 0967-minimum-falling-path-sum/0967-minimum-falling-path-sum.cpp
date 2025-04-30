class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) 
    {
        int n = matrix.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int j = 0 ; j < n ; j++)
           dp[0][j] = matrix[0][j];
        for(int i = 1 ; i < n ; i++)
        {
            for(int j = 0 ; j < n ; j++)
            {
                int down = matrix[i][j] + dp[i-1][j];
                int downLeft = INT_MAX;
                int downRight = INT_MAX;
                if(j - 1 >= 0) downLeft = matrix[i][j] + dp[i-1][j-1];
                if(j + 1 < n) downRight = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = min({down, downLeft, downRight});
            }
        }
        return *min_element(dp[n-1].begin(), dp[n-1].end());
    }
};

// memo (TLE)
// class Solution {
// public:
//     int func(int i, int j, vector<vector<int>>& nums, vector<vector<int>>& dp) {
//         int n = nums.size();
//         if (j < 0 || j >= n) return 1e9; // out of bounds
//         if (i == n - 1) return nums[i][j]; // base case: bottom row
//         if (dp[i][j] != -1) return dp[i][j];

//         int down = nums[i][j] + func(i + 1, j, nums, dp);
//         int downLeft = nums[i][j] + func(i + 1, j - 1, nums, dp);
//         int downRight = nums[i][j] + func(i + 1, j + 1, nums, dp);

//         return dp[i][j] = min({down, downLeft, downRight});
//     }

//     int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n = matrix.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1));
//         int minSum = INT_MAX;

//         for (int j = 0; j < n; j++) {
//             minSum = min(minSum, func(0, j, matrix, dp));
//         }
//         return minSum;
//     }
// };