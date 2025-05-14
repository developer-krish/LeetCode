class Solution {
public:
    int minCost(int n, vector<int>& cuts) 
    {
        int c = cuts.size();
        cuts.push_back(n); // insert length of stick at end at of cuts arr
        cuts.insert(cuts.begin(), 0); // 0 at front
        sort(cuts.begin(), cuts.end()); // so we can solve them individually
        vector<vector<int>> dp(c+2, vector<int>(c+2, 0));
        for(int i = c ; i >= 1 ; i--)
        {
            for(int j = 1 ; j <= c ; j++)
            {
                if(i > j) continue;
                int mini = INT_MAX;
                for(int ind = i ; ind <= j ; ind++)
                {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][ind-1] + dp[ind+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][c];
    }
};

// memmo
// class Solution {
// public:
//     int func(int i, int j, vector<int>& nums, vector<vector<int>>& dp)
//     {
//         if(i > j) return 0;
//         int mini = INT_MAX;
//         if(dp[i][j] != -1) return dp[i][j];
//         for(int ind = i ; ind <= j ; ind++)
//         {
//             int cost = nums[j+1] - nums[i-1] + func(i, ind - 1, nums, dp) + func(ind + 1, j, nums, dp);
//             mini = min(mini, cost);
//         }
//         return dp[i][j] = mini;
//     }
//     int minCost(int n, vector<int>& cuts) 
//     {
        // int c = cuts.size();
        // cuts.push_back(n); // insert length of stick at end at of cuts arr
        // cuts.insert(cuts.begin(), 0); // 0 at front
        // sort(cuts.begin(), cuts.end()); // so we can solve them individually
        // vector<vector<int>> dp(n, vector<int>(n, -1));
//         return func(1, c, cuts, dp);
//     }
// };