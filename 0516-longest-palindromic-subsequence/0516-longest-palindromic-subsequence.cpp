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
    int longestPalindromeSubseq(string s) 
    {
        string t  = s;
        reverse(t.begin(), t.end());
        return longestCommonSubsequence(s, t);
    }
};