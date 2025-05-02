class Solution {
public:
    int longestCommonSubsequence(string text1, string text2)
    {
        int l1 = text1.size();
        int l2 = text2.size();
        vector<vector<int>> dp(l1+1, vector<int>(l2+1, 0));
        for(int i = 0 ; i <= l1 ; i++)
           dp[i][0] = 0;
        for(int j = 0 ; j <= l2 ; j++)
           dp[0][j] = 0;
        
        for(int ind1 = 1 ; ind1 <= l1 ; ind1++)
        {
            for(int ind2 = 1 ; ind2 <= l2 ; ind2++)
            {
                if(text1[ind1 - 1] == text2[ind2 - 1])
                    dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
                else
                    dp[ind1][ind2] = max(dp[ind1 - 1][ind2], dp[ind1] [ind2 - 1]);
            }
        }
        return dp[l1][l2];
    }
};


// memo
// class Solution {
// public:
//     int func(int ind1, int ind2, string s1, string s2, vector<vector<int>>& dp)
//     {
//         if(ind1 < 0 || ind2 < 0)
//            return 0;
//         if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
//         if(s1[ind1] == s2[ind2])
//             return dp[ind1][ind2] = 1 + func(ind1 - 1, ind2 - 1, s1, s2, dp);
//          return dp[ind1][ind2] = max(func(ind1 - 1, ind2, s1, s2, dp), func(ind1, ind2 - 1, s1, s2, dp));
//     }
    
//     int longestCommonSubsequence(string text1, string text2) 
//     {
        // int l1 = text1.size();
        // int l2 = text2.size();
        // vector<vector<int>> dp(l1, vector<int>(l2, -1));
//         return func(l1 - 1, l2 - 1, text1, text2, dp);
//     }
// };