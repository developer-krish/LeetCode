class Solution {
public:
    int minCut(string s) 
    {
        int n = s.size();
        vector<int> dp(n+1, 0);
        vector<vector<bool>>isPal(n, vector<bool>(n, false));
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            for(int j = i ; j < n ; j++)
            {
                if(s[i] == s[j] && (j - i <= 2 || isPal[i+1][j-1]))
                   isPal[i][j] = true;
            }
        }
        for(int i = n - 1 ; i >= 0 ; i--)
        {
            int minCost = INT_MAX;
            for(int j = i ; j < n ; j++)
            {
                if(isPal[i][j])
                {
                    int cost = 1 + dp[j + 1];
                    minCost = min(minCost, cost);
                }
            }
            dp[i] = minCost;
        }
        return dp[0] - 1;
    }
};

// memo
// class Solution {
// public:
//     bool isPalindrome(int i, int j, string s)
//     {
//         while(i < j)
//         {
//             if(s[i] != s[j]) return false;
//             i++;
//             j--;
//         }
//         return true;
//     }
//     int func(int i, string s, vector<int>& dp)
//     {
//         if(i == s.size()) return 0;
//         int minCost = INT_MAX;
//         if(dp[i] != -1) return dp[i];
//         for(int j = i ; j < s.size() ; j++)
//         {
//             if(isPalindrome(i, j, s))
//             {
//                 int cost = 1 + func(j + 1, s, dp);
//                 minCost = min(minCost, cost);
//             }
//         }
//         return dp[i] = minCost;
//     }
//     int minCut(string s) 
//     {
//         int n = s.size();
//         vector<int> dp(n, -1);
//         return func(0, s, dp) - 1;
//     }
// };