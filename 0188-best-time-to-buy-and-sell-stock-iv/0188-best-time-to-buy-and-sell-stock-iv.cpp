class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n = prices.size();
        vector<vector<int>>after(2, vector<int>(k+1, 0));
        vector<vector<int>>curr(2, vector<int>(k+1, 0));
        for(int ind = n - 1 ; ind >= 0 ; ind--)
        {
            for(int buy = 0 ; buy <= 1; buy++)
            {
                for(int cap = 1 ; cap <= k ; cap++)
                {
                    int profit = 0;
                    if(buy)
                       profit = max(-prices[ind] + after[0][cap], after[1][cap]);
                    else
                       profit = max(prices[ind] + after[1][cap - 1], after[0][cap]);
                    curr[buy][cap] = profit;
                }
            }
            after = curr;
        }
        return after[1][k];
    }
        
};

// Tablulation
// class Solution {
// public:
//     int maxProfit(int k, vector<int>& prices) 
//     {
//         int n = prices.size();
//         vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
//         for(int ind = n - 1 ; ind >= 0 ; ind--)
//         {
//             for(int buy = 0 ; buy <= 1; buy++)
//             {
//                 for(int cap = 1 ; cap <= k ; cap++)
//                 {
//                     int profit = 0;
//                     if(buy)
//                        profit = max(-prices[ind] + dp[ind + 1][0][cap], dp[ind + 1][1][cap]);
//                     else
//                        profit = max(prices[ind] + dp[ind + 1][1][cap - 1], dp[ind + 1][0][cap]);
//                     dp[ind][buy][cap] = profit;
//                 }
//             }
//         }
//         return dp[0][1][k];
//     }
// };


// memo
// class Solution {
// public:
//     int func(int ind, int buy, int k, vector<int>& prices, vector<vector<vector<int>>>& dp)
//     {
//         if(ind == prices.size()) return 0;
//         if(k == 0) return 0;
//         int profit = 0;
//         if(dp[ind][buy][k] != -1) return dp[ind][buy][k];
        // if(buy)
        //    profit = max(-prices[ind] + func(ind + 1, 0, k, prices, dp), func(ind + 1, 1, k, prices, dp));
        // else
        //    profit = max(prices[ind] + func(ind + 1, 1, k - 1, prices, dp), func(ind + 1, 0, k, prices, dp));
        // return dp[ind][buy][k] = profit;
//     }
//     int maxProfit(int k, vector<int>& prices) 
//     {
        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
//         return func(0, 1, k, prices, dp);
//     }
// };