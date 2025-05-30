class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();
        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i = 2 ; i < n ; i++)
        {
            int left = cost[i] + dp[i - 1];
            int right = cost[i] + dp[i - 2];
            dp[i] = min(left, right);
        }
        return min(dp[n - 1], dp[n-2]);
    }
};

// memo
// class Solution {
// public:
//     int func(int ind, vector<int>& cost, vector<int>& dp)
//     {
//         if(ind < 0) return 0;
//         if(ind == 0 || ind == 1) return cost[ind];
        
//         if(dp[ind] != -1) return dp[ind];
//         int left = cost[ind] + func(ind - 1, cost, dp);
//         int  right = cost[ind] + func(ind - 2, cost, dp);
//         return dp[ind] = min(left, right);
//     }
//     int minCostClimbingStairs(vector<int>& cost) 
//     {
//         int n = cost.size();
//         vector<int> dp(n, -1);
//         return min(func(n - 1, cost, dp) ,func(n - 2, cost, dp));
//     }
// };