class Solution {
public:
    int maxProfit(vector<int>& prices) 
    {
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2, 0);
        int profit = 0;
        ahead[0] = ahead[1] = 0;
        for(int ind = n - 1 ; ind >= 0 ; ind--)
        {
            for(int buy = 0 ; buy <= 1 ; buy++)
            {
                if(buy)
                    profit = max(-prices[ind] + ahead[0], ahead[1]);
                else
                    profit = max(prices[ind] +ahead[1], ahead[0]);
                curr[buy] = profit;
            }
            ahead = curr;
        }
        return ahead[1];
        
    }
};

// Tabulation 
// class Solution {
// public:
//     int maxProfit(vector<int>& prices) 
//     {
        // int n = prices.size();
        // vector<vector<int>> dp(n+1, vector<int>(2, 0));
        // int profit = 0;
        // dp[n][0] = dp[n][1] = 0;
        // for(int ind = n - 1 ; ind >= 0 ; ind--)
        // {
        //     for(int buy = 0 ; buy <= 1 ; buy++)
        //     {
        //         if(buy)
        //             profit = max(-prices[ind] + dp[ind+1][0], dp[ind+1][1]);
        //         else
        //             profit = max(prices[ind] + dp[ind+1][1], dp[ind+1][0]);
        //         dp[ind][buy] = profit;
        //     }
        // }
        // return dp[0][1];
//     }
// };

// memo
// class Solution {
// public:
//     int func(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp)
//     {
//         if(ind == prices.size())
//            return 0;
//         int profit = 0;
//         if(dp[ind][buy] != -1) return dp[ind][buy];
//         if(buy)
//            profit = max(-prices[ind] + func(ind + 1 , 0, prices, dp), 0 + func(ind + 1, 1, prices, dp)); // (buy, notBuy)
//         else
//            profit = max(prices[ind] + func(ind + 1, 1, prices, dp), 0 + func(ind + 1, 0, prices, dp));
//         return dp[ind][buy] = profit;
//     }
//     int maxProfit(vector<int>& prices) 
//     {
//         int n = prices.size();
//         vector<vector<int>> dp(n, vector<int>(2, -1));
//         return func(0, 1, prices, dp);
//     }
// };