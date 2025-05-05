class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) 
    {
        int n = prices.size();
        vector<int> after(2, 0);
        vector<int> curr(2, 0);
        for(int ind = n-1 ; ind >= 0 ; ind--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                int profit = 0;
                if(buy)
                   profit = max(-prices[ind] + after[0], after[1]);
                else
                   profit = max(prices[ind] + after[1] - fee, after[0]);
                curr[buy] = profit;
            }
            after = curr;
        }
        return after[1];
    }
    
};

// Tabulation
// class Solution {
// public:
//     int maxProfit(vector<int>& prices, int fee) 
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int>(2, 0));
//         for(int ind = n-1 ; ind >= 0 ; ind--)
//         {
//             for(int buy = 0 ; buy <= 1 ; buy++)
//             {
//                 int profit = 0;
//                 if(buy)
//                    profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
//                 else
//                    profit = max(prices[ind] + dp[ind+1][1] - fee, dp[ind+1][0]);
//                 dp[ind][buy] = profit;
//             }
//         }
//         return dp[0][1];
//     }
// };

// memo
// class Solution {
// public:
//     int func(int ind, int buy, int fee, vector<int>& prices, vector<vector<int>>& dp)
//     {
//         int n = prices.size();
//         if(ind == n) return 0;
//         if(dp[ind][buy] != -1) return dp[ind][buy];
//         int profit = 0;
//         if(buy)
//           profit = max(-prices[ind] + func(ind+1, 0, fee, prices, dp), func(ind+1, 1, fee, prices, dp));
//         else
//           profit = max(prices[ind]  + func(ind+1, 1, fee, prices, dp) - fee, func(ind+1, 0, fee, prices, dp));
//         return dp[ind][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices, int fee) 
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n+1, vector<int>(2, -1));
//         return func(0, 1, fee, prices, dp);
//     }
// };